/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_io_here.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 17:22:01 by eboris            #+#    #+#             */
/*   Updated: 2020/09/07 17:24:07 by eboris           ###   ########.fr       */
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

	temp = NULL;
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
