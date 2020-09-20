/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:02:16 by geliz             #+#    #+#             */
/*   Updated: 2020/09/20 18:01:12 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_parser(t_main *main)
{
	ft_printf("str = %s\n", main->ks);
	if (!main->prompt)
		sh_check_quotes(main);
	if (!main->prompt)
		sh_check_dquotes(main);
	if (!main->prompt)
	 	sh_check_slash(main);
	if (!main->prompt)
	 	sh_check_heredoc(main);
	if (main->prompt)
		ft_printf("READ MORE -- %s\n", main->prompt);
	// if (!main->prompt)
	// 	sh_check_braces(main);
	// if (!main->prompt)
	// 	sh_check_fbraces(main);
}