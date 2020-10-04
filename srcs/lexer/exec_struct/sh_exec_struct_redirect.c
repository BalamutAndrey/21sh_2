/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_struct_redirect.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:55:23 by eboris            #+#    #+#             */
/*   Updated: 2020/10/04 17:46:42 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void		sh_exec_struct_redirect(t_main *main)
{
	t_redirect	*first;
	t_redirect	*curr;
	t_redirect	*temp;
	t_node		*node;

	first = NULL;
	curr = NULL;
	node = main->tree_curr;
	while (node != NULL)
	{
		if (sh_is_a_redirect(node->token) == true)
		{
			temp = sh_exec_struct_redirect_new();
			node = sh_exec_struct_redirect_write(node, temp);
			if (first == NULL)
			{
				first = temp;
				curr = first;
			}
			else
			{
				curr->next = temp;
				curr = curr->next;
			}
		}
		node = node->right;
	}
	main->exec_curr->redir = first;
}

t_redirect	*sh_exec_struct_redirect_new(void)
{
	t_redirect	*new;

	new = malloc(sizeof(t_redirect));
	if (new == NULL)
	{
		// malloc error!!!
	}
	new->io_num = -1;
	new->type = NONE;
	new->filename = NULL;
	new->next = NULL;
	return (new);
}

t_node		*sh_exec_struct_redirect_write(t_node *node, t_redirect *redirect)
{
	if (node->node_type == IO_NUMBER)
	{
		redirect->io_num = ft_atoi(node->token->content);
		node = node->right;
	}
	redirect->type = node->node_type;
	if (redirect->io_num == -1)
	{
		if ((node->node_type == LESS) || (node->node_type == DLESS) ||
		(node->node_type == LESSAND))
		{
			redirect->io_num = STDIN_FILENO;
		}
		else if ((node->node_type == GREAT) || (node->node_type == DGREAT) ||
		(node->node_type == GREATAND))
		{
			redirect->io_num = STDOUT_FILENO;
		}
	}
	node = node->right;
	redirect->filename = ft_strdup(node->token->content);
	return (node);
}
