/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cmd_word.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:55:08 by eboris            #+#    #+#             */
/*   Updated: 2020/09/07 15:56:43 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** cmd_word         : WORD                   !! Apply rule 7b !!
*/

t_node	*sh_cmdword(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_cmdword_word(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** cmd_word         : WORD                   !! Apply rule 7b !!
*/

t_node	*sh_cmdword_word(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}
