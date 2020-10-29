/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_remove_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:14:16 by eboris            #+#    #+#             */
/*   Updated: 2020/10/29 18:31:58 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_remove_exec(t_main *main)
{
	t_exec	*temp;

	temp = main->exec_first;
	if (main->exec_first != NULL)
	{
		while (temp != NULL)
		{
			main->exec_first = temp->next;
			if (temp->cmd != NULL)
				ft_strdel(&temp->cmd);
			sh_remove_argv(temp->argv);
			temp->argv = NULL;
			sh_remove_envvar(temp->envvar);
			temp->envvar = NULL;
			temp->envvar_curr = NULL;
			free(temp);
			temp = main->exec_first;
		}
		main->exec_first = NULL;
	}
	main->exec_curr = NULL;
}

void	sh_remove_argv(char **argv)
{
	int	i;

	i = 0;
	if (argv != NULL)
	{
		while (argv[i] != NULL)
		{
			ft_strdel(&argv[i]);
			i++;
		}
		argv = NULL;
	}
}
