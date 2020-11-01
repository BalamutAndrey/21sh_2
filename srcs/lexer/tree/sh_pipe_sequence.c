/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pipe_sequence.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 18:04:07 by eboris            #+#    #+#             */
/*   Updated: 2020/11/01 16:44:09 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** pipe_sequence    :                             command
**                  | pipe_sequence '|' linebreak command
*/

t_node	*sh_pipesequence(t_main *main)
{
	t_token	*curr;
	t_node	*temp;

	temp = NULL;
	curr = main->token_curr;
	if ((temp = sh_pipesequence_command(main)) != NULL)
	{
		if ((main->token_curr != NULL) && (main->token_curr->type == NEWLINE))
			main->token_curr = main->token_curr->next;
		if ((main->token_curr == NULL) || (main->token_curr->type == SEPARATOR))
		{
			return (temp);
		}
		else if (temp != NULL)
		{
			sh_lexer_del_node(&temp);
			main->token_curr = curr;
		}
	}
	if ((temp = sh_pipesequence_pipesequence_pipe_linebreak_command(main))
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
	if ((temp = sh_command(main)) != NULL)
	{
		return (temp);
	}
	return (NULL);
}

/*
** pipe_sequence    : pipe_sequence '|' linebreak command
*/

t_node	*sh_pipesequence_pipesequence_pipe_linebreak_command(t_main *main)
{
	t_node	*right;
	t_node	*left;
	t_node	*pipe;

	left = NULL;
	right = NULL;
	right = sh_pipesequence_command(main);
	if ((right != NULL) && (main->token_curr != NULL) && (main->token_curr->type == PIPELINE))
	{
		pipe = sh_lexer_create_node(main, main->token_curr, PIPELINE);
		if (main->token_curr->next == NULL)
		{
			//	Ошибка синтаксиса!!!
			// ft_printf("\n21sh: syntax error near unexpected token `%s'\n", main->token_curr->content);
			// sh_lexer_del_node(&pipe);
			// sh_lexer_del_node(&right);
			// main->token_curr = token;
			sh_lexer_tree_error(main);
			return (NULL);
		}
		main->token_curr = main->token_curr->next;
		left = sh_pipesequence(main);
		if (left == NULL)
		{
			// Ошибка синтаксиса!!!
			// ft_printf("\n21sh: syntax error near unexpected token `%s'\n", main->token_curr->content);
			// sh_lexer_del_node(&pipe);
			// sh_lexer_del_node(&right);
			// main->token_curr = token;
			sh_lexer_tree_error(main);
			return (NULL);
		}
		sh_lexer_add_node(pipe, left, right);
		return (pipe);
	}
	return (NULL);
}
