/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_read.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:21:19 by eboris            #+#    #+#             */
/*   Updated: 2020/07/11 14:21:28 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_READ_H
# define SH_READ_H

/*
** sh_read_ks.c
*/
void	sh_read_ks(t_main *main);
void	sh_ks_and_dir(t_main *main);
void	sh_print_prompt(t_main *main);

/*
** sh_isprint.c
*/
bool	sh_isprint(int64_t c);

/*
** sh_cursor.c
*/
void	sh_reprint_ks(t_main *main);
void	sh_delete_ks(t_main *main);
void	sh_cursor_plus(t_main *main);
void	sh_cursor_minus(t_main *main);
void	sh_cursor_math(t_main *main);

/*
** sh_history.c
*/
void	sh_history_add(t_main *main);
void	sh_history_create(t_main *main);
void	sh_history_newlist(t_main *main);
void	sh_history_read(t_main *main, char k);
void	sh_history_delete(t_main *main);

#endif
