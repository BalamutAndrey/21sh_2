/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_bus_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 15:50:38 by eboris            #+#    #+#             */
/*   Updated: 2020/08/04 16:48:59 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_sig_bus_error(int a)
{
	extern t_main	*main_struct;

	(void)a;
	//ft_putstr_fd("\n21sh: bus error\n", main_struct->fd);
	ft_putstr_fd("\n21sh: bus error\n", 1);
}
