/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_redirect_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:29:43 by eboris            #+#    #+#             */
/*   Updated: 2020/09/07 16:31:54 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** redirect_list    :               io_redirect
**                  | redirect_list io_redirect
*/

t_node	*redirectlist(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = redirectlist_ioredirect(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = redirectlist_redirectlist_ioredirect(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** redirect_list    :               io_redirect
*/

t_node	*redirectlist_ioredirect(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}

/*
** redirect_list    : redirect_list io_redirect
*/

t_node	*redirectlist_redirectlist_ioredirect(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}
