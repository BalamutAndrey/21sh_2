/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pipe_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 18:04:07 by eboris            #+#    #+#             */
/*   Updated: 2020/09/03 18:07:49 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** pipe_sequence    :                             command
**                  | pipe_sequence '|' linebreak command
*/

t_node	*sh_pipesequence(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_pipesequence_command(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_pipesequence_pipesequence_pipe_linebreak_command(main))
				!= NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** pipe_sequence    :                             command
*/

t_node	*sh_pipesequence_command(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}

/*
** pipe_sequence    : pipe_sequence '|' linebreak command
*/

t_node	*sh_pipesequence_pipesequence_pipe_linebreak_command(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}
