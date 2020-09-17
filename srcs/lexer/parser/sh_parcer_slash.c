/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parcer_slash.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 18:43:26 by geliz             #+#    #+#             */
/*   Updated: 2020/09/17 19:13:38 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_check_slash(t_main *main)
{
	int		i;
	
	i = 0;
	while (*main->ks)
		main->ks++;
	--main->ks;
	while (*main->ks == '\\')
	{
		--main->ks;
		i++;
	}
	if (i % 2 != 0)
	{
		main->prompt = ft_strdup("slash");
		if (!main->prompt)
			ft_fprintf(2, "Malloc error\n");
	}
}
