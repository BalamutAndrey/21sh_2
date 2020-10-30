/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:35:00 by eboris            #+#    #+#             */
/*   Updated: 2020/10/30 14:45:04 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_fds(t_main *main)
{
	t_fds	*temp;

	if (main->opfds != NULL)
	{
		temp = main->opfds;
		while (temp != NULL)
		{
			main->opfds = temp->next;
			free(temp);
			temp = main->opfds;
		}
		main->opfds = NULL;
	}
}