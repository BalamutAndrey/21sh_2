/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_hist.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:59:21 by eboris            #+#    #+#             */
/*   Updated: 2020/10/29 17:54:30 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void    sh_remove_hist(t_main *main)
{
	t_hist	*temp;
	
	temp = main->hist;
	if (main->hist != NULL)
	{
		while (temp != NULL)
		{
			main->hist = temp->next;
			if (temp->com != NULL)
				ft_strdel(&temp->com);
			free(temp);
			temp = main->hist;
		}
		main->hist = NULL;
		main->hist_curr = NULL;
		main->hist_end = NULL;
	}
}
