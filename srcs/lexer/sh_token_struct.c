/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_token_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 17:05:36 by geliz             #+#    #+#             */
/*   Updated: 2020/09/06 17:19:32 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

t_token		*sh_new_token(int type, char *content, t_main *main)
{
	t_token	*token;

	token = ft_memalloc(sizeof(t_token));
	token->type = type;
	if (content)
		token->content = ft_strdup(content);
	else
		token->content = NULL;
	token->next = NULL;
//	if (!token || (content && !token->content))
//		ERROR
	(void)main;
	return (token);
}

void	sh_remove_token_list(t_token *token)
{
	t_token		*tmp;
	
	while (token)
	{
		ft_strdel(&token->content);
		token->type = 0;
		tmp = token->next;
		token->next = NULL;
		free(token);
		token = tmp;
	}
}