/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cmd_suffix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:21:03 by eboris            #+#    #+#             */
/*   Updated: 2020/09/07 16:24:16 by eboris           ###   ########.fr       */
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
	return (NULL);
}

/*
** cmd_suffix       : cmd_suffix WORD
*/

t_node	*sh_cmdsuffix_cmdsuffix_word(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}
