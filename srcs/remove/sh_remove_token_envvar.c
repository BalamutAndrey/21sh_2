/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_token_envvar.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:42:42 by eboris            #+#    #+#             */
/*   Updated: 2020/10/29 17:52:09 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_token(t_main *main)
{
	t_token	*temp;

	temp = main->token;
	if (main->token != NULL)
	{
		while (temp != NULL)
		{
			main->token = temp->next;
			if (temp->content != NULL)
			{
				ft_strdel(&temp->content);
			}
			sh_remove_envvar(temp->envvar);
			free(temp);
			temp = main->token;
		}
		main->token = NULL;
	}
	main->token_curr = NULL;
}

void	sh_remove_envvar(t_envvar *envvar)
{
	t_envvar	*temp;

	temp = envvar;
	if (envvar != NULL)
	{
		while (temp != NULL)
		{
			envvar = temp->next;
			if (temp->str != NULL)
			{
				ft_strdel(&temp->str);
			}
			free(temp);
			temp = envvar;
		}
	}
}
