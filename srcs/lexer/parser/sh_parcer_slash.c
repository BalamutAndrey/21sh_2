/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parcer_slash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:43:26 by geliz             #+#    #+#             */
/*   Updated: 2020/09/20 14:39:19 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_check_slash(t_main *main)
{
	int		i;
	int		j;
	
	i = 0;
	j = ft_strlen(main->ks);
	while (main->ks[j] == '\\')
	{
		j--;
		i++;
	}
	if (i % 2 != 0)
	{
		main->prompt = ft_strdup("slash");
		if (!main->prompt)
			ft_fprintf(2, "Malloc error\n");
	}
}
