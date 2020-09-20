/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parcer_heredoc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 16:42:46 by geliz             #+#    #+#             */
/*   Updated: 2020/09/20 16:29:23 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_check_heredoc(t_main *main)
{
	int		here_start;
	char	*delim;
	
	if (ft_strstr("<<", main->ks))
		here_start = ft_strlen(ft_strstr("<<", main->ks)) + 2;
	
}