/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cmd_name.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 15:50:58 by eboris            #+#    #+#             */
/*   Updated: 2020/09/20 18:30:13 by eboris           ###   ########.fr       */
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
	if ((main->token_curr == NULL) || (main->token_curr->type != WORD))
		return (NULL);
	temp = sh_lexer_create_node(main, main->token_curr, CMDNAME);
	//main->token_curr = main->token_curr->next;
	return (temp);
}
