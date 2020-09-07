/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_io_redirect.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:34:08 by eboris            #+#    #+#             */
/*   Updated: 2020/09/07 16:37:14 by eboris           ###   ########.fr       */
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
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_ioredirect_iofile(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_ioredirect_ionumber_iofile(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_ioredirect_iohere(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_ioredirect_ionumber_iohere(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** io_redirect      :           io_file
*/

t_node	*sh_ioredirect_iofile(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}

/*
** io_redirect      : IO_NUMBER io_file
*/

t_node	*sh_ioredirect_ionumber_iofile(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}

/*
** io_redirect      :           io_here
*/

t_node	*sh_ioredirect_iohere(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}

/*
** io_redirect      : IO_NUMBER io_here
*/

t_node	*sh_ioredirect_ionumber_iohere(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}
