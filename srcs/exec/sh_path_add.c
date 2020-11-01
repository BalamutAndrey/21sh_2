/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_path_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 16:53:48 by eboris            #+#    #+#             */
/*   Updated: 2020/11/01 17:34:51 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_path_add(t_main *main, t_exec *temp)
{
	if (temp->argv != NULL && temp->argv[0][0] != '\0')
	{
		if (temp->argv[0][0] == '.')
			sh_run_write_string_point(main, temp);
		else if (temp->argv[0][0] == '~')
			sh_run_write_string_home(main, temp);
		else if ((temp->argv[0][0] != '/') &&
			(sh_is_builtin(temp->argv[0]) == false))
			sh_find_path(main, temp);
	}
//	ft_printf("\ncmd = %s\n", temp->cmd_arg[0]);
}

void	sh_run_write_string_point(t_main *main, t_exec *temp)
{
	char	*str1;
	char	*str2;

	str2 = ft_strdup(main->dir);
	str1 = ft_strdup("/");
	str2 = ft_strsdup(str2, str1);
	str1 = ft_strdup(temp->argv[0]);
	ft_strdel(&temp->argv[0]);
	temp->argv[0] = ft_strsdup(str2, str1);
}

void	sh_run_write_string_home(t_main *main, t_exec *temp)
{
	char	*str1;
	char	*str2;

	str2 = ft_strdup(temp->argv[0]);
	str2 = ft_strmancpy(str2, 1);
	str1 = ft_strdup(main->home);
	ft_strdel(&temp->argv[0]);
	temp->argv[0] = ft_strsdup(str1, str2);
}

void	sh_find_path(t_main *main, t_exec *exec)
{
	t_path	*temp;
	char	*str1;
	// char	*str2;

	temp = main->path;
	while (temp)
	{
		// str2 = ft_strdup(temp->path);
		// str1 = ft_strdup("/");
		// str2 = ft_strsdup(str2, str1);
		// str1 = ft_strdup(exec->argv[0]);
		// str1 = ft_strsdup(str2, str1);

		str1 = sh_strjoin_arg(main, "%s %s %s", temp->path, "/", exec->argv[0]);
//		ft_printf("\npath = %s\n", str1);
		if (sh_run_access(str1) == 0)
		{
			ft_strdel(&exec->argv[0]);
			exec->argv[0] = ft_strdup(str1);
			temp = NULL;
		}
		else
		{
			temp = temp->next;
		}
		ft_strdel(&str1);
	}
}
