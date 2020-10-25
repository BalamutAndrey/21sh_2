/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_struct_redirect.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:55:23 by eboris            #+#    #+#             */
/*   Updated: 2020/10/25 17:58:55 by geliz            ###   ########.fr       */
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
			
			// ft_printf("\nPrinting redirects env\n");
			// while (temp->envvar)
			// {
			// 	ft_printf("%i %s %i -- %i\n", temp->envvar->start, temp->envvar->str, temp->envvar->end, temp->envvar->type);
			// 	temp->envvar = temp->envvar->next;
			// }
			// ft_printf("\nEnd printing redirects env\n\n");

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
	new->envvar = NULL;
	new->envvar_curr = NULL;
	new->error = 0;
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

	if (node->token->envvar != NULL)
	{
		sh_exec_struct_write_redir_envvar(node, redirect, redirect->filename);
	}

	return (node);
}

void		sh_exec_struct_write_redir_envvar(t_node *node, t_redirect *exec, char *argv)
{
	if (exec->envvar == NULL)
	{
		exec->envvar = node->token->envvar;
		exec->envvar_curr = exec->envvar;
	}
	else
	{
		exec->envvar_curr->next = node->token->envvar;
		exec->envvar_curr = exec->envvar_curr->next;
	}
	while (exec->envvar_curr->next != NULL)
	{
		exec->envvar_curr->str = argv;
		exec->envvar_curr = exec->envvar_curr->next;
	}
	exec->envvar_curr->str = argv;
}
