/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_envvar_in_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:48:28 by geliz             #+#    #+#             */
/*   Updated: 2020/10/24 18:10:10 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_change_envvars_in_exec_struct(t_main *main, t_envvar *envvar)
{
	char	*ret;
	char	*env_cont;
	char	*before_var;
	char	*after_var;
	
	before_var = NULL;
	after_var = NULL;
	env_cont = sh_find_envvar_in_env(main->envp_curr, envvar);
	envvar->type = ft_strlen(env_cont) - (envvar->end - envvar->start);
	if (envvar->start > 0)
		before_var = ft_strsub(envvar->str, 0, envvar->start);
	if (envvar->end < ft_strlen(envvar->str))
		after_var = ft_strsub(envvar->str, envvar->end, ft_strlen(envvar->str) - envvar->end);
	ret = ft_strjoin_arg("%f %s %f", before_var, env_cont, after_var);
	return (ret);
}

void	sh_envvar_change_argv(t_envvar *envvar, t_exec *exec, char *new_str)
{
	int		i;

	i = 0;
	while (exec->argv[i] != envvar->str)
		i++;
	ft_strdel(&exec->argv[i]);
	exec->argv[i] = new_str;
	new_str = NULL;
}

void	sh_change_envvars_in_exec(t_main *main, t_exec *exec)
{
	char	*new_str;
	char	*tmp;
	int		shift;

	tmp = NULL;
	shift = 0;
	while (exec->envvar)
	{
		new_str = sh_change_envvars_in_exec_struct(main, exec->envvar);
		sh_envvar_change_argv(exec->envvar, exec, new_str);
		if (!tmp)
			tmp = exec->envvar->str;
		if (exec->envvar->next && tmp == exec->envvar->next->str)
		{
			shift += exec->envvar->type;
			sh_envvar_add_shift_to_struct(exec->envvar, new_str, shift);
		}
		else
		{
			tmp = NULL;
			shift = 0;
		}
		exec->envvar = exec->envvar->next;
	}
}
