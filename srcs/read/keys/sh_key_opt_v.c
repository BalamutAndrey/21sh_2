/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_opt_v.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/17 17:10:41 by eboris            #+#    #+#             */
/*   Updated: 2020/07/17 18:03:51 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_opt_v(t_main *main)
{
	uint64_t	i;
	uint64_t	n;
	char		*temp;

	n = 0;
	temp = ft_strnew(MAX_KS_LEN);
	if (main->cursor_sel_text[0] != '\0')
	{
		i = main->cursor;
		while (main->ks[i] != '\0')
		{
			temp[n] = main->ks[i];
			main->ks[i] = '\0';
			i++;
			n++;
		}
		n = 0;
		i = main->cursor;
		main->cursor_sel_start = i;
		main->cursor_sel_end = i;
		while (main->cursor_sel_text[n] != '\0' && (i < MAX_KS_LEN))
		{
			main->ks[i] = main->cursor_sel_text[n];
			i++;
			n++;
			main->ks_len++;
			main->cursor_sel_end++;
			sh_cursor_plus(main);
		}
		main->cursor_sel_end--;
		n = 0;
		while (temp[n] != '\0' && (i < MAX_KS_LEN))
		{
			main->ks[i] = temp[n];
			i++;
			n++;
		}
	}
	ft_strdel(&temp);
	main->cursor_sel = true;
	sh_reprint_ks(main);
}
