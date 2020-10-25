/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cursor_math.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/16 16:37:04 by eboris            #+#    #+#             */
/*   Updated: 2020/10/25 18:37:20 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_cursor_math(t_main *main)
{
	// main->cursor_line = main->ks_len / main->term_col;
	// if (main->cursor < (main->term_col - main->prompt_len))
	// {
	// 	main->cursor_curr = main->cursor + main->prompt_len;
	// 	main->cursor_line_curr = 0;
	// }
	// else
	// {
	// 	main->cursor_line_curr = (main->cursor + main->prompt_len) / main->term_col;
	// 	main->cursor_curr = (main->cursor + main->prompt_len) % main->term_col;
	// }
	int64_t	i;
	uint64_t	l;
	uint64_t	n;

	i = main->prompt_len + 1;
	l = 0;
	n = 0;
	while (main->ks[n] != '\0')
	{
		if (i == (main->term_col))
		{
			l++;
			main->curs[l] = i;
			i = 1;
			n++;
		}
		else if (main->ks[n] == '\n')
		{
			l++;
		 	main->curs[l] = i;
		 	i = 1;
			n++;
		}
		else
		{
			n++;
			i++;
		}
	}
	l++;
	main->curs[l] = i;
	main->curs[l + 1] = 0;
	main->cursor_line = l;
	sh_cursor_math_curr(main);
}

void	sh_cursor_math_curr(t_main *main)
{
	int	i;
	int	n;

	i = 1;
	n = main->cursor + main->prompt_len + 1;
	// ft_printf("#%i#%i#%i#", main->cursor, main->prompt_len, n);
	while ((n > main->term_col) || (n > main->curs[i]))
	{
		// ft_printf("$%i %i$", i, n);
		n = n - main->curs[i];
		i++;
	}
	main->cursor_curr = n;
	main->cursor_line_curr = i;
	// ft_printf("*%i*%i*%i*%i*%i*%i*%i*%i*%i", main->term_col, main->cursor, main->cursor_curr, 
	// 							main->cursor_line, main->cursor_line_curr,
	// 							main->curs[1], main->curs[2], main->curs[3], main->curs[4]);
}


// ???
void	sh_cursor_reset(t_main *main)
{
	main->cursor_line = 0;
	main->cursor_line_curr = 0;
	main->cursor_curr = 0;
}
