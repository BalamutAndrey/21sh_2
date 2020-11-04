/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:27:54 by eboris            #+#    #+#             */
/*   Updated: 2020/11/04 16:26:23 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_left(t_main *main)
{
	if ((main->cursor <= main->ks_len) && (main->cursor > 0))
	{
		sh_cursor_minus(main);
	}
}
