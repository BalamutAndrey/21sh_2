/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_structs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 11:47:56 by eboris            #+#    #+#             */
/*   Updated: 2020/10/17 15:57:29 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

t_main	*sh_add_main_struct(char **env)
{
	t_main	*new;

	if ((new = malloc(sizeof(t_main))) == NULL)
	{
		sh_term_errors_start(3);
		exit(0);
	}
	new->term_name = NULL;
	new->user = NULL;
	new->home = NULL;
	new->envp = env;
	new->prompt = NULL;
	new->path = NULL;
	new->hist = NULL;
	sh_history_create(new);
	new->dir = ft_strnew(MAX_DIR_LEN);
	new->ks = ft_strnew(MAX_KS_LEN);
	new->cursor_sel_text = ft_strnew(MAX_KS_LEN);
	new->ks_temp = NULL;
	new->heredoc = NULL;
	new->cpid = -1;
	sh_write_struct(new);
	return (new);
}

void	sh_copy_envp(t_main *main)
{
	int		i;
	char	**cur_envp;

	i = 0;
	while (main->envp[i])
		i++;
	cur_envp = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (main->envp[i])
	{
		cur_envp[i] = ft_strnew(ft_strlen(main->envp[i]));
		cur_envp[i] = ft_strcpy(cur_envp[i], main->envp[i]);
		i++;
	}
	main->envp_curr = cur_envp;
}

void	sh_write_struct(t_main *new)
{
	int		i;
	char	*temp;

	i = -1;
	while (new->envp[++i])
		if (ft_strncmp(new->envp[i], "HOME=", 5) == 0)
		{
			temp = ft_strdup(new->envp[i]);
			new->home = ft_strmancpy(temp, 5);
			ft_printf("\n%s\n", new->home);
		}
		else if (ft_strncmp(new->envp[i], "USER=", 5) == 0)
		{
			temp = ft_strdup(new->envp[i]);
			new->user = ft_strmancpy(temp, 5);
		}
}

void	sh_remove_struct(t_main **main)
{
	t_main	*temp;

	temp = *main;
	if (temp->term_name != NULL)
		ft_strdel(&temp->term_name);
	if (temp->user != NULL)
		ft_strdel(&temp->user);
	if (temp->home != NULL)
		ft_strdel(&temp->home);
	if (temp->prompt != NULL)
		ft_strdel(&temp->prompt);
	if (temp->dir != NULL)
		ft_strdel(&temp->dir);
	if (temp->ks != NULL)
		ft_strdel(&temp->ks);
	sh_history_delete(temp);
	free(*main);
	exit(0);
}
