/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_readline_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:34:27 by eboris            #+#    #+#             */
/*   Updated: 2020/10/17 16:37:38 by eboris           ###   ########.fr       */
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
		//sh_history_add(main);
		main->hist_curr = main->hist_end;
	}
	fin = sh_lexer_start(main);
	
	if (main->prompt != NULL)
		sh_history_add(main);
	
	
	if (main->ks_temp != NULL)
		ft_strdel(&main->ks_temp);
	return (fin);
}
