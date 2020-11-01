/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_readline_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:34:27 by eboris            #+#    #+#             */
/*   Updated: 2020/11/01 19:30:11 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

bool	sh_readline_end(t_main *main)
{
	bool	fin;

	if (main->ks_temp != NULL)
	{
		main->ks_temp = ft_strjoin_arg("%f %f", main->ks_temp, main->ks);
		main->ks = ft_strnew(MAX_KS_LEN);
		ft_strcpy(main->ks, main->ks_temp);
		ft_strdel(&main->ks_temp);
	}
	if (main->prompt != NULL)
	{
		ft_strdel(&main->hist_end->prev->com);
		main->hist_end->prev->com = ft_strdup(main->ks);
		ft_strdel(&main->prompt);
	}
	else
	{
		sh_history_add(main);
		main->hist_curr = main->hist_end;
	}
	fin = sh_lexer_start(main);
	sh_readline_clear(main);
	return (fin);
}

void	sh_readline_clear(t_main *main)
{
	sh_remove_token(main);
	sh_remove_tree(main);
	sh_remove_exec(main);
	if (main->ks_temp != NULL)
		ft_strdel(&main->ks_temp);
}
