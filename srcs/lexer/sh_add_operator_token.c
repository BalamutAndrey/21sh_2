/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_add_operator_token.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 16:33:42 by geliz             #+#    #+#             */
/*   Updated: 2020/09/06 16:34:14 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_add_operator_token_part_two(t_token *token, char *str, int i)
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

void	sh_add_operator_token(t_list *data, char *str, int i)
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
		sh_add_operator_token_part_two(token, str, i);
	data->content = token;
}
