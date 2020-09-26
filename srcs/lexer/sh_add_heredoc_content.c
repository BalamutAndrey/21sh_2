/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_add_heredoc_content.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:39:51 by geliz             #+#    #+#             */
/*   Updated: 2020/09/26 17:43:20 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_add_heredoc_content(t_main *main)
{
	t_heredoc	*here;
	t_token		*tok;

	here = main->heredoc;
	tok = main->token;
	while (tok)
	{
		if (tok->type == DLESS)
		{
			ft_strdel(&tok->next->content);
			tok->next->content = ft_strdup(here->content);
			here = here->next;
		}
		tok = tok->next;
	}
}
