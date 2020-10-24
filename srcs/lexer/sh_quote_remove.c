/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_quote_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 15:00:27 by geliz             #+#    #+#             */
/*   Updated: 2020/10/24 17:32:18 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_dslashes_remove(int i, int end, t_token *token, t_main *main)
{
	while (i < end)
	{
		if (token->content[i] == '\\' && token->content[i + 1] == '\\')
		{
			sh_remove_char(i, token, main);
			end--;
		}
		i++;
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
		else if (token->content[i] == '$' && sh_is_protected(token->content, i) == 0
			&& ft_isalpha(token->content[i + 1]) == 1)
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
		else if (token->content[i] == '$' && sh_is_protected(token->content, i) == 0
			&& ft_isalpha(token->content[i + 1]) == 1)
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

void	sh_find_envvar(t_token *token, t_main *main)
{
	int		i;

	i = 0;
	while (token->content[i])
	{
		if (token->content[i] == '$' && sh_is_protected(token->content, i) == 0
			&& ft_isalpha(token->content[i + 1]) == 1)
			i = sh_add_envvar(1, i, main, token);
		i++;
	}
}

void	sh_quote_remove(t_main *main, t_token *token)
{
	while (token)
	{
		if (token->type == DLESS && token->next && token->next->type == WORD)
		{
			sh_find_envvar(token->next, main);
			token = token->next->next;
		}
		else if (token->type == WORD)
		{
			if (token->content[0] == '~' && (token->content[1] == '\0' || token->content[1] == '/'))
				sh_add_envvar(0, 0, main, token);
			else
				sh_find_and_remove_quotes(main, token);
			tmp_print_quote_remove(token);
		}
		if (token)
			token = token->next;
	}
}

// Переписать функции не под token а под строчку и использовать их в Heredoc для 
// правильного определения EOF снаружи Heredoc и подхвата в нужном месте envvar уже внутри Heredoc
// HEREDOC ctrl+d == here->delim (ctrl + d == 4 ASCII), проверить чтобы он не попал в токен
// удалять содержимое хирдока для правильного отображения в истории
// ПРОВЕРИТЬ что кавычки, слэш и прочее отрабатывают раньше хирдока
// $PATH && ~ в дереве и экзеке
// список запущенных процессов в main struct
// кавычки в хирдоках, УЖС!!!

// НАЙТИ И ЗАМЕНИТЬ $ в содержимом хирдока

// ЧЕКНУТЬ $PATH в хирдоках

// ECHO
// ENV_CUR
// в экзек поменять env на env_cur

// $ пробел - НЕ ПЕРЕМЕННАЯ СРЕДЫ!!