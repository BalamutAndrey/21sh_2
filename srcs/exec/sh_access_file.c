/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_access_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 15:35:21 by eboris            #+#    #+#             */
/*   Updated: 2020/10/26 18:07:35 by eboris           ###   ########.fr       */
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
	if ((ft_strncmp(str, "exit ", 5) == 0) ||
		(ft_strncmp(str, "exit\0", 5) == 0) ||
		(ft_strncmp(str, "cd ", 3) == 0) ||
		(ft_strncmp(str, "cd\0", 3) == 0) ||
		(ft_strncmp(str, "echo ", 5) == 0) ||
		(ft_strncmp(str, "echo\0", 5) == 0) ||
		(ft_strncmp(str, "env ", 4) == 0) ||
		(ft_strncmp(str, "env\0", 4) == 0) ||
		(ft_strncmp(str, "setenv ", 7) == 0) ||
		(ft_strncmp(str, "setenv\0", 7) == 0) ||
		(ft_strncmp(str, "unsetenv ", 9) == 0) ||
		(ft_strncmp(str, "unsetenv\0", 9) == 0) ||
		(ft_strncmp(str, "pwd ", 4) == 0) ||
		(ft_strncmp(str, "pwd\0", 4) == 0))
	{
		return (true);
	}
	return (false);		
}

bool	sh_is_builtin_nofork(char *str)
{
	if ((ft_strncmp(str, "cd ", 5) == 0) ||
		(ft_strncmp(str, "cd\0", 5) == 0) ||
		(ft_strncmp(str, "exit ", 5) == 0) ||
		(ft_strncmp(str, "exit\0", 5) == 0) ||
		(ft_strncmp(str, "setenv ", 7) == 0) ||
		(ft_strncmp(str, "setenv\0", 7) == 0) ||
		(ft_strncmp(str, "unsetenv ", 9) == 0) ||
		(ft_strncmp(str, "unsetenv\0", 9) == 0))
	{
		return (true);
	}
	return (false);		
}