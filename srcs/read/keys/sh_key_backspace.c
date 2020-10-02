/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_backspace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:35:11 by eboris            #+#    #+#             */
/*   Updated: 2020/07/09 15:00:27 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_backspace(t_main *main)
{
	uint64_t	i;
	char		*temp;
	
	if ((main->cursor == main->ks_len) && (main->cursor > 0))
	{
		sh_cursor_minus(main);
		main->ks_len--;
		main->ks[main->cursor] = '\0';
	}
	else if (main->cursor > 0)
	{
		i = main->cursor;
		temp = ft_strnew(MAX_KS_LEN);
		while (main->ks[i] != '\0')
		{
			temp[i - main->cursor] = main->ks[i];
			i++;
		}
		i = 0;
		sh_cursor_minus(main);
		while (temp[i] != '\0')
		{
			main->ks[main->cursor + i] = temp[i];
			i++;
		}
		main->ks[main->cursor + i] = '\0';
		ft_strdel(&temp);
		main->ks_len--;
	}
	sh_reprint_ks(main);
}
