/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_complete_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 16:37:32 by eboris            #+#    #+#             */
/*   Updated: 2020/11/07 17:16:02 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** complete_command : list separator
**                  | list
*/

t_node	*sh_complete_command(t_main *main, t_node *node)
{
	t_node	*temp;

	temp = node;
	if ((temp = sh_complete_command_list_separator(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_complete_command_list(main)) != NULL)
	{
		main->tree_curr = temp;
		return (temp);
	}
	return (NULL);
}

/*
** complete_command : list separator
*/

t_node	*sh_complete_command_list_separator(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	(void)temp;
	(void)main;
	return (NULL);
}

/*
** complete_command : list
*/

t_node	*sh_complete_command_list(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if (main->token_curr->type == SEPARATOR)
	{
		sh_lexer_tree_error(main);
		return (NULL);
	}
	if ((temp = sh_list(main)) != NULL)
		return (temp);
	return (NULL);
}
