/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_access_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 15:35:21 by eboris            #+#    #+#             */
/*   Updated: 2020/11/04 17:34:31 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_run_access(char *str)
{
	int			i;
	struct stat	buff;

	i = 0;
	if ((sh_is_builtin(str) == true) && (sh_is_builtin_nofork(str) == false))
		return (6);
// No fork
	if ((sh_is_builtin(str) == true) && (sh_is_builtin_nofork(str) == true))
		return (5);
	if (access(str, 0) != 0)
	{
		// ft_printf("\n Access 0 error \n");
		return (1);
	}
	if (access(str, 1) != 0)
	{
		// ft_printf("\n Access 1 error \n");
		return (2);
	}
	lstat(str, &buff);
	if (!(S_ISLNK(buff.st_mode)) && !(S_ISREG(buff.st_mode)))
	{
		// ft_printf("\n Not a file of link \n");
		return (3);
	}
	if (!(S_ISLNK(buff.st_mode)))
		stat(str, &buff);
	if ((buff.st_mode & S_IXUSR) || (buff.st_mode & S_IXGRP) ||
			(buff.st_mode & S_IXOTH))
		return (0);
	// ft_printf("\n End error \n");
	return (4);
}

bool	sh_is_builtin(char *str)
{
	if ((ft_strcmp(str, "exit") == 0) ||
		(ft_strcmp(str, "cd") == 0) ||
		(ft_strcmp(str, "echo") == 0) ||
		(ft_strcmp(str, "env") == 0) ||
		(ft_strcmp(str, "setenv") == 0) ||
		(ft_strcmp(str, "unsetenv") == 0) ||
		(ft_strcmp(str, "pwd") == 0))
	{
		return (true);
	}
	return (false);		
}

bool	sh_is_builtin_nofork(char *str)
{
	if ((ft_strcmp(str, "cd") == 0) ||
		(ft_strcmp(str, "exit") == 0) ||
		(ft_strcmp(str, "setenv") == 0) ||
		(ft_strcmp(str, "unsetenv") == 0))
	{
		return (true);
	}
	return (false);		
}