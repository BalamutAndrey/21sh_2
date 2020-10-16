/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cursor_math.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:37:04 by eboris            #+#    #+#             */
/*   Updated: 2020/10/16 17:56:00 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_cursor_math(t_main *main)
{
	main->cursor_line = main->ks_len / main->term_col;
	if (main->cursor < (main->term_col - main->prompt_len))
	{
		main->cursor_curr = main->cursor + main->prompt_len;
		main->cursor_line_curr = 0;
	}
	else
	{
		main->cursor_line_curr = (main->cursor + main->prompt_len) / main->term_col;
		main->cursor_curr = (main->cursor + main->prompt_len) % main->term_col;
	}

	// uint64_t	i;
	// uint64_t	col;

	// i = 0;
	// col = 0;
	// main->cursor_line = 1;
	// if (main->ks_len < main->term_col)
	// {
	// 	sh_cursor_add(main, 1, main->ks_len);
	// }
	// while (main->ks[i] != '\0')
	// {
	// 	if ((col == main->term_col) || (main->ks[i] == '\n'))
	// 	{
	// 		main->cursor_line++;
	// 		col = 0;
	// 		sh_cursor_add(main, main->cursor_line, col);
	// 	}
	// 	col++;
	// 	i++;
	// }
	// main->cur_curr = main->cur_first;
	// if (main->ks[main->cursor] == '\n')
	// {
	// 	if (main->ks[main->cursor + 1] != '\0')
	// 	{
	// 		main->cursor++;
	// 	}
	// 	else
	// 	{
	// 		main->cursor--;
	// 	}
	// }
	// i = main->prompt_len;
	// main->cursor_line_curr = 0;
	// while (i < )
	// {
	// 	ft_printf("*%i", main->cur_curr->line);
	// 	i = i + main->cur_curr->simvol;
	// 	main->cursor_line_curr++;
	// 	main->cur_curr = main->cur_curr->next;
	// }
	// main->cursor_line_curr++;
	// ft_printf("cursor = %i, curr = %i, all = %i", main->cursor, main->cursor_line_curr, main->cursor_line);
}

void	sh_cursor_add(t_main *main, uint64_t line, uint64_t col)
{
	t_cursor	*new;

	new = ft_memalloc(sizeof(t_cursor));
	if (main->cur_first == NULL)
	{
		main->cur_first = new;
		main->cur_curr = new;
		main->cur_curr->prev = NULL;
	}
	else
	{
		main->cur_curr->next = new;
		new->prev = main->cur_curr;
		main->cur_curr = new;
	}
	main->cur_curr->line = line;
	main->cur_curr->simvol = col;
	main->cur_curr->next = NULL;
	new = NULL;
}
