/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 16:20:13 by eboris            #+#    #+#             */
/*   Updated: 2020/10/17 13:51:03 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_BUILTIN_H
# define SH_BUILTIN_H

/*
** sh_cd.c
*/
void	sh_cd(t_exec *exec, t_main *main);
void	sh_cd_error(t_main *main);
void	sh_cd_check_param(t_exec *exec, t_main *main);
void	sh_cd_change_dir(t_exec *exec, t_main *main, bool param);
void	sh_chdir_finish(t_exec *exec, t_main *main, bool param, int p);

/*
** sh_cd_path.c
*/
void	sh_home_dir(t_exec *exec, t_main *main, int p);
void	sh_prev_dir(t_exec *exec, t_main *main, int p);
void	sh_no_root_dir(t_exec *exec, t_main *main, int p);

/*
** sh_env_replace.c
*/
int		sh_env_replace(t_main *new, char *whats, char *to);
void	sh_env_replace_new(t_main *new, char *whats, char *to);
void	sh_env_remove(t_main *new);
int		sh_env_len(t_main *new);

/*
** sh_pwd.c
*/
void	sh_pwd(t_exec *exec, t_main *main);
void	sh_pwd_error(t_main *main);
void	sh_pwd_check_param(t_exec *exec, t_main *main);
void	sh_pwd_print_dir(t_main *main, bool param);

/*
** sh_exit.c
*/
void	sh_exit(t_main *main, uint64_t code);

#endif
