/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/15 16:07:07 by eboris            #+#    #+#             */
/*   Updated: 2020/09/15 16:20:34 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

t_node	*sh_lexer_create_node(t_main *main, t_token *token)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (new == NULL)
	{
		// Error
		(void)main;
	}
	else
	{
		new->token = token;
		new->left = NULL;
		new->right = NULL;
		return (new);
	}
}

void	*sh_lexer_add_node(t_node *node, t_node *left, t_node *right)
{
	if (node != NULL)
	{
		node->left = left;
		node->right = right;
	}
}

void	sh_lexer_del_node(t_node **node)
{
	ft_memdel((void **)node);
}
