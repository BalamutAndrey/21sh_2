/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_right.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:29:39 by eboris            #+#    #+#             */
/*   Updated: 2020/07/09 18:27:27 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_right(t_main *main)
{
//	uint64_t	i;

	if (main->cursor <= (main->ks_len - 1))
	{
		sh_cursor_plus(main);
		// if (main->cusor_curr > 0)
		// {
		// 	ft_putstr_fd(tgoto(tgetstr("nd", NULL), 0, 5), main->fd);
		// }
		// else
		// {
		// 	sh_reprint_ks(main);
		// }
	}
}
