/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cursor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 15:04:38 by eboris            #+#    #+#             */
/*   Updated: 2020/11/07 17:28:44 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_reprint_ks(t_main *main)
{
	uint64_t	i;
	
	while (main->cursor_line_curr < main->cursor_line)
	{
		ft_putstr_fd(tgoto(tgetstr("do", NULL), 0, 5), main->fd);
		main->cursor_line_curr++;
	}
	while (main->cursor_line_curr > 1)
	{
		sh_delete_ks(main);
		ft_putstr_fd(tgoto(tgetstr("up", NULL), 0, 5), main->fd);
		main->cursor_line_curr--;
	}
	sh_delete_ks(main);
	sh_cursor_math(main);
	sh_print_prompt(main);
	i = 0;
	while (main->ks[i] != '\0')
	{
		if (main->cursor_sel == true && i >= main->cursor_sel_start && i <= main->cursor_sel_end)
		{
			ft_putstr_fd(tgetstr("so", NULL), main->fd);
			ft_putchar_fd(main->ks[i], main->fd);
			ft_putstr_fd(tgetstr("se", NULL), main->fd);
		}
		else
		{
			ft_putchar_fd(main->ks[i], main->fd);
		}
		i++;
	}
	i = main->cursor_line;
	while (main->cursor_line_curr != i)
	{
		ft_putstr_fd(tgoto(tgetstr("up", NULL), 0, 5), main->fd);
		i--;
	}
	ft_putstr_fd(tgetstr("cr", NULL), main->fd);
	i = 1;
	while (main->cursor_curr != i)
	{
		ft_putstr_fd(tgoto(tgetstr("nd", NULL), 0, 5), main->fd);
		i++;
	}
}

void	sh_delete_ks(t_main *main)
{
	ft_putstr_fd(tgoto(tgetstr("dl", NULL), 0, 5), main->fd);
	ft_putstr_fd(tgoto(tgetstr("cr", NULL), 0, 5), main->fd);
}

void	sh_cursor_plus(t_main *main)
{
	if (main->cursor < main->ks_len)
		main->cursor++;
	sh_reprint_ks(main);
}

void	sh_cursor_minus(t_main *main)
{
	if (main->cursor > 0)
		main->cursor--;
	sh_reprint_ks(main);
}
