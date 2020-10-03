/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:36:00 by geliz             #+#    #+#             */
/*   Updated: 2020/10/03 15:29:40 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_EXEC_H
# define SH_EXEC_H

/*
** sh_exec.c
*/
void	sh_exec(t_main *main);
void	sh_set_default_io_value(t_main *main);
void	sh_redirect_from_heredoc(t_redirect *new, t_main *main);
void	sh_add_opened_fd(t_main *main, int nbr);

void	temp_exec(void);
t_redirect	*temp_create_redir_list(void);

/*
** sh_redirects.c
*/
void	sh_redirect_from_ionumber(t_redirect *new, t_main *main);
void	sh_redirect_from_file(t_redirect *new, t_main *main);
void	sh_redirect_to_file_append(t_redirect *new, t_main *main);
void	sh_redirect_to_file(t_redirect *new, t_main *main);
void	sh_redirect_to_ionumber(t_redirect *new, t_main *main);


#endif
