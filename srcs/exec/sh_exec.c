/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:29:08 by geliz             #+#    #+#             */
/*   Updated: 2020/10/17 15:56:28 by eboris           ###   ########.fr       */
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
t_exec	*temp_fill_exec(void)
{
	t_exec	*first;
	t_exec	*tmp;
	
	tmp = ft_memalloc(sizeof(t_exec));
	first = tmp;
	temp_fill_exec2(tmp, ft_strsplit("/bin/cat", ' '), false);
	temp_add_redirection(tmp, 0, DLESS, "../test_here/NEW_FILE");
/*	tmp->next = ft_memalloc(sizeof(t_exec));
	tmp = tmp->next;
	temp_fill_exec2(tmp, ft_strsplit("/usr/bin/grep o", ' '), true);
	tmp->next = ft_memalloc(sizeof(t_exec));
	tmp = tmp->next;
	temp_fill_exec2(tmp, ft_strsplit("/usr/bin/grep der", ' '), true);
	tmp->next = ft_memalloc(sizeof(t_exec));
	tmp = tmp->next;
	temp_fill_exec2(tmp, ft_strsplit("/usr/bin/wc -c", ' '), true);
	tmp->next = ft_memalloc(sizeof(t_exec));
	tmp = tmp->next;
	temp_fill_exec2(tmp, ft_strsplit("/usr/bin/sum", ' '), true);*/
//	temp_add_redirection(tmp, 1, GREAT, "../test_here/NEW_FILE");
//	temp_add_redirection(tmp, 1, GREAT, "../test_here/NEW_FILE");
	return (first);
}

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

void	sh_exec(t_main *main)
{
	t_exec	*exec;

	exec = main->exec_first;
	//For test only:
	// sh_exec_prog(exec, main);
	
	while (exec)
	{
		tcsetattr(main->fd, TCSANOW, &main->t_start);
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
