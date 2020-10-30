/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_struct_argv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:46:16 by eboris            #+#    #+#             */
/*   Updated: 2020/10/30 15:28:34 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

u_int64_t	sh_exec_struct_write_argv_num(t_main *main)
{
	t_node		*temp;
	u_int64_t	n;

	temp = main->tree_curr;
	n = 0;
	while (temp != NULL)
	{
		if ((temp->node_type == CMDSUFFIX) || (temp->node_type == CMDNAME))
		{
			n++;
		}
		temp = temp->right;
	}
	if (n > 0)
		return (n + 1);
	return (0);
}

void		sh_exec_struct_write_argv(t_main *main, t_exec *new)
{
	t_node		*temp;
	u_int64_t	n;
	u_int64_t	i;
	char		**argv;
	// t_exec		*t_new;

	temp = main->tree_curr;
	// t_new = new;
	n = sh_exec_struct_write_argv_num(main);
	i = 0;
	if (n != 0)
	{
		argv = malloc(sizeof(char*) * n);
		while (temp != NULL)
		{
			// if (temp->node_type == CMDNAME)
			// {
			// 	argv[0] = ft_strdup(temp->token->content);
			// 	if (temp->token->envvar != NULL)
			// 		sh_exec_struct_write_envvar(temp, t_new, argv[0]);
			// }
			// else if (temp->node_type == CMDSUFFIX)
			// {
			// 	// ft_printf("* %i %s\n", i, new->envvar->str);
			// 	argv[i] = ft_strdup(temp->token->content);
			// 	if (temp->token->envvar != NULL)
			// 		sh_exec_struct_write_envvar(temp, t_new, argv[i]);
			// 	i++;
			// }
			if (temp->node_type == CMDNAME)
				sh_exec_struct_write_argv_add(temp, new, argv, &i);
			else if (temp->node_type == CMDSUFFIX)
				sh_exec_struct_write_argv_add(temp, new, argv, &i);
			temp = temp->right;
		}
		argv[i] = NULL;
		main->exec_curr->argv = argv;
		new->envvar_curr = new->envvar;
	}

	// ft_printf("\nPrinting argvs env\n");
	// while (new->envvar)
	// {
	// 	ft_printf("%i %s %i -- %i\n", new->envvar->start, new->envvar->str, new->envvar->end, new->envvar->type);
	// 	new->envvar = new->envvar->next;
	// }
	// ft_printf("\nEnd argvs redirects env\n\n");

}

void		sh_exec_struct_write_argv_add(t_node *temp, t_exec *new,
			char **argv, u_int64_t *i)
{
	u_int64_t	n;

	n = *i;
	argv[n] = ft_strdup(temp->token->content);
	if (temp->token->envvar != NULL)
	{
		sh_exec_struct_write_envvar(temp, new, argv[n]);
	}
	n++;
	*i = n;
}

void		sh_exec_struct_write_envvar(t_node *node, t_exec *exec, char *argv)
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
