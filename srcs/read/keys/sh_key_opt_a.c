/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_opt_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:33:15 by eboris            #+#    #+#             */
/*   Updated: 2020/07/18 17:46:56 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_opt_a(t_main *main)
{
	uint64_t	i;

	i = 0;
	if (main->cursor_line > 0 && main->cursor_line_curr <= main->cursor_line)
	{
		while (i < main->term_col && main->cursor <= (main->ks_len + main->prompt_len))
		{
			sh_cursor_plus(main);
			i++;
		}
	}
}
