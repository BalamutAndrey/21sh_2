/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parcer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:02:16 by geliz             #+#    #+#             */
/*   Updated: 2020/09/05 16:09:21 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_parcer(t_main *main)
{
	sh_check_quotes(str);
	sh_check_dquotes(str);
	sh_check_braces(str);
	sh_check_fbraces(str);
}