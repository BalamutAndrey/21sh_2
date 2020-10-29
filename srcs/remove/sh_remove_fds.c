/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_fds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:35:00 by eboris            #+#    #+#             */
/*   Updated: 2020/10/29 18:36:38 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_fds(t_main *main)
{
	t_fds	*temp;

	temp = main->opfds;
	if (main->opfds != NULL)
	{
		while (temp != NULL)
		{
			main->opfds = temp->next;
			free(temp);
			temp = main->opfds;
		}
		main->opfds = NULL;
	}
}