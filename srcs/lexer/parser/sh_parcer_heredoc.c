/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parcer_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:42:46 by geliz             #+#    #+#             */
/*   Updated: 2020/09/20 19:08:09 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_find_heredoc_delimiter(t_main *main, t_heredoc *here)
{
	int		i;
	char	*ptr;
	
	i = here->delim_start;
	while (sh_is_whitespace_or_tab(main->ks[i]) == 1)
		i++;
	here->delim_start = i;
	while (main->ks[i] && sh_is_whitespace_or_tab(main->ks[i]) == 0 && 
		sh_is_operator(&main->ks[i]) == 0)
		i++;
	here->delim = ft_strsub(main->ks, here->delim_start, i - here->delim_start);
	here->delim = ft_strjoin_arg("%s %f %s", "\n", here->delim, "\n");
	if (!(ptr = strstr(main->ks, here->delim)))
		main->prompt = ft_strdup("Heredoc");
	else
	{
		while (&main->ks[i] != ptr)
			i++;
		here->here_end = i;
	}
	ft_printf("delim = %s, here_end = %i\n", here->delim, here->here_end);
	return (NULL);
}

void	sh_get_heredoc_info(t_main *main, t_heredoc *here)
{
	int		i;
	char	*str;

	if (main->heredoc->here_start == 0)
		main->heredoc->here_start = ft_strlen(main->ks);
	sh_find_heredoc_delimiter(main, here);

}

int		sh_find_heredoc(t_main *main, int i)
{
	while (main->ks[i] != '\0')
	{
		if (main->ks[i] == '<' && main->ks[i + 1] == '<')
		{
			if (main->ks[i + 2] == '\0' || sh_is_operator(&main->ks[i + 2]))
				ft_fprintf(2, "Heredoc error, no DELIM_WORD\n");
			return (i + 2);
			i++;
		}
		i++;
	}
	return (-1);
}

void	sh_check_heredoc(t_main *main)
{
	t_heredoc	*tmp;
	int			i;

	tmp = main->heredoc;
	i = 0;
	while ((i = sh_find_heredoc(main, i)) != -1)
	{
		if (!main->heredoc)
		{
			main->heredoc = ft_memalloc(sizeof(t_heredoc));
			main->heredoc->next = NULL;
			main->heredoc->here_start = 0;
			tmp = main->heredoc;
		}
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = ft_memalloc(sizeof(t_heredoc));
			tmp = tmp->next;
			tmp->next = NULL;
		}
		tmp->delim_start = i;
		sh_get_heredoc_info(main, tmp);
	}
}
