/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_exec.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:23:28 by eboris            #+#    #+#             */
/*   Updated: 2020/10/04 17:28:08 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LEXER_EXEC_H
# define SH_LEXER_EXEC_H

/*
** sh_exec_struct_create.c
*/
void	sh_exec_struct_create(t_main *main);
void	sh_exec_struct_go(t_main *main, bool pipe);
t_exec	*sh_exec_struct_new(t_main *main);
void	sh_exec_struct_write(t_main *main, bool pipe);

/*
** sh_exec_struct_argv.c
*/
u_int64_t	sh_exec_struct_write_argv_num(t_main *main);
void		sh_exec_struct_write_argv(t_main *main);

/*
** sh_exec_struct_redirect.c
*/
void		sh_exec_struct_redirect(t_main *main);
t_redirect	*sh_exec_struct_redirect_new(void);
t_node		*sh_exec_struct_redirect_write(t_node *node, t_redirect *redirect);

#endif