/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cmd_suffix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:21:03 by eboris            #+#    #+#             */
/*   Updated: 2020/09/25 15:40:13 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** cmd_suffix       :            io_redirect
**                  | cmd_suffix io_redirect
**                  |            WORD
**                  | cmd_suffix WORD
*/

t_node	*sh_cmdsuffix(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_cmdsuffix_ioredirect(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_cmdsuffix_cmdsuffix_ioredirect(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_cmdsuffix_word(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_cmdsuffix_cmdsuffix_word(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** cmd_suffix       :            io_redirect
*/

t_node	*sh_cmdsuffix_ioredirect(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}

/*
** cmd_suffix       : cmd_suffix io_redirect
*/

t_node	*sh_cmdsuffix_cmdsuffix_ioredirect(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}

/*
** cmd_suffix       :            WORD
*/

t_node	*sh_cmdsuffix_word(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((main->token_curr == NULL) || (main->token_curr->type != WORD))
		return (NULL);
	if ((main->token_curr->next != NULL) &&
		(main->token_curr->next->type != SEPARATOR))
	{
		return (NULL);
	}
	temp = sh_lexer_create_node(main, main->token_curr, CMDSUFFIX);
	main->token_curr = main->token_curr->next;
	return (temp);
}

/*
** cmd_suffix       : cmd_suffix WORD
*/

t_node	*sh_cmdsuffix_cmdsuffix_word(t_main *main)
{
	t_token	*token;
	t_token	*first_token;
	t_node	*first;
	t_node	*temp;
	t_node	*curr;

	if (main->token_curr == NULL)
		return (NULL);
	if ((main->token_curr->next == NULL) || (main->token_curr->next->type == SEPARATOR))
		return (NULL);
	first_token = main->token_curr;
	token = main->token_curr->next;
	main->token_curr->next = NULL;
	first = sh_cmdsuffix(main);
	if (first == NULL)
		return (NULL);
	main->token_curr = first_token;
	main->token_curr->next = token;
	main->token_curr = token;
	curr = first;
	while ((main->token_curr != NULL) && (main->token_curr->type != SEPARATOR))
	{
		temp = NULL;
		first_token = main->token_curr;
		token = main->token_curr->next;
		main->token_curr->next = NULL;
		if ((temp = sh_cmdsuffix(main)) != NULL)
		{
			sh_lexer_add_node(curr, NULL, temp);
			curr = temp;
		}
		main->token_curr = first_token;
		main->token_curr->next = token;
		main->token_curr = token;
	}
	return (first);
}
