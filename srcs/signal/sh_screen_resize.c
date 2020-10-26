/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_screen_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:28:01 by eboris            #+#    #+#             */
/*   Updated: 2020/10/26 16:10:42 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_sig_screen_resize(int a)
{
	extern t_main	*main_struct;

	(void)a;
	sh_ioctl(main_struct);
	ft_putstr_fd(tgetstr("cl", NULL), main_struct->fd);
	sh_reprint_ks(main_struct);
}
