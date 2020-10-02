/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_left.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:27:54 by eboris            #+#    #+#             */
/*   Updated: 2020/07/09 18:27:13 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_left(t_main *main)
{
	if ((main->cursor <= main->ks_len) && (main->cursor > 0))
	{
//		ft_putstr_fd(tgoto(tgetstr("le", NULL), 0, 5), main->fd);
		sh_cursor_minus(main);
	}
}
