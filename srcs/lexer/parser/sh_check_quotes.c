/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_check_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:14:02 by geliz             #+#    #+#             */
/*   Updated: 2020/09/05 17:07:05 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_check_dquotes(t_main *main)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while(main->ks[i])
	{
		if (main->ks[i] == '"')
		{
			if (i == 0 || main->ks[i - 1] != '\\')
				count++;
		}
		i++;
	}
	if (count % 2 != 0)
	{
		main->prompt = ft_strdup(">");
		if (!main->prompt)
			ft_fprintf(2, "Malloc error\n");
	}
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
			if (i == 0 || main->ks[i - 1] != '\\' || count % 2 != 0)
				count++;
		}
		i++;
	}
	if (count % 2 != 0)
	{
		main->prompt = ft_strdup(">");
		if (!main->prompt)
			ft_fprintf(2, "Malloc error\n");
	}
}
