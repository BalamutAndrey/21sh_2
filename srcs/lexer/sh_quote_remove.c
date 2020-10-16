/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_quote_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:00:27 by geliz             #+#    #+#             */
/*   Updated: 2020/10/16 19:32:50 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_dslashes_remove(int i, int end, t_token *token, t_main *main)
{
	while (i < end)
	{
		if (token->content[i] == '\\' && token->content[i + 1] == '\\')
			sh_remove_char(i, token, main);
		i++;
		end--;
	}
	return (end);
}

int		sh_dquotes_remove(t_token *token, int i, t_main *main)
{
	int		tmp;

	tmp = i;
	sh_remove_char(i, token, main);
	while (token->content[i] != '\"' || sh_is_protected(token->content, i) == 1)
	{
		if (token->content[i] == '\\' && 
			(token->content[i + 1] == '\"' || token->content[i + 1] == '$') && 
			sh_is_protected(token->content, i) == 0)
			{
				sh_remove_char(i, token, main);
				i++;
			}
		else if (token->content[i] == '$' && sh_is_protected(token->content, i) == 0)
			i = sh_add_envvar(1, i, main, token);
		else
			i++;
	}
	sh_remove_char(i, token, main);
	i = sh_dslashes_remove(tmp, i, token, main);
	return (i + 1);
}

int		sh_squotes_remove(t_token *token, int i, t_main *main)
{
	sh_remove_char(i, token, main);
	while (token->content[i] != '\'')
		i++;
	sh_remove_char(i, token, main);
	return (i);
}

void	sh_find_and_remove_quotes(t_main *main, t_token *token)
{
	int		i;

	i = 0;
	while (token->content[i])
	{
		if (token->content[i] == '\"' && sh_is_protected(token->content, i) == 0)
			i = sh_dquotes_remove(token, i, main);
		else if (token->content[i] == '\'' && sh_is_protected(token->content, i) == 0)
			i = sh_squotes_remove(token, i, main);
		else if (token->content[i] == '$' && sh_is_protected(token->content, i) == 0)
			i = sh_add_envvar(1, i, main, token);
		else if (token->content[i] == '\\')
		{
			sh_remove_char(i, token, main);
			i++;
		}
		else
			i++;
	}
}

void	tmp_print_quote_remove(t_token *token)
{
	t_envvar	*en;
	
	printf("*** QUOTE REMOVAL SERVICE ***\n");
	printf("%s\n", token->content);
	en = token->envvar;
	while (en)
	{
		printf("type = %i, start = %i, end = %i\n", en->type, en->start, en->end);
		en = en->next;
	}
}

void	sh_quote_remove(t_main *main, t_token *token)
{
	while (token)
	{
		if (token->type == WORD)
		{
			if (ft_strcmp(token->content, "~") == 0)
				sh_add_envvar(0, 0, main, token);
			else
				sh_find_and_remove_quotes(main, token);
			tmp_print_quote_remove(token);
		}
		token = token->next;
	}
}

// Переписать функции не под token а под строчку и использовать их в Heredoc для 
// правильного определения EOF снаружи Heredoc и подхвата в нужном месте envvar уже внутри Heredoc
// HEREDOC ctrl+d == here->delim (ctrl + d == 4 ASCII), проверить чтобы он не попал в токен