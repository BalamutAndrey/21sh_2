/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_struct_argv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:46:16 by eboris            #+#    #+#             */
/*   Updated: 2020/10/04 17:57:03 by eboris           ###   ########.fr       */
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
		return (n + 2);
	return (0);
}

void		sh_exec_struct_write_argv(t_main *main)
{
	t_node		*temp;
	u_int64_t	n;
	u_int64_t	i;
	char		**argv;

	temp = main->tree_curr;
	n = sh_exec_struct_write_argv_num(main);
	i = 1;
	if (n != 0)
	{
		argv = malloc(sizeof(char*) * n);
		while (temp != NULL)
		{
			if (temp->node_type == CMDNAME)
			{
				argv[0] = ft_strdup(temp->token->content);
			}
			else if (temp->node_type == CMDSUFFIX)
			{
				argv[i] = ft_strdup(temp->token->content);
				i++;
			}
			temp = temp->right;
		}
		argv[i] = NULL;
		main->exec_curr->argv = argv;
	}
}
