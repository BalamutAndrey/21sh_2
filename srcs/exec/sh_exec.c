/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:29:08 by geliz             #+#    #+#             */
/*   Updated: 2020/10/18 18:06:36 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	temp_fill_exec2(t_exec *tmp, char **argv, bool pipe)
{
	tmp->cmd = argv[0];
	tmp->argv = argv;
	tmp->env = NULL;
	tmp->redir = NULL;
	tmp->pipe = pipe;
	tmp->next = NULL;
}

void	temp_add_redirection(t_exec *exec, int io, t_type type, char *filename)
{
	t_redirect	*red;

	if (!exec->redir)
	{
		exec->redir = ft_memalloc(sizeof(t_redirect));
		red = exec->redir;
	}
	else
	{
		red = exec->redir;
		while (red->next)
			red = red->next;
		red->next = ft_memalloc(sizeof(t_redirect));
		red = red->next;
	}
	red->io_num = io;
	red->type = type;
	red->filename = filename;
}


/*
чистить фдшники после каждой команды, проверить с редиректом в начале и середине!!!
на данный момент при редиректе в начале не работает
*/

void	sh_standart_exec(t_exec *exec, t_main *main)
{
	pid_t	cpid;
	int16_t	error;
	
	if (exec->pipe == true || (exec->next && exec->next->pipe == true))
	{
		if (exec->redir)
			sh_redirects_hub(exec, main);
		// execv(exec->argv[0], exec->argv);
		if ((error = sh_exec_prog(exec, main)) != 0)
		{
			sh_exec_print_error(error);
			exit(0);
		}
	}
	else
	{
		cpid = fork();
		if (cpid == 0)
		{
			if (exec->redir)
				sh_redirects_hub(exec, main);
			// execv(exec->argv[0], exec->argv);
			if ((error = sh_exec_prog(exec, main)) != 0)
			{
				//ft_printf("Error = %i\n", error);
				sh_exec_print_error(error);
				exit(0);
			}
		}
		else
		{
			main->cpid = cpid;
			waitpid(cpid, NULL, 0);
			main->cpid = -1;
		}
	}
}

int		sh_find_heredoc_in_exec_struct(t_exec *exec)
{
	t_redirect	*new;

	while(new)
	{
		if (new->type == DLESS)
			return (1);
		new = new->next;
	}
	return (0);
}

char	*sh_find_envvar_in_env(char **env, t_envvar *envvar)
{
	int		i;
	char	*pos;
	int		len;
	char	*var;
	char	*ret;

	i = 0;
	pos = NULL;
	len = envvar->end - envvar->start;
	var = ft_strsub(envvar->str, envvar->start + 1, len - 1);
	var = ft_strjoin_arg("%f %s", var, "=");
	while (env[i])
	{
		if ((pos = ft_strnstr(env[i], var, ft_strlen(var))) != NULL)
		{
			len = ft_strlen(var);
			ft_strdel(&var);
			return (&pos[len]);
		}
		i++;
	}
	return (NULL);
}

void	sh_change_envvars_in_exec(t_main *main, t_exec *exec, t_envvar *envvar)
{
	char	*ret;
	int		i;
	char	*env_cont;
	char	*before_var;
	char	*after_var;
	
	before_var = NULL;
	after_var = NULL;
	env_cont = sh_find_envvar_in_env(main->envp_curr, envvar);
	if (envvar->start > 0)
		before_var = ft_strsub(envvar->str, 0, envvar->start);
	if (envvar->end < ft_strlen(envvar->str))
		after_var = ft_strsub(envvar->str, envvar->end, ft_strlen(envvar->str) - envvar->end);
	ret = ft_strjoin_arg("%f %s %f", before_var, env_cont, after_var);
	ft_printf("ret = %s\n", ret);

}

void	sh_change_envvars_in_exec_and_redirs(t_main *main, t_exec *exec)
{
	while (exec->envvar)
	{
		sh_change_envvars_in_exec(main, exec, exec->envvar);
		exec->envvar = exec->envvar->next;
	}
}

void	sh_exec(t_main *main)
{
	t_exec	*exec;

	exec = main->exec_first;
	//For test only:
	// sh_exec_prog(exec, main);
	while (exec)
	{
		tcsetattr(main->fd, TCSANOW, &main->t_start);
		sh_change_envvars_in_exec_and_redirs(main, exec); // CD имеет смысл запускать после этого :)
		if (exec->pipe == true || (exec->next && exec->next->pipe == true))
			sh_exec_piped_commands(exec, main);
		else
			sh_standart_exec(exec, main);
		exec = exec->next;
		tcsetattr(main->fd, TCSANOW, &main->t_curr);
	}
}

int16_t	sh_exec_prog(t_exec *exec, t_main *main)
{
	int16_t	error;

	error = -1;
	// ft_printf("Add path\n");
	sh_path_add(main, exec);
	ft_fprintf(2, "argv[0] = %s\n", exec->argv[0]);
	//ft_printf("check access\n");
	if (((error = sh_run_access(exec->argv[0])) == 0) &&
		(sh_is_builtin(exec->argv[0]) == false))
	{
		//ft_printf("aceess Ok\n");
		execve(exec->argv[0], exec->argv, main->envp_curr);
	}
	//ft_printf("error = %i\n", error);
	return (error);
}

void	sh_exec_print_error(int16_t error)
{
	if (error == 1)
	{
		ft_fprintf(STDERR_FILENO, "\n21sh: Access 0 error. Command not found.\n");
	}
	else if (error == 2)
	{
		ft_fprintf(STDERR_FILENO, "\n21sh: Access 1 error.\n");
	}
	else if (error == 3)
	{
		ft_fprintf(STDERR_FILENO, "\n21sh: Not a file of link.\n");
	}
	else if (error == 4)
	{
		ft_fprintf(STDERR_FILENO, "\n21sh: Unknown error.\n");
	}
}
