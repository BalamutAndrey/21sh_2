/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_exec.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 17:23:28 by eboris            #+#    #+#             */
/*   Updated: 2020/11/04 17:13:59 by geliz            ###   ########.fr       */
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
void		sh_exec_struct_write_argv(t_main *main, t_exec *new);
void		sh_exec_struct_write_argv_add(t_node *temp, t_exec *new, 
			char **argv, u_int64_t *i);

/*
** sh_exec_struct_redirect.c
*/
void		sh_exec_struct_redirect(t_main *main);
t_redirect	*sh_exec_struct_redirect_new(t_main *main);
t_node		*sh_exec_struct_redirect_write(t_node *node, t_redirect *redirect);

/*
** sh_exec_struct_envvar.c
*/
void		sh_exec_struct_write_envvar(t_node *node, t_exec *exec, char *argv);
void		sh_exec_struct_write_redir_envvar(t_node *node, t_redirect *exec, char *argv);
t_envvar	*sh_create_new_envvar(void);
t_envvar	*sh_copy_envvar(t_envvar *from);

#endif