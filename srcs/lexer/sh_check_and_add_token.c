/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_check_and_add_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:30:27 by geliz             #+#    #+#             */
/*   Updated: 2020/09/26 17:26:27 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_check_type_and_add_token(t_token *token, char *str,
			int i, int io_nbr_flag)
{
	if (io_nbr_flag != 0)
	{
		token->type = IO_NUMBER;
		token->content = ft_strsub(str, 0, i);
	}
/*	else if (*str == '\n')
	{
			token->type = NEWLINE;
		token->content = ft_strdup("newline");
	}*/
	else if (sh_is_operator(str) > 0)
		sh_add_operator_token(token, str, i);
	else
	{
		token->type = WORD;
		token->content = ft_strsub(str, 0, i);
	}
}
