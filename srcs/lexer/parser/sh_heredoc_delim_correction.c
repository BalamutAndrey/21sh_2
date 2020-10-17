/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_heredoc_delim_correction.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 18:01:28 by geliz             #+#    #+#             */
/*   Updated: 2020/10/17 18:34:56 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_heredoc_dslashes_remove(int i, int end, t_heredoc *here, t_main *main)
{
	while (i < end)
	{
		if (here->delim[i] == '\\' && here->delim[i + 1] == '\\')
			sh_heredoc_remove_char(i, here, main);
		i++;
		end--;
	}
	return (end);
}

int		sh_heredoc_dquotes_remove(t_heredoc *here, int i, t_main *main)
{
	int		tmp;

	tmp = i;
	sh_heredoc_remove_char(i, here, main);
	while (here->delim[i] != '\"' || sh_is_protected(here->delim, i) == 1)
	{
		if (here->delim[i] == '\\' && here->delim[i + 1] == '\"' &&
            sh_is_protected(here->delim, i) == 0)
			{
				sh_heredoc_remove_char(i, here, main);
				i++;
			}
		else
			i++;
	}
	sh_heredoc_remove_char(i, here, main);
	i = sh_heredoc_dslashes_remove(tmp, i, here, main);
	return (i + 1);
}

int		sh_heredoc_squotes_remove(t_heredoc *here, int i, t_main *main)
{
	sh_heredoc_remove_char(i, here, main);
	while (here->delim[i] != '\'')
		i++;
	sh_heredoc_remove_char(i, here, main);
	return (i);
}
void	sh_heredoc_remove_char(int i, t_heredoc *here, t_main *main)
{
	char	*ret;
	int		len;
	int		j;

	len = ft_strlen(here->delim) - 1;
	j = 0;
	ret = ft_strnew(len);
	while (j < len)
	{
		if (j < i)
		{
			ret[j] = here->delim[j];
			j++;
		}
		else 
		{
			ret[j] = here->delim[i + 1];
			j++;
			i++;
		}
	}
	ft_strdel(&here->delim);
	here->delim = ret;
    ret = NULL;
}

void	sh_find_and_remove_heredoc_quotes(t_heredoc *here, t_main *main)
{
	int		i;

	i = 0;
	while (here->delim[i])
	{
		if (here->delim[i] == '\"' && sh_is_protected(here->delim, i) == 0)
			i = sh_heredoc_dquotes_remove(here, i, main);
		else if (here->delim[i] == '\'' && sh_is_protected(here->delim, i) == 0)
			i = sh_heredoc_squotes_remove(here, i, main);
		else if (here->delim[i] == '\\')
		{
			sh_heredoc_remove_char(i, here, main);
			i++;
		}
		else
			i++;
	}
}

void    sh_heredoc_delim_correction(t_main *main)
{
    t_heredoc   *tmp;
    
    tmp = main->heredoc;
    while (tmp)
    {
        sh_find_and_remove_heredoc_quotes(tmp, main);
        tmp = tmp->next;
    }
}
