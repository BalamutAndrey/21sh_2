/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_envvar_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 17:48:25 by geliz             #+#    #+#             */
/*   Updated: 2020/10/24 18:02:39 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_envvar_add_shift_to_struct(t_envvar *envvar, char *new_str, int shift)
{
	envvar->next->str = new_str;
	envvar->next->start += shift;
	envvar->next->end += shift;
}

char	*sh_get_envvar_from_str(t_envvar *envvar)
{
	char	*var;
	int		len;

	if (envvar->type == 0)
	{
		var = ft_strdup("HOME=");
		return (var);
	}
	len = envvar->end - envvar->start;
	var = ft_strsub(envvar->str, envvar->start + 1, len - 1);
	var = ft_strjoin_arg("%f %s", var, "=");
	return (var);
}

char	*sh_find_envvar_in_env(char **env, t_envvar *envvar)
{
	int		i;
	char	*pos;
	int		len;
	char	*var;

	i = 0;
	pos = NULL;
	var = sh_get_envvar_from_str(envvar);
	while (env[i])
	{
		if ((pos = ft_strnstr(env[i], var, ft_strlen(var))) != NULL)
		{
			len = ft_strlen(var);
			ft_strdel(&var);
			return (&pos[len]);
		}
		i++;
	}
	return (NULL);
}
