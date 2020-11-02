/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_token.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:42:42 by eboris            #+#    #+#             */
/*   Updated: 2020/11/02 16:49:49 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_token(t_main *main)
{
	t_token	*temp;

	if (main->token != NULL)
	{
		temp = main->token;
		while (temp != NULL)
		{
			main->token = temp->next;
			if (temp->content != NULL)
			{
				ft_strdel(&temp->content);
			}
			if (temp->envvar != NULL)
			{
			 	sh_remove_envvar(temp->envvar);
				temp->envvar = NULL;
			}
			free(temp);
			temp = main->token;
		}
		main->token = NULL;
	}
	main->token_curr = NULL;
}
