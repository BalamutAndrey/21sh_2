/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:57:04 by eboris            #+#    #+#             */
/*   Updated: 2020/10/28 18:09:16 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** sh_remove_struct.c 
*/
void	sh_remove_struct(t_main **main);

/*
** sh_remove_struct.c 
*/
void   sh_remove_envp_curr(t_main *main);

/*
** sh_remove_path.c
*/
void	sh_remove_path(t_main *main);

/*
** sh_remove_hist.c
*/
void    sh_remove_hist(t_main *main);
