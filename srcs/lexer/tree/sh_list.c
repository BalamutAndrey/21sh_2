/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:15:17 by eboris            #+#    #+#             */
/*   Updated: 2020/09/25 16:53:19 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** list             : list separator_op and_or
**                  |                   and_or
*/

t_node	*sh_list(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_list_separatorop_andor(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_list_andor(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** list             : list separator_op and_or
*/

t_node	*sh_list_separatorop_andor(t_main *main)
{
	t_node	*temp;
	t_node	*sep;
	t_node	*tree_curr;
	t_token	*find;
	t_token	*first;

	find = main->token_curr;
	first = main->token_curr;
	while (find != NULL)
	{
		if ((find->next != NULL) && (find->next->type == SEPARATOR))
		{
			first = find->next;
			find->next = NULL;
			tree_curr = main->tree_curr;
			temp = sh_list_andor(main);
			main->token_curr = first->next;
			sep = sh_lexer_create_node(main, NULL, SEPARATOR);
			sh_lexer_add_node(tree_curr, sep, temp);
			main->tree_curr = sep;
			return (sh_list(main));
		}
		find = find->next;
	}
	temp = NULL;
	return (NULL);
}

/*
** list             :                   and_or
*/

t_node	*sh_list_andor(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_andor(main)) != NULL)
	{
		if ((main->token_curr != NULL) && (main->token_curr->next != NULL))
		{
			//free temp
			return (NULL);
		}
		return (temp);
	}
	return (NULL);
}
