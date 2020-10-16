/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_key_ctrl_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/05 15:41:57 by eboris            #+#    #+#             */
/*   Updated: 2020/10/16 19:26:09 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

bool	sh_key_ctrl_d(t_main *main)
{
	if (ft_strcmp(main->prompt, "here") == 0)
	{
		main->ks[main->ks_len++] = 4;
		ft_putstr_fd(tgetstr("do", NULL), main->fd);
		ft_putstr_fd(tgetstr("cr", NULL), main->fd);
		return (false);
	}
	return (true);
}
