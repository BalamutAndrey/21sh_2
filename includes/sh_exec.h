/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:36:00 by geliz             #+#    #+#             */
/*   Updated: 2020/10/03 18:21:02 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXEC_H
# define SH_EXEC_H

/*
** sh_exec.c
*/
void	sh_exec(t_main *main);
void	sh_standart_exec(t_exec *exec, t_main *main);

/*
** sh_redirects_hub.c
*/
void	sh_redirects_hub(t_exec *exec, t_main *main);
void	sh_set_default_io_value(t_main *main);
void	sh_redirect_from_heredoc(t_redirect *new, t_main *main);
void	sh_add_opened_fd(t_main *main, int nbr);
/*
** sh_redirects.c
*/
void	sh_redirect_from_ionumber(t_redirect *new, t_main *main);
void	sh_redirect_from_file(t_redirect *new, t_main *main);
void	sh_redirect_to_file_append(t_redirect *new, t_main *main);
void	sh_redirect_to_file(t_redirect *new, t_main *main);
void	sh_redirect_to_ionumber(t_redirect *new, t_main *main);
/*
** sh_exec_pipes.c
*/
t_exec	*sh_exec_piped_commands(t_exec *exec, t_main *main);
void	sh_stdout_pipe(t_exec *exec, int fd[2], t_main *main);
void	sh_stdin_pipe(t_exec *exec, int fd[2], t_main *main);
void	sh_std_in_out_pipe(t_exec *exec, int fd[2], int fd2[2], t_main *main);

#endif