/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:51:52 by eboris            #+#    #+#             */
/*   Updated: 2020/10/28 18:10:36 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_struct(t_main **main)
{
	t_main	*temp;

	temp = *main;
	if (temp->term_name != NULL)
		ft_strdel(&temp->term_name);
    sh_remove_envp_curr(main);
	sh_remove_path(main);
	sh_remove_hist(main);
	if (temp->user != NULL)
		ft_strdel(&temp->user);
	if (temp->home != NULL)
		ft_strdel(&temp->home);
	if (temp->dir != NULL)
		ft_strdel(&temp->dir);
	if (temp->ks != NULL)
		ft_strdel(&temp->ks);
	if (temp->ks_temp != NULL)
		ft_strdel(&temp->ks_temp);


	if (temp->prompt != NULL)
		ft_strdel(&temp->prompt);
	sh_history_delete(temp);
	free(*main);
	exit(0);
}