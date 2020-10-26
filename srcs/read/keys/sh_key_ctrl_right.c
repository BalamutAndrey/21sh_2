/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_ctrl_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:21:40 by eboris            #+#    #+#             */
/*   Updated: 2020/10/26 15:48:56 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_ctrl_right(t_main *main)
{
	int	i;

	i = main->cursor + 1;
	while (main->ks[i] != '\0' && ((main->ks[i] != ' ') && (main->ks[i] != '\n')))
	{
		i++;
		sh_cursor_plus(main);
	}
	sh_cursor_plus(main);
	sh_cursor_plus(main);
}
