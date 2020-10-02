/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_opt_q.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:32:15 by eboris            #+#    #+#             */
/*   Updated: 2020/07/18 17:40:23 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_opt_q(t_main *main)
{
	uint64_t	i;

	i = 0;
	if (main->cursor_line > 0 && main->cursor_line_curr > 0)
	{
		while (i < main->term_col && main->cursor >= 0)
		{
			i++;
			sh_cursor_minus(main);
		}
	}
}
