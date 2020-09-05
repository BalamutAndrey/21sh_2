/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_check_and_add_token.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 18:30:27 by geliz             #+#    #+#             */
/*   Updated: 2020/09/05 18:44:34 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	ft_add_io_number_token(t_list *data, char *str, int i)
{
	t_token		*token;

	token = ft_memalloc(sizeof(t_token));
	token->type = IO_NUMBER;
	token->content = ft_strsub(str, 0, i);
	data->content = token;
}

void	ft_add_newline_token(t_list *data)
{
	t_token		*token;

	token = ft_memalloc(sizeof(t_token));
	token->type = NEWLINE;
	token->content = ft_strdup("newline");
	data->content = token;
}

void	ft_add_operator_token_part_two(t_token *token, char *str, int i)
{
	if (!ft_strcmp(token->content, ">|"))
		token->type = CLOBBER;
	else if (!ft_strcmp(token->content, ";"))
		token->type = SEPARATOR;
	else if (!ft_strcmp(token->content, "!"))
		token->type = BANG;
	else if (!ft_strcmp(token->content, "{"))
		token->type = LBRACE;
	else if (!ft_strcmp(token->content, "}"))
		token->type = RBRACE;
	else if (!ft_strcmp(token->content, "(") || !ft_strcmp(token->content, ")")
		|| !ft_strcmp(token->content, "<") || !ft_strcmp(token->content, ">"))
		token->type = NONE;
}

void	ft_add_operator_token(t_list *data, char *str, int i)
{
	t_token		*token;

	token = ft_memalloc(sizeof(t_token));
	token->content = ft_strsub(str, 0, i);
	if (!ft_strcmp(token->content, "<<-"))
		token->type = DLESSDASH;
	else if (!ft_strcmp(token->content, "&&"))
		token->type = AND_IF;
	else if (!ft_strcmp(token->content, "||"))
		token->type = OR_IF;
	else if (!ft_strcmp(token->content, ";;"))
		token->type = DSEMI;
	else if (!ft_strcmp(token->content, "<<"))
		token->type = DLESS;
	else if (!ft_strcmp(token->content, ">>"))
		token->type = DGREAT;
	else if (!ft_strcmp(token->content, "<&"))
		token->type = LESSAND;
	else if (!ft_strcmp(token->content, ">&"))
		token->type = GREATAND;
	else if (!ft_strcmp(token->content, "<>"))
		token->type = LESSGREAT;
	else
		ft_add_operator_token_part_two(token, str, i);
	data->content = token;
}

void	ft_add_word_token(t_list *data, char *str, int i)
{
	t_token		*token;

	token = ft_memalloc(sizeof(t_token));
	token->type = WORD;
	token->content = ft_strsub(str, 0, i);
	data->content = token;
}

void	ft_check_type_and_add_token(t_list *data, char *str,
			int i, int io_nbr_flag)
{
	if (io_nbr_flag != 0)
		ft_add_io_number_token(data, str, i);
	else if (*str == '\n')
		ft_add_newline_token(data);
	else if (ft_is_operator(str) > 0)
		ft_add_operator_token(data, str, i);
	else
		ft_add_word_token(data, str, i);
}