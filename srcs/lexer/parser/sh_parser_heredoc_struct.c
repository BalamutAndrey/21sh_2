/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser_heredoc_struct.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:08:02 by geliz             #+#    #+#             */
/*   Updated: 2020/09/26 18:13:19 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_get_heredoc_info(t_main *main, t_heredoc *here)
{
	int		i;
	char	*str;

	if (main->heredoc->here_start == 0)
		main->heredoc->here_start = ft_strlen(main->ks);
	i = here->delim_start;
	while (main->ks[i] && sh_is_whitespace_or_tab(main->ks[i]) == 0 && 
		sh_is_operator(&main->ks[i]) == 0 && main->ks[i] != '\n')
		i++;
	here->delim = ft_strsub(main->ks, here->delim_start, i - here->delim_start);
	here->delim = ft_strjoin_arg("%s %f %s", "\n", here->delim, "\n");
}

int		sh_find_heredoc(t_main *main, int i)
{
	while (main->ks[i] != '\0')
	{
		if (main->ks[i] == '<' && main->ks[i + 1] == '<')
		{
			if (main->ks[i + 2] == '\0' || sh_is_operator(&main->ks[i + 2]) || main->ks[i + 2] == '\n')
				ft_fprintf(2, "Heredoc error, no DELIM_WORD\n");
			i += 2;
			while (main->ks[i] == '\t' || main->ks[i] == ' ')
				i++;
			return (i);
		}
		i++;
	}
	return (-1);
}

t_heredoc	*sh_create_heredoc_list(int i)
{
	t_heredoc	*tmp;

	tmp = ft_memalloc(sizeof(t_heredoc));
	tmp->next = NULL;
	tmp->delim = NULL;
	tmp->delim_start = i;
	tmp->here_end = -1;
	tmp->here_start = -1;
	return (tmp);
}

void	sh_create_heredoc_structs(t_main *main)
{
	t_heredoc	*tmp;
	int			i;

	tmp = main->heredoc;
	i = 0;
	while ((i = sh_find_heredoc(main, i)) != -1)
	{
		if (!main->heredoc)
		{
			main->heredoc = sh_create_heredoc_list(i);
			main->heredoc->here_start = 0;
			tmp = main->heredoc;
		}
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = sh_create_heredoc_list(i);
			tmp = tmp->next;
		}
		tmp->delim_start = i;
		sh_get_heredoc_info(main, tmp);
	}
}