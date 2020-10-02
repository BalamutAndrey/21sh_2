/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_read_ks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 15:20:40 by eboris            #+#    #+#             */
/*   Updated: 2020/10/02 15:20:43 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_read_ks(t_main *main)
{
	uint64_t	i;
	char		*temp;
	uint64_t	buf;
	bool		fin;

	fin = true;
	while (fin == true)
	{
		main->ks_len = 0;
		main->ks_temp_len = 0;
		main->cursor = 0;
		main->cursor_sel = false;
		main->cursor_sel_start = 0;
		main->cursor_sel_end = 0;
		if (main->prompt == NULL)
		{
			sh_ks_and_dir(main);
		}
		else
		{
			main->ks_temp_len = ft_strlen(main->ks);
			main->ks_temp = ft_strdup(main->ks);
			ft_bzero(main->ks, MAX_KS_LEN);
			main->ks_temp[main->ks_temp_len] = '\n';
		}
		sh_print_prompt(main);
	
		sh_cursor_math(main);
		while (fin == true)
		{
			buf = 0;
			read(0, &buf, 8);
			if (((main->ks_len + main->ks_temp_len) < MAX_KS_LEN) && (sh_isprint(buf) == true))
			{
				main->cursor_sel = false;
				main->cursor_sel_start = 0;
				main->cursor_sel_end = 0;
				if (main->cursor == main->ks_len)
				{		
					main->ks[main->ks_len] = buf;
					//ft_putchar_fd(main->ks[main->ks_len], main->fd);
				}
				else
				{
					i = main->cursor;
					temp = ft_strnew(MAX_KS_LEN);
					while (main->ks[i] != '\0')
					{
						temp[i - main->cursor] = main->ks[i];
						i++;
					}
					main->ks[main->cursor] = buf;
					i = main->cursor;
					while (temp[i - main->cursor] != '\0')
					{
						main->ks[i + 1] = temp[i - main->cursor];
						i++;
					}
					ft_strdel(&temp);
					//sh_reprint_ks(main);
				}
				main->ks_len++;
				sh_cursor_plus(main);
				// if (main->cusor_curr == 0)
				// 	ft_putstr_fd(tgoto(tgetstr("nd", NULL), 0, 5), main->fd);
			}
			else
				fin = sh_keys(main, buf);
		}
		if (main->ks_temp != NULL)
		{
			main->ks_temp = ft_strjoin_arg("%f %f", main->ks_temp, main->ks);
			main->ks = ft_strnew(MAX_KS_LEN);
			ft_strcpy(main->ks, main->ks_temp);
			ft_strdel(&main->ks_temp);
			ft_strdel(&main->prompt);
		}
		fin = sh_lexer_start(main);
		// fin = sh_parser(main);
		sh_history_add(main);
		main->hist_curr = main->hist_end;
		if (main->ks_temp != NULL)
		{
			ft_strdel(&main->ks_temp);
		}
	}
}

void	sh_ks_and_dir(t_main *main)
{
	ft_bzero(main->dir, MAX_DIR_LEN);
	ft_bzero(main->ks, MAX_KS_LEN);
	getcwd(main->dir, MAX_DIR_LEN - 1);
	main->ks_len = 0;
}

void	sh_print_prompt(t_main *main)
{
	main->prompt_len = 3;
	if (main->prompt == NULL)
	{
		if (main->user)
		{
			ft_printf("%s ", main->user);
			main->prompt_len = main->prompt_len + ft_strlen(main->user) + 1;
		}
		else
		{
			ft_printf("%03ix%03i [%02i]", main->term_col, main->term_row, main->fd);
			main->prompt_len = main->prompt_len + 8 + 4;
		}
		ft_printf("$> ");
	}
	else
	{
		main->prompt_len = main->prompt_len + ft_strlen(main->prompt);
		ft_printf("%s> ", main->prompt);
		//Заменить на удаление ПОСЛЕ истории!!!
		//ft_strdel(&main->prompt);
	}
}
