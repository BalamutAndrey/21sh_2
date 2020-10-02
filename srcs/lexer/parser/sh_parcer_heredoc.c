/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parcer_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:42:46 by geliz             #+#    #+#             */
/*   Updated: 2020/10/02 15:52:36 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_get_heredoc_content(t_main *main)
{
	t_heredoc	*tmp;

	tmp = main->heredoc;
	while (tmp->here_end != -1)
	{
		if (tmp->next && tmp->next->here_start == -1)
			tmp->next->here_start = tmp->here_end;
		tmp = tmp->next;
	}
	if (ft_strstr(&main->ks[tmp->here_start], tmp->delim))
	{
		tmp->here_end = ft_strlen(main->ks);
		tmp->content = ft_strsub(main->ks, tmp->here_start, 
			ft_strlen(main->ks) - tmp->here_start - ft_strlen(tmp->delim));
	}
//	ft_erase_delims?? OR in LEXER
}

void	sh_print_heredoc(t_main *main)
{
	t_heredoc	*tmp; // TMP FUNC, DELETI IT LATER

	tmp = main->heredoc;
	while (tmp)
	{
		ft_printf("heredoc delim = %s\nheredoc content = %s\n", tmp->delim, tmp->content);
		tmp = tmp->next;
	}
}

int		sh_is_heredoc_finished(t_main *main)
{
	t_heredoc	*tmp;
	char		*str;

	tmp = main->heredoc;
	while (tmp)
	{
		if (tmp->here_end == -1)
		{
			main->prompt = ft_strdup("Heredoc");
			return (0);
		}
		tmp = tmp->next;
	}
	if (main->prompt)
	{
		ft_strdel(&main->prompt);
		main->prompt = NULL;
		sh_print_heredoc(main);////TEMP FUNC
	}
	return (1);
}

void	sh_check_heredoc(t_main *main)
{
	if (!main->heredoc)
		sh_create_heredoc_structs(main);
	sh_print_heredoc(main);////TEMP FUNC
	ft_printf("******str = %s\n", main->ks);
	if (main->heredoc)
	{
		if (sh_is_heredoc_finished(main) == 0)
			sh_get_heredoc_content(main);
		sh_is_heredoc_finished(main);
	}
}
