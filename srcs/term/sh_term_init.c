/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_term_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/28 11:33:48 by eboris            #+#    #+#             */
/*   Updated: 2020/07/19 15:15:46 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

bool	sh_term_init(t_main *main)
{
	if ((getenv("TERM") == NULL) ||
			(main->term_name = ft_strdup(getenv("TERM"))) == NULL)
		sh_error_init(1, main);
	if (tgetent(NULL, main->term_name) <= 0)
		sh_error_init(2, main);
	// if ((main->fd = open(ttyname(1), O_RDWR | O_NDELAY)) < 0)
	// 	sh_error_init(3, main);
	// dup2(STDIN_FILENO, 100);
	main->fd = STDOUT_FILENO;
	tcgetattr(main->fd, &main->t_start);
	ft_memcpy(&main->t_curr, &main->t_start, sizeof(main->t_start));
	main->t_curr.c_lflag &= ~(ICANON | ECHO | ECHONL | IEXTEN);
	// main->t_curr.c_oflag &= ~(OPOST);
	main->t_curr.c_cc[VMIN] = 1;
	main->t_curr.c_cc[VTIME] = 0;
	if (tcsetattr(main->fd, TCSANOW, &main->t_curr) == -1)
		sh_error_init(4, main);
	ft_putstr_fd(tgetstr("cl", NULL), main->fd);
	ft_putstr_fd(tgetstr("ti", NULL), main->fd);
	ft_putstr_fd(tgetstr("vs", NULL), main->fd);
	sh_ioctl(main);
	return (false);
}

void	sh_ioctl(t_main *main)
{
	struct winsize w;

	ioctl(main->fd, TIOCGWINSZ, &w);
	main->term_col = w.ws_col;
	main->term_row = w.ws_row;
}

void	sh_term_restore(t_main *main)
{
	//ft_putstr_fd(tgetstr("cl", NULL), main->fd);
	ft_putstr_fd(tgetstr("te", NULL), main->fd);
	ft_putstr_fd(tgetstr("ve", NULL), main->fd);
	tcsetattr(main->fd, TCSANOW, &main->t_start);
	close(main->fd);
}
