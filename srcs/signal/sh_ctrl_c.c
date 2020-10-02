/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ctrl_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:16:34 by eboris            #+#    #+#             */
/*   Updated: 2020/07/08 14:11:22 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_sig_ctrl_c(int a)
{
	extern t_main	*main_struct;

	(void)a;
	ft_putstr_fd(tgetstr("do", NULL), main_struct->fd);
	ft_putstr_fd(tgetstr("cr", NULL), main_struct->fd);
	ft_putstr_fd("^C", main_struct->fd);
	ft_putstr_fd(tgetstr("do", NULL), main_struct->fd);
	ft_putstr_fd(tgetstr("cr", NULL), main_struct->fd);
}
