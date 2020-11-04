/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_builtin_unsetenv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:53:52 by geliz             #+#    #+#             */
/*   Updated: 2020/11/04 19:11:22 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_builtin_unsetenv_create_new(t_main *main, int pos, int j)
{
	char	**new;
	int		z;

	z = 0;
	new = sh_memalloc(sizeof(char*) * (j - 1), main);
	new[j - 1] = NULL;
	j = 0;
	while (main->envp_curr[j])
	{
		if (j == pos)
			j++;
		new[z] = sh_strdup(main->envp_curr[j], main);
		j++;
		z++;
	}
	sh_remove_envp_curr(main);
	main->envp_curr = new;
}

void	sh_builtin_unsetenv_delete_one(t_main *main, char *tmp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (main->envp_curr[i] && ft_strcmp(main->envp_curr[i], tmp) != 0)
		i++;
	if (!main->envp_curr[i])
	{
		ft_strdel(&tmp);
		return ;
	}
	else
	{
		while (main->envp_curr[j])
			j++;
		sh_builtin_unsetenv_create_new(main, i, j);
		ft_strdel(&tmp);
	}
}

char	*sh_builtin_unsetenv(t_exec *exec, t_main *main)
{
	int		i;
	char	*tmp;

	i = 1;
	if (!exec->argv[i])
		return (sh_strdup("21sh: unsetenv: too few arguments\n", main));
	while (exec->argv[i])
	{
		tmp = sh_strjoin_arg(main, "%s %s", exec->argv[i], "=");
		sh_builtin_unsetenv_delete_one(main, tmp);
		i++;
	}
	return (NULL);
}
