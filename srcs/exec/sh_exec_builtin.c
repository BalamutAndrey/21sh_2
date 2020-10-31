/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:43:11 by eboris            #+#    #+#             */
/*   Updated: 2020/10/31 17:44:15 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_exec_builtin(t_exec *exec, t_main *main)
{
	char	*finish;

	finish = NULL;
	if ((ft_strncmp(exec->argv[0], "cd ", 3) == 0) ||
		(ft_strncmp(exec->argv[0], "cd\0", 3) == 0))
	{
		finish = sh_cd(exec, main);
	}
	else if ((ft_strncmp(exec->argv[0], "pwd ", 4) == 0) ||
			(ft_strncmp(exec->argv[0], "pwd\0", 4) == 0))
	{
		sh_pwd(exec, main);
	}
	else if ((ft_strncmp(exec->argv[0], "echo ", 5) == 0) ||
			(ft_strncmp(exec->argv[0], "echo\0", 5) == 0))
	{
		sh_builtin_echo(main, exec);
	}
	else if ((ft_strncmp(exec->argv[0], "exit ", 5) == 0) ||
			(ft_strncmp(exec->argv[0], "exit\0", 5) == 0))
	{
		sh_exit(main, 0);
	}
	return (finish);
}
