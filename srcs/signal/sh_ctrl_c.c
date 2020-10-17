/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_ctrl_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 18:16:34 by eboris            #+#    #+#             */
/*   Updated: 2020/10/17 16:09:27 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_sig_ctrl_c(int a)
{
	extern t_main	*main_struct;

	(void)a;
	tcsetattr(main_struct->fd, TCSANOW, &main_struct->t_curr);
	if (main_struct->cpid != -1)
	{
		kill(main_struct->cpid, 1);
		main_struct->cpid = -1;
		ft_putstr_fd(tgetstr("do", NULL), main_struct->fd);
		ft_putstr_fd(tgetstr("cr", NULL), main_struct->fd);
	}
	else
	{
		ft_putstr_fd(tgetstr("do", NULL), main_struct->fd);
		ft_putstr_fd(tgetstr("cr", NULL), main_struct->fd);
		ft_fprintf(STDERR_FILENO, "^C");
		ft_putstr_fd(tgetstr("do", NULL), main_struct->fd);
		ft_putstr_fd(tgetstr("cr", NULL), main_struct->fd);
		ft_bzero(main_struct->ks, MAX_KS_LEN);
		sh_rl_reset_line(main_struct);
		sh_rl_check_prompt_start(main_struct);
		//sh_print_prompt(main_struct);
		sh_cursor_math(main_struct);
		// sh_key_enter(main_struct);
		sh_reprint_ks(main_struct);
	}
}
