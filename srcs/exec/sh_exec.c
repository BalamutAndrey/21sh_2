/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:29:08 by geliz             #+#    #+#             */
/*   Updated: 2020/11/01 19:01:42 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	temp_fill_exec2(t_exec *tmp, char **argv, bool pipe)
{
	tmp->cmd = argv[0];
	tmp->argv = argv;
	// tmp->env = NULL;
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
	char	*err_built;
	int		redir_err;
	
	err_built = NULL;
	redir_err = 0;
	if (exec->pipe == true || (exec->next && exec->next->pipe == true))
	{
	//	if (exec->redir)
			//sh_redirects_hub(exec, main);
		// execv(exec->argv[0], exec->argv);
		if (exec->redir)
			redir_err = sh_redirects_hub(exec, main);
		if (redir_err >= 0 && (error = sh_exec_prog(exec, main, err_built)) != 0) //sh_redir_error(exec->redir->error) &&
		{
			sh_exec_print_error(error);
			exit(0);
		}
	}
	else
	{
		//SEGA!!!  при пустой строке. Поставил заглушку в sh_parser, сделать нормально!
		if (exec->argv != NULL && (sh_run_access(exec->argv[0]) == 5) && ((err_built = sh_exec_builtin(exec, main)) == NULL))
		{
			//ft_printf("\n%s is Ok\n", exec->argv[0]);
		}
		else
		{	

			cpid = fork();
			if (cpid == 0)
			{
	//			if (exec->redir)
	//				sh_redirects_hub(exec, main);
				// execv(exec->argv[0], exec->argv);
				if (exec->redir)// && (sh_redirects_hub(exec, main) == 0))
					redir_err = sh_redirects_hub(exec, main);
				if (exec->argv != NULL && redir_err >= 0 && ((error = sh_exec_prog(exec, main, err_built)) != 0))
					{
//						ft_printf("Error = %i\n", error);
						sh_exec_print_error(error);
//						sh_remove_struct(&main);
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

void	sh_print_exec(t_exec *exec)
{
	int		i;

	i = 0;
	while (exec)
	{
		while (exec->argv[i])
		{
			ft_printf("%s\n", exec->argv[i]);
			i++;
		}
		exec = exec->next;
	}
}

void	sh_exec(t_main *main)
{
	t_exec	*exec;

	exec = main->exec_first;
//	sh_print_exec(main->exec_first);
	//For test only:
	// sh_exec_prog(exec, main);
	while (exec)
	{
		
		tcsetattr(main->fd, TCSANOW, &main->t_start);
		sh_change_envvars_in_exec(main, exec); // CD имеет смысл запускать после этого :)
		if (exec->pipe == true || (exec->next && exec->next->pipe == true))
			sh_exec_piped_commands(exec, main);
		else
			sh_standart_exec(exec, main);
		exec = exec->next;
		tcsetattr(main->fd, TCSANOW, &main->t_curr);
	}
}

int16_t	sh_exec_prog(t_exec *exec, t_main *main, char *err_built)
{
	int16_t	error;

	error = -1;
//	ft_fprintf(2, "Add path\n");
	sh_path_add(main, exec);
//	ft_fprintf(2, "argv[0] = %s\n", exec->argv[0]);
//	ft_fprintf(2, "check access\n");
	if (sh_run_access(exec->argv[0]) == 6)
	{
		//test
//		ft_printf("\naccess 6\n");
		sh_exec_builtin(exec, main);
	}	
	else if (err_built != NULL)
	{
//		ft_printf("\nerror built\n");
		// Не работает редирект!
		ft_fprintf(STDERR_FILENO, "%s", err_built);
		ft_strdel(&err_built);
	}
	else if ((error = sh_run_access(exec->argv[0])) == 0)
	{
//		ft_printf("\nerror built NULL\n");
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
