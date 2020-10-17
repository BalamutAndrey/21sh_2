/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_check_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:14:02 by geliz             #+#    #+#             */
/*   Updated: 2020/10/17 18:49:01 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_check_dquotes(t_main *main)
{
	int		i;
	int		count_sq;
	int		count_dq;

	i = 0;
	count_sq = 0;
	count_dq = 0;
	while(main->ks[i])
	{
		if (main->ks[i] == '\"' && count_sq == 0)
		{
			if (sh_is_protected(main->ks, i) == 0)
				count_dq++;
		}
		else if (main->ks[i] == '\'' && count_dq == 0)
		{
			if ((count_sq % 2 == 0 && sh_is_protected(main->ks, i) == 0) || count_sq % 2 != 0)
				count_sq++;
		}
		i++;
	}
	if (count_dq > count_sq && count_dq % 2 != 0)
	{
		main->prompt = ft_strdup("dquote");
		if (!main->prompt)
			ft_fprintf(2, "Malloc error\n");
	}
	else if (count_sq > count_dq && count_sq % 2 != 0)
	{
		main->prompt = ft_strdup("quote");
		if (!main->prompt)
			ft_fprintf(2, "Malloc error\n");
	}
	else
		ft_strdel(&main->prompt);
}

void	sh_check_quotes(t_main *main)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while(main->ks[i])
	{
		if (main->ks[i] == '\'')
		{
			if ((count % 2 == 0 && sh_is_protected(main->ks, i) == 0) || count % 2 != 0)
				count++;
		}
		i++;
	}
	if (count % 2 != 0)
	{
		main->prompt = ft_strdup("quote");
		if (!main->prompt)
			ft_fprintf(2, "Malloc error\n");
	}
	else
		ft_strdel(&main->prompt);
}
