/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_ctrl_left.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:20:10 by eboris            #+#    #+#             */
/*   Updated: 2020/10/26 16:04:29 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_ctrl_left(t_main *main)
{
	int	i;

	sh_cursor_minus(main);
	i = main->cursor - 1;
	while (i != 0 && ((main->ks[i] != ' ') && (main->ks[i] != '\n')))
	{
		i--;
		sh_cursor_minus(main);
	}
}
