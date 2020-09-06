/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_check_and_add_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:30:27 by geliz             #+#    #+#             */
/*   Updated: 2020/09/06 16:34:31 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_add_io_number_token(t_list *data, char *str, int i)
{
	t_token		*token;

	token = ft_memalloc(sizeof(t_token));
	token->type = IO_NUMBER;
	token->content = ft_strsub(str, 0, i);
	data->content = token;
}

void	sh_add_newline_token(t_list *data)
{
	t_token		*token;

	token = ft_memalloc(sizeof(t_token));
	token->type = NEWLINE;
	token->content = ft_strdup("newline");
	data->content = token;
}

void	sh_add_word_token(t_list *data, char *str, int i)
{
	t_token		*token;

	token = ft_memalloc(sizeof(t_token));
	token->type = WORD;
	token->content = ft_strsub(str, 0, i);
	data->content = token;
}

void	sh_check_type_and_add_token(t_list *data, char *str,
			int i, int io_nbr_flag)
{
	if (io_nbr_flag != 0)
		sh_add_io_number_token(data, str, i);
	else if (*str == '\n')
		sh_add_newline_token(data);
	else if (sh_is_operator(str) > 0)
		sh_add_operator_token(data, str, i);
	else
		sh_add_word_token(data, str, i);
}