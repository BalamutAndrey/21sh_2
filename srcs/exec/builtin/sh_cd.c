/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:10:08 by eboris            #+#    #+#             */
/*   Updated: 2020/10/31 18:35:02 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_cd(t_exec *exec, t_main *main)
{
	int		i;
	int		n;
	char	*fin;

	i = 0;
	n = 1;
	fin = NULL;
	while (exec->argv[n] != NULL)
	{
		i++;
		n++;
	}
	if (i > 2)
		fin = sh_strdup(
		"21sh: cd: too many arguments\nUsage: cd [-L | -P] directory\n", main);
	else if (i == 2)
	{
		fin = sh_cd_check_param(exec, main);
	}
	else
	{
		fin = sh_cd_change_dir(exec, main, false);
	}
	return (fin);
}

// void	sh_cd_error(t_main *main)
// {
// 	ft_fprintf(2, "Usage: cd [-L | -P] directory\n");
// }

char	*sh_cd_check_param(t_exec *exec, t_main *main)
{
	char	*fin;

	fin = NULL;
	if ((ft_strncmp(exec->argv[1], "-L", 3) == 0) ||
		(ft_strncmp(exec->argv[1], "--logical", 9) == 0))
	{
		sh_cd_change_dir(exec, main, false);
	}
	else if ((ft_strncmp(exec->argv[1], "-P", 3) == 0) ||
			(ft_strncmp(exec->argv[1], "--physical", 10) == 0))
	{
		fin = sh_cd_change_dir(exec, main, true);
	}
	else
	{
		fin = sh_strjoin_arg(main, "%s %s %s", "21sh: cd: string not in pwd: ",
			exec->argv[1], "\nUsage: cd [-L | -P] directory\n");
	}
	return (fin);
}

char	*sh_cd_change_dir(t_exec *exec, t_main *main, bool param)
{
	int8_t	p;
	char	*fin;

	fin = NULL;
	if (param == true)
		p = 2;
	else
		p = 1;
	if (exec->argv[p] != NULL && exec->argv[p][0] != '\0')
	{
		if (exec->argv[p][0] == '~')
			sh_home_dir(exec, main, p);
		else if ((exec->argv[p][0] == '-') && (exec->argv[p][1] == '\0'))
			sh_prev_dir(exec, main, p);
		else if (exec->argv[p][0] != '/')
			sh_no_root_dir(exec, main, p);
	}
	else
		sh_chdir_save_argv(exec, main, p);
	fin = sh_chdir_finish(exec, main, param, p);
	return (fin);
}

void	sh_chdir_save_argv(t_exec *exec, t_main *main, int8_t p)
{
	int16_t	i;

	i = 0;
	while (exec->argv[i])
	{
		ft_strdel(&exec->argv[i]);
		i++;
	}
	free(exec->argv);
	exec->argv = malloc(sizeof(char **) * p + 1);
	exec->argv[0] = sh_strdup("cd", main);
	exec->argv[p] = sh_strdup(main->home, main);
}

// Разобраться в двумя точками в pwd. Ключи попутаны местами или неправильный ключ по дефолту.

char	*sh_chdir_finish(t_exec *exec, t_main *main, bool param, int p)
{
	int		fin;
	char	*temp1;
	char	*temp2;
	char	*finish;

	finish = NULL;
	if ((access(exec->argv[p], 0) == 0) && (access(exec->argv[p], 1) == -1))
	{
		finish = sh_strjoin_arg(main,
			"%s %s %s", "21sh: cd: permission denied: ", exec->argv[p], "\n");
	}
	else
	{
		fin = chdir(exec->argv[p]);
		if (fin != 0)
			finish = sh_strjoin_arg(main, "%s %s %s",
				"21sh: cd: no such file or directory: ", exec->argv[p], "\n");
		else
		{
			temp1 = sh_strdup("OLDPWD", main);
			temp2 = sh_strdup(main->dir, main);
			sh_env_replace(main, temp1, temp2);
			ft_strdel(&main->dir);
			main->dir = sh_strnew(MAX_DIR_LEN, main);
			getcwd(main->dir, MAX_DIR_LEN);
			temp1 = sh_strdup("PWD", main);
			if (param == false)
			{
				temp2 = sh_strdup(exec->argv[p], main);
			}
			else
			{
				temp2 = sh_strdup(main->dir, main);
			}
			sh_env_replace(main, temp1, temp2);
		}
	}
	return (finish);
}
