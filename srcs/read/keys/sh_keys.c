/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 16:49:25 by eboris            #+#    #+#             */
/*   Updated: 2020/10/16 19:16:50 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

bool	sh_keys(t_main *main, uint64_t buf)
{
	if (main->cursor_sel == true && buf != 0x44323b315b1b && buf != 0x43323b315b1b
			&& buf != 0xa7c3 && buf != 0x9a88e2 && buf != 0x8889e2)
		{
			main->cursor_sel = false;
			sh_reprint_ks(main);
		}
	if (buf == 0xA)
		return (sh_key_enter(main));
	else if (buf == 0x445B1B)
		sh_key_left(main);
	else if (buf == 0x435B1B)
		sh_key_right(main);
	else if (buf == 0x415B1B)
		sh_key_up(main);
	else if (buf == 0x425B1B)
		sh_key_down(main);
	else if (buf == 0x7f)
		sh_key_backspace(main);
	else if (buf == 0x7E335B1B)
		sh_key_delete(main);
	else if (buf == 0x485B1B)
		sh_key_home(main);
	else if (buf == 0x465B1B)
		sh_key_end(main);
	else if (buf == 0x4)
		return (sh_key_ctrl_d(main));
	else
		return (sh_keys_2(main, buf));
	return (true);
}

bool	sh_keys_2(t_main *main, uint64_t buf)
{
	if (buf == 0x44323b315b1b)
		sh_key_shift_left(main);
	else if (buf == 0x43323b315b1b)
		sh_key_shift_right(main);
	else if (buf == 0xa7c3)
		sh_key_opt_c(main);
	else if (buf == 0x9a88e2)
		sh_key_opt_v(main);
	else if (buf == 0x8889e2)
		sh_key_opt_x(main);
	else if (buf == 0x44353b315b1b)
		sh_key_ctrl_left(main);
	else if (buf == 0x43353b315b1b)
		sh_key_ctrl_right(main);
	else if (buf == 0x93c5)
		sh_key_opt_q(main);
	else if (buf == 0xa5c3)
		sh_key_opt_a(main);
	// else
	// {
	// 	ft_putstr_fd(tgetstr("do", NULL), main->fd);
	// 	ft_putstr_fd(tgetstr("cr", NULL), main->fd);
	// 	ft_printf("Key: %llx", buf);
	// 	ft_putstr_fd(tgetstr("do", NULL), main->fd);
	// 	ft_putstr_fd(tgetstr("cr", NULL), main->fd);
	// }
	return (true);
}
