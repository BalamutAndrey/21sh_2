/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_separator_op.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:01:13 by eboris            #+#    #+#             */
/*   Updated: 2020/09/07 18:06:49 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** separator_op     : '&'
**                  | ';'
*/

t_node	*sh_separatorop(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_separatorop_ampersand(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_separatorop_semicolon(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** separator_op     : '&'
*/

t_node	*sh_separatorop_ampersand(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}

/*
** separator_op     : ';'
*/

t_node	*sh_separatorop_semicolon(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}
