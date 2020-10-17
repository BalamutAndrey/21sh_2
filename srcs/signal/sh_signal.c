/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 17:27:09 by eboris            #+#    #+#             */
/*   Updated: 2020/10/17 15:07:26 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_signal_set(void)
{
	signal(SIGWINCH, sh_sig_screen_resize);
	// signal(SIGBUS, sh_sig_bus_error);
	// signal(SIGSEGV, sh_sig_bus_error);
	// signal(SIGFPE, sh_sig_bus_error);
	signal(SIGINT, sh_sig_ctrl_c);
}
