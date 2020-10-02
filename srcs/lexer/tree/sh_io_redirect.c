/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_io_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:34:08 by eboris            #+#    #+#             */
/*   Updated: 2020/10/02 16:44:46 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** io_redirect      :           io_file
**                  | IO_NUMBER io_file
**                  |           io_here
**                  | IO_NUMBER io_here
*/

t_node	*sh_ioredirect(t_main *main)
{
	t_node	*first;
	t_node	*curr;
	t_node	*temp;

	temp = NULL;
	if (sh_is_a_redirect(main->token_curr) == false)
		return (NULL);
	if (((first = sh_ioredirect_iofile(main)) != NULL) ||
	((first = sh_ioredirect_ionumber_iofile(main)) != NULL) ||
	((first = sh_ioredirect_iohere(main)) != NULL) ||
	((first = sh_ioredirect_ionumber_iohere(main)) != NULL))
	{
		curr = first;
		while (curr->right != NULL)
			curr = curr->right;
	}
	else
	{
		// Ошибка синтаксиса!
		return (NULL);
	}
	while (sh_is_a_redirect(main->token_curr) == true)
	{
		if (((temp = sh_ioredirect_iofile(main)) != NULL) ||
		((temp = sh_ioredirect_ionumber_iofile(main)) != NULL) ||
		((temp = sh_ioredirect_iohere(main)) != NULL) ||
		((temp = sh_ioredirect_ionumber_iohere(main)) != NULL))
		{
			sh_lexer_add_node(curr, NULL, temp);
			curr = temp;
			while (curr->right != NULL)
				curr = curr->right;
		}
		else
		{
			// Ошибка синтаксиса!
			return (NULL);
		}
	}
	return (first);
}

/*
** io_redirect      :           io_file
*/

t_node	*sh_ioredirect_iofile(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_iofile(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** io_redirect      : IO_NUMBER io_file
*/

t_node	*sh_ioredirect_ionumber_iofile(t_main *main)
{
	t_node	*first;
	t_node	*temp;
	t_token	*first_token;

	temp = NULL;
	if ((main->token_curr == NULL) || (main->token_curr->type != IO_NUMBER))
		return (NULL);
	first_token = main->token_curr;
	first = sh_lexer_create_node(main, main->token_curr, IO_NUMBER);
	main->token_curr = main->token_curr->next;
	if ((temp = sh_ioredirect_iofile(main)) != NULL)
	{
		sh_lexer_add_node(first, NULL, temp);
		return (first);
	}
	else
	{
		sh_lexer_del_node(&first);
		main->token_curr = first_token;
	}
	return (NULL);
}

/*
** io_redirect      :           io_here
*/

t_node	*sh_ioredirect_iohere(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_iohere(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** io_redirect      : IO_NUMBER io_here
*/

t_node	*sh_ioredirect_ionumber_iohere(t_main *main)
{
	t_node	*first;
	t_node	*temp;
	t_token	*first_token;

	temp = NULL;
	if ((main->token_curr == NULL) || (main->token_curr->type != IO_NUMBER))
		return (NULL);
	first_token = main->token_curr;
	first = sh_lexer_create_node(main, main->token_curr, IO_NUMBER);
	main->token_curr = main->token_curr->next;
	if ((temp = sh_ioredirect_iohere(main)) != NULL)
	{
		sh_lexer_add_node(first, NULL, temp);
		return (first);
	}
	else
	{
		sh_lexer_del_node(&first);
		main->token_curr = first_token;
	}
	return (NULL);
}
