/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/10 17:19:22 by eboris            #+#    #+#             */
/*   Updated: 2020/07/10 17:28:44 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_path(t_main *main)
{
	int		i;
	char	*temp;

	i = 0;
	temp = NULL;
	if (main->path)
		sh_path_del(main);
	while ((main->envp_curr[i]) &&
			(ft_strncmp(main->envp_curr[i], "PATH=", 5) != 0))
		i++;
	if (main->envp_curr[i])
	{
		temp = ft_strdup(main->envp_curr[i]);
		temp = ft_strmancpy(temp, 5);
		if ((temp) && (temp[0] != '\0'))
			main->path = sh_path_write(temp);
	}
}

void	sh_path_del(t_main *main)
{
	t_path	*temp;
	t_path	*temp2;

	if (main->path)
		temp = main->path;
	else
		temp = NULL;
	while (temp)
	{
		temp2 = temp->next;
		if (temp->path)
			ft_strdel(&temp->path);
		free(temp);
		temp = temp2;
	}
	main->path = NULL;
}

t_path	*sh_path_write(char *param)
{
	t_path	*first;
	t_path	*new;
	t_path	*prev;
	char	*str;
	int		i;

	prev = NULL;
	new = NULL;
	while ((param) && (param[0] != '\0'))
	{
		i = 0;
		while ((param[i] != '\0') && (param[i] != ':'))
			i++;
		if (param[i] == ':')
			str = ft_strmbncpy(param, i);
		else
			str = ft_strdup(param);
		param = ft_strmancpy(param, (i + 1));
		if (new)
			prev = new;
		new = sh_path_write_struct(prev, &first, str);
	}
	ft_strdel(&param);
	return (first);
}

t_path	*sh_path_write_struct(t_path *prev, t_path **first, char *str)
{
	t_path	*new;

	new = malloc(sizeof(t_path));
	new->path = ft_strdup(str);
	ft_strdel(&str);
	new->next = NULL;
	if (prev)
		prev->next = new;
	else
		*first = new;
	ft_strdel(&str);
	return (new);
}
