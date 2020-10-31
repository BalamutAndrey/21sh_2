/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_pipes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:08:03 by geliz             #+#    #+#             */
/*   Updated: 2020/10/31 17:03:16 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_std_in_out_pipe(t_exec *exec, int fd[2], int fd2[2], t_main *main)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		dup2(fd2[1], STDOUT_FILENO);
		close(fd2[0]);
		sh_standart_exec(exec, main);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
		main->cpid = pid;
		waitpid(pid, NULL, 0);
		main->cpid = -1;
	}
}

void	sh_stdin_pipe(t_exec *exec, int fd[2], t_main *main)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		sh_standart_exec(exec, main);
	}
	else
	{
		close(fd[0]);
		close(fd[1]);
		main->cpid = pid;
		waitpid(pid, NULL, 0);
		main->cpid = -1;
	}
}

void	sh_stdout_pipe(t_exec *exec, int fd[2], t_main *main)
{
	pid_t		pid;
	t_redirect	*here;

	here = NULL;
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		sh_standart_exec(exec, main);
	}
	else
	{
		main->cpid = pid;
		waitpid(pid, NULL, 0);
		main->cpid = -1;
	}
}

void	fill_pipe(int fd[2], int str_fd[2])
{
	fd[0] = str_fd[0];
	fd[1] = str_fd[1];
}

t_exec	*sh_exec_piped_commands(t_exec *exec, t_main *main)
{
	if (exec->pipe == false && exec->next && exec->next->pipe == true)
	{
		pipe(exec->pipefd);
		fill_pipe(exec->next->pipefd, exec->pipefd);
		sh_stdout_pipe(exec, exec->pipefd, main);
	}
	if (exec->pipe == true && exec->next && exec->next->pipe == true)
	{
		pipe(exec->next->pipefd);
		sh_std_in_out_pipe(exec, exec->pipefd, exec->next->pipefd, main);
	}
	if (exec->pipe == true && (!exec->next || exec->next->pipe == false))
		sh_stdin_pipe(exec, exec->pipefd, main);
	return (exec);
}
