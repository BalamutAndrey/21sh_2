/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_token_envvar.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 17:42:42 by eboris            #+#    #+#             */
/*   Updated: 2020/11/01 20:11:25 by eboris           ###   ########.fr       */
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

void	sh_remove_envvar(t_envvar *envvar)
// {
// 	t_envvar	*temp;

// 	if (envvar != NULL)
// 	{
// 		temp = envvar;
// 		while (temp != NULL)
// 		{
// 			envvar = temp->next;
// 			if (temp->str != NULL)
// 				temp->str = NULL;
// //			{
// //				ft_strdel(&temp->str);
// //			}
// 			free(temp);
// 			temp = envvar;
// 		}
// 	}
// }

// void	sh_delete_envvars(t_envvar *envvar)
{
	t_envvar	*tmp;

	while (envvar)
	{
		tmp = envvar->next;
		envvar->str = NULL;
		envvar->next = NULL;
		free(envvar);
		envvar = tmp;
	}
}
