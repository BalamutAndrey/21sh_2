/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cmd_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:50:58 by eboris            #+#    #+#             */
/*   Updated: 2020/09/17 17:56:06 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** cmd_name         : WORD                   !! Apply rule 7a !!
*/

t_node	*sh_cmdname(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_cmdname_word(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** cmd_name         : WORD                   !! Apply rule 7a !!
*/

t_node	*sh_cmdname_word(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if 
	return (NULL);
}
