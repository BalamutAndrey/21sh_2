/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_ctrl_right.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 16:21:40 by eboris            #+#    #+#             */
/*   Updated: 2020/07/18 17:20:56 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_key_ctrl_right(t_main *main)
{
	int	i;

	i = main->cursor + 1;
	while (main->ks[i] != '\0' && ((main->ks[i] >= 65 && main->ks[i] <= 90) || (main->ks[i] >= 97 && main->ks[i] <= 122)))
	{
		i++;
		sh_cursor_plus(main);
	}
	sh_cursor_plus(main);
}
