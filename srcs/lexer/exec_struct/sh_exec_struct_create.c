/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_struct_create.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 14:51:20 by eboris            #+#    #+#             */
/*   Updated: 2020/10/30 16:12:01 by eboris           ###   ########.fr       */
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
		ft_printf("Pipe? %i\n", main->exec_curr->pipe);
		ft_printf("\n end exec-structs\n");
		main->exec_curr = main->exec_curr->next;
	}
}

// void	sh_exec_struct_pipe(t_main *main)
// {
// 	t_exec	*temp;
// 	bool	pipe;

// 	temp = main->exec_first;
// 	pipe = false;
// 	while (temp)
// 	{
// 		if ((pipe == false) && (temp->pipe == true))
// 		{
// 			temp->pipe = false;
// 			pipe = true;
// 		}
// 		else if ((pipe == true) && (temp->pipe == false))
// 		{
// 			pipe = false;
// 		}
// 		temp = temp->next;
// 	}
// }

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
		first = main->exec_first;
		main->exec_first = main->exec_first->next;
		main->exec_curr = main->exec_first;
		
		sh_remove_exec_exec(first);

		// sh_exec_struct_pipe(main);
//		temp_print_exec(main);
	}
	else
	{
		// Удалить фирст вместо этого!!!!
		sh_remove_exec(main);
		main->exec_first = NULL;
	}
	// MUSOR
	// if (main->ks[0] == '\0')
	// 	main->exec_first = NULL;
}

void	sh_exec_struct_go(t_main *main, bool pipe)
{
	t_node	*temp;
	bool	sep;

	sep = false;
	temp = main->tree_curr;
	if (temp != NULL)
	{
		if ((main->tree_curr->node_type == SEPARATOR) && (main->tree_curr->right != NULL) && (main->tree_curr->right->node_type == PIPELINE))
		{
			main->tree_curr = temp->right->right;
			sh_exec_struct_go(main, false);
			main->tree_curr = temp->right;
			sep = true;
		}
		else if ((main->tree_curr->node_type == SEPARATOR) && (main->tree_curr->right != NULL))
		{
			main->tree_curr = temp->right;
			sh_exec_struct_go(main, false);
			main->tree_curr = temp;
		}
		else if ((main->tree_curr->node_type == PIPELINE) && (main->tree_curr->right != NULL))
		{
			main->tree_curr = temp->right;
			sh_exec_struct_go(main, true);
			main->tree_curr = temp;
		}
		else
		{
			sh_exec_struct_write(main, pipe);
			main->tree_curr = temp;
		}
	}
	if (main->tree_curr->left != NULL)
	{
		if (main->tree_curr->node_type == SEPARATOR)
		{
			main->tree_curr = main->tree_curr->left;
			sh_exec_struct_go(main, false);
		}
		else if (main->tree_curr->node_type == PIPELINE)
		{
			main->tree_curr = main->tree_curr->left;
			sh_exec_struct_go(main, true);
		}
	}
	if ((sep == true) && (temp->left != NULL))
	{
		sep = false;
		main->tree_curr = temp->left;
		sh_exec_struct_go(main, false);
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
	new->cmd = NULL;
	new->argv = NULL;
	// new->env = NULL;
	new->redir = NULL;
	new->pipe = false;
	new->pipefd[0] = STDIN_FILENO;
	new->pipefd[1] = STDOUT_FILENO;
	new->envvar = NULL;
	new->envvar_curr = NULL;
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
	sh_exec_struct_write_argv(main, new);
	sh_exec_struct_redirect(main);
	new->pipe = pipe;
	main->tree_curr = node;
}
