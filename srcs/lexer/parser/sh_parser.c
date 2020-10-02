/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:02:16 by geliz             #+#    #+#             */
/*   Updated: 2020/10/02 19:19:58 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

bool	sh_lexer_start(t_main *main)
{
	if ((ft_strncmp(main->ks, "exit ", 5) == 0) ||
			(ft_strncmp(main->ks, "exit\0", 5) == 0))
	{
		sh_term_restore(main);
		sh_remove_struct(&main);
	}
	while (main->cursor_line_curr < main->cursor_line)
	{
		ft_putstr_fd(tgoto(tgetstr("do", NULL), 0, 5), main->fd);
		main->cursor_line_curr++;
	}
	ft_putstr_fd("Your bunny wrote: ", main->fd);
	ft_putstr_fd(main->ks, main->fd);
	ft_putstr_fd(tgetstr("do", NULL), main->fd);
	ft_putstr_fd(tgetstr("cr", NULL), main->fd);
	//if (main->ks[0] != '\0')
	sh_parser(main);
	//main->prompt = ft_strdup("test");
	return (true);
}

void	sh_parser(t_main *main)
{
	ft_printf("str = % 50s\n", main->ks);
	if (!main->prompt || !ft_strcmp(main->prompt, "quote"))
		sh_check_quotes(main);
	if (!main->prompt || !ft_strcmp(main->prompt, "dquote"))
		sh_check_dquotes(main);
//	if (!main->prompt)
//	 	sh_check_slash(main); 
	if (!main->prompt || !ft_strcmp(main->prompt, "Heredoc"))
	 	sh_check_heredoc(main);
	if (main->prompt)//tmp!!!!!!!!!!!
		ft_printf("************READ MORE -- %s\n", main->prompt);
	// if (!main->prompt)
	// 	sh_check_braces(main);
	// if (!main->prompt)
	// 	sh_check_fbraces(main);

	if (!main->prompt)
	{
		sh_lexer(main);
		sh_lexer_tree_new(main);
	}
	// 										UPPER FUNC FOR LEXER->TREE
}