/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_struct_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 14:51:20 by eboris            #+#    #+#             */
/*   Updated: 2020/10/11 16:23:49 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	temp_print_exec(t_main *main)
{
	char* type[] = {"NONE", "COMPLETE_COMMAND", "LIST", "PIPELINE", "AND_OR",
                "COMMAND", "CMDNAME", "CMDSUFFIX", "SEPARATOR", "WORD",
                "NEWLINE", "IO_NUMBER", "LESS", "GREAT", "AND_IF",
                "OR_IF", "DSEMI", "DLESS", "DGREAT", "LESSAND",
                "GREATAND", "LESSGREAT", "DLESSDASH", "CLOBBER","LBRACE",
				"RBRACE", "BANG"};
	int	i;
	
	ft_printf("\n\n Printing exec-structs...\n");
	main->exec_curr = main->exec_first;
	while (main->exec_curr)
	{
		if (main->exec_curr->argv != NULL)
		{
			ft_printf("Argv's:\n");
			i = 0;
			while (main->exec_curr->argv[i] != NULL)
			{
				ft_printf("argv[%i] = %s\n", i, main->exec_curr->argv[i]);
				i++;
			}
		}
		if (main->exec_curr->redir != NULL)
		{
			ft_printf("Redirs's:\n");
			i = 0;
			while (main->exec_curr->redir != NULL)
			{
				ft_printf("io_num = %i\n", main->exec_curr->redir->io_num);
				ft_printf("type = %i - %s\n", main->exec_curr->redir->type, type[main->exec_curr->redir->type]);
				ft_printf("filename = %s\n\n", main->exec_curr->redir->filename);
				main->exec_curr->redir = main->exec_curr->redir->next;
			}
		}
		ft_printf("\n Pipe? %i\n", main->exec_curr->pipe);
		ft_printf("\n end exec-structs\n");
		main->exec_curr = main->exec_curr->next;
	}
}

void	sh_exec_struct_create(t_main *main)
{
	t_exec	*first;

	first = sh_exec_struct_new(main);
	main->exec_first = first;
	main->exec_curr = first;
//	main->tree_curr = main->tree_first->right;
	main->tree_curr = main->tree_first;
	sh_exec_struct_go(main, false);
	if (main->exec_first->next != NULL)
	{
		main->exec_first = main->exec_first->next;
//		temp_print_exec(main);
	}
	// Удалить фирст! 
}

void	sh_exec_struct_go(t_main *main, bool pipe)
{
	t_node	*temp;

	temp = main->tree_curr;
//	if ((temp->right != NULL) || (temp->node_type != SEPARATOR) || (temp->node_type != PIPELINE))
	if (temp != NULL)
	{
//		if (temp->right->node_type == SEPARATOR)
		if ((temp->node_type == SEPARATOR) && (temp->right != NULL))
		{
			main->tree_curr = temp->right;
			sh_exec_struct_go(main, false);
		}
//		else if (temp->right->node_type == PIPELINE)
		else if ((temp->node_type == PIPELINE) && (temp->right != NULL))
		{
			main->tree_curr = temp->right;
			sh_exec_struct_go(main, true);
		}
		else
		{
//			main->tree_curr = temp->right;
			sh_exec_struct_write(main, pipe);
		}
	}
	main->tree_curr = temp;
	if (temp->left != NULL)
	{
		if (temp->node_type == SEPARATOR)
		{
			main->tree_curr = temp->left;
			sh_exec_struct_go(main, false);
		}
		else if (temp->node_type == PIPELINE)
		{
			main->tree_curr = temp->left;
			sh_exec_struct_go(main, true);
		}
		else
		{
			main->tree_curr = temp->left;
			sh_exec_struct_write(main, pipe);
		}
	}
}

t_exec	*sh_exec_struct_new(t_main *main)
{
	t_exec	*new;

	new = malloc(sizeof(t_exec));
	if (new == NULL)
	{
		//malloc error!
	}
	new->argv = NULL;
	new->env = NULL;
	new->redir = NULL;
	new->pipe = false;
	new->pipefd[0] = STDIN_FILENO;
	new->pipefd[1] = STDOUT_FILENO;
	new->next = NULL;
	return (new);
}

void	sh_exec_struct_write(t_main *main, bool pipe)
{
	t_node	*node;
	t_exec	*new;

	node = main->tree_curr;
	new = sh_exec_struct_new(main);
	main->exec_curr->next = new;
	main->exec_curr = main->exec_curr->next;
	sh_exec_struct_write_argv(main);
	sh_exec_struct_redirect(main);
	new->pipe = pipe;
	main->tree_curr = node;
}
