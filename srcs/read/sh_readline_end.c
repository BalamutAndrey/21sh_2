/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_readline_end.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:34:27 by eboris            #+#    #+#             */
/*   Updated: 2020/10/15 17:35:52 by eboris           ###   ########.fr       */
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
		ft_strdel(&main->prompt);
	}
	fin = sh_lexer_start(main);
	sh_history_add(main);
	main->hist_curr = main->hist_end;
	if (main->ks_temp != NULL)
	{
		ft_strdel(&main->ks_temp);
	}
	return (fin);
}
