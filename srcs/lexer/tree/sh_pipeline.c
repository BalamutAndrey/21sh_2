/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pipeline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:53:53 by eboris            #+#    #+#             */
/*   Updated: 2020/09/17 18:56:59 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** pipeline         :      pipe_sequence
**                  | Bang pipe_sequence
*/

t_node	*sh_pipeline(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_pipeline_pipesequence(main)) != NULL)
	{
		return (temp);
	}
	else if ((temp = sh_pipeline_bang_pipesequence(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** pipeline         :      pipe_sequence
*/

t_node	*sh_pipeline_pipesequence(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_command(main)) != NULL)
		return (temp);
	return (NULL);
}

/*
** pipeline         : Bang pipe_sequence
*/

t_node	*sh_pipeline_bang_pipesequence(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}
