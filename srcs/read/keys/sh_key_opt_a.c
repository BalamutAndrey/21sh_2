/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_opt_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:33:15 by eboris            #+#    #+#             */
/*   Updated: 2020/10/25 18:54:10 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_opt_a(t_main *main)
{
	// uint64_t	i;

	// i = 0;
	// if (main->cursor_line > 0 && main->cursor_line_curr <= main->cursor_line)
	// {
	// 	while (i < main->term_col && main->cursor <= (main->ks_len + main->prompt_len))
	// 	{
	// 		sh_cursor_plus(main);
	// 		i++;
	// 	}
	// }

	uint64_t	line;
	uint64_t	col;

	if (main->cursor_line > 1 && main->cursor_line_curr <= main->cursor_line)
	{
		line = main->cursor_line_curr + 1;
		if (main->cursor_curr > main->curs[main->cursor_line_curr + 1])
		{
			col = main->curs[main->cursor_line_curr + 1];
		}
		else
		{
			col = main->cursor_curr;
		}
		if (main->cursor_line_curr == main->cursor_line)
		{
			line = main->cursor_line_curr;
			col = main->curs[main->cursor_line_curr];
		}
		while (main->cursor_line_curr != line)
		{
			sh_cursor_plus(main);
		}
		while (main->cursor_curr != col)
		{
			sh_cursor_plus(main);
		}
	}
}
