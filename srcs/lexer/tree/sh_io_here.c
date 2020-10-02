/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_io_here.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:22:01 by eboris            #+#    #+#             */
/*   Updated: 2020/10/02 16:36:42 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** io_here          : DLESS     here_end
**                  | DLESSDASH here_end
*/

t_node	*sh_iohere(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_iohere_dless_hereend(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_iohere_dlessdash_hereend(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** io_here          : DLESS     here_end
*/

t_node	*sh_iohere_dless_hereend(t_main *main)
{
	t_node	*temp;
	t_node	*first;
	t_token	*token;

	temp = NULL;
	token = main->token_curr;
	if ((main->token_curr != NULL) && (main->token_curr->type == DLESS))
	{
		first = sh_lexer_create_node(main, main->token_curr, DLESS);
		main->token_curr = main->token_curr->next;
		if ((temp = sh_hereend(main)) != NULL)
		{
			sh_lexer_add_node(first, NULL, temp);
			main->token_curr = main->token_curr->next;
			return (first);
		}
		else
		{
			// Ошибка лексемы?
			sh_lexer_del_node(&first);
			main->token_curr = token;
			return (NULL);
		}
	}
	return (NULL);
}

/*
** io_here          : DLESSDASH here_end
*/

t_node	*sh_iohere_dlessdash_hereend(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}
