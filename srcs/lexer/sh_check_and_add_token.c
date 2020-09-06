/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_check_and_add_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:30:27 by geliz             #+#    #+#             */
/*   Updated: 2020/09/06 17:21:18 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_add_io_number_token(t_token *token, char *str, int i)
{
	token->type = IO_NUMBER;
	token->content = ft_strsub(str, 0, i);
}

void	sh_add_newline_token(t_token *token)
{
	token->type = NEWLINE;
	token->content = ft_strdup("newline");
}

void	sh_add_word_token(t_token *token, char *str, int i)
{
	token->type = WORD;
	token->content = ft_strsub(str, 0, i);
}

void	sh_check_type_and_add_token(t_token *token, char *str,
			int i, int io_nbr_flag)
{
	if (io_nbr_flag != 0)
		sh_add_io_number_token(token, str, i);
	else if (*str == '\n')
		sh_add_newline_token(token);
	else if (sh_is_operator(str) > 0)
		sh_add_operator_token(token, str, i);
	else
		sh_add_word_token(token, str, i);
}
