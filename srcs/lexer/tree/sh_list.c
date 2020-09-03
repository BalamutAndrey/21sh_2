/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:15:17 by eboris            #+#    #+#             */
/*   Updated: 2020/09/03 17:19:35 by eboris           ###   ########.fr       */
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
	if ((temp = sh_list_separatorop_andor) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_list_andor) != NULL)
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

	temp = NULL;
	return (NULL);
}

/*
** list             |                   and_or
*/

t_node	*sh_list_andor(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}
