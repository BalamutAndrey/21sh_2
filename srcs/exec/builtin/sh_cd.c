/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 17:10:08 by eboris            #+#    #+#             */
/*   Updated: 2020/10/12 16:36:21 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_cd(t_exec *exec, t_main *main)
{
	int		i;
	int		n;

	i = 0;
	n = 1;
	while (exec->argv[n] != NULL)
	{
		i++;
		n++;
	}
	if (i > 2)
	{
		ft_fprintf(2, "21sh: cd: too many arguments\n");
		sh_cd_error(main);
	}
	else if (i == 2)
	{
		sh_cd_check_param(exec, main);
	}
	else
	{
		sh_cd_change_dir(exec, main, false);
	}
}

void	sh_cd_error(t_main *main)
{
	ft_fprintf(2, "Usage: cd [-L | -P] directory\n");
}

void	sh_cd_check_param(t_exec *exec, t_main *main)
{
	if ((ft_strncmp(exec->argv[1], "-L", 3) == 0) ||
		(ft_strncmp(exec->argv[1], "--logical", 9) == 0))
	{
		sh_cd_change_dir(exec, main, false);
	}
	else if ((ft_strncmp(exec->argv[1], "-P", 3) == 0) ||
			(ft_strncmp(exec->argv[1], "--physical", 10) == 0))
	{	
		sh_cd_change_dir(exec, main, true);
	}
	else
	{
		ft_fprintf(2, "21sh: cd: string not in pwd: %s\n", exec->argv[1]);
		sh_cd_error(main);
	}
}

void	sh_cd_change_dir(t_exec *exec, t_main *main, bool param)
{
	int8_t	p;
	int16_t	i;

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
	{
		i = 0;
		while(exec->argv[i])
		{
			ft_strdel(&exec->argv[i]);
			i++;
		}
		free(exec->argv);
		exec->argv = malloc(sizeof(char **) * p + 1);
		exec->argv[0] = ft_strdup("cd");
		exec->argv[p] = ft_strdup(main->home);
	}
	sh_chdir_finish(exec, main, param, p);
	(void)main;
}

void	sh_chdir_finish(t_exec *exec, t_main *main, bool param, int p)
{
	int		fin;
	char	*temp1;
	char	*temp2;

	if ((access(exec->argv[p], 0) == 0) && (access(exec->argv[p], 1) == -1))
	{
		ft_fprintf(2, "21sh: cd: permission denied: %s\n", exec->argv[p]);
	}
	else
	{
		fin = chdir(exec->argv[p]);
		if (fin != 0)
			ft_fprintf(2, "21sh: cd: no such file or directory: %s\n", exec->argv[p]);
		else
		{
			temp1 = ft_strdup("OLDPWD");
			temp2 = ft_strdup(main->dir);
			sh_env_replace(main, temp1, temp2);
			ft_strdel(&main->dir);
			main->dir = ft_strnew(MAX_DIR_LEN);
			getcwd(main->dir, MAX_DIR_LEN);
			temp1 = ft_strdup("PWD");
			if (param == false)
			{
				temp2 = ft_strdup(exec->argv[p]);
			}
			else
			{		
				temp2 = ft_strdup(main->dir);
			}
			sh_env_replace(main, temp1, temp2);
		}
	}
}