/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:02:16 by geliz             #+#    #+#             */
/*   Updated: 2020/10/02 15:34:41 by eboris           ###   ########.fr       */
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
	ft_printf("str = %s\n", main->ks);
	if (!main->prompt)
		sh_check_quotes(main);
	if (!main->prompt)
		sh_check_dquotes(main);
	if (!main->prompt)
	 	sh_check_slash(main); 
	if (!main->prompt || !ft_strcmp(main->prompt, "Heredoc"))
	 	sh_check_heredoc(main);
	if (main->prompt)
		ft_printf("READ MORE -- %s\n", main->prompt);
/*	main->ks = ft_strdup("cat EOF  cat EODF\n");
	sh_check_heredoc(main);
	main->ks = ft_strjoin_arg("%f %s", main->ks, "12345678901234567890\n099887654321END\n");
	sh_check_heredoc(main);
	main->ks = ft_strjoin_arg("%f %s", main->ks, "EOF\n");
	sh_check_heredoc(main);
	main->ks = ft_strjoin_arg("%f %s", main->ks, "kjasdlkfkjlkasdkkasjdkfjas;kdfs;dkfkj\n");
	sh_check_heredoc(main);
	main->ks = ft_strjoin_arg("%f %s", main->ks, "sdjfkjaskfkjadskjfkkajsldfsadfjksEND\n");
	sh_check_heredoc(main);
	main->ks = ft_strjoin_arg("%f %s", main->ks, "EODF\n");
	sh_check_heredoc(main); */
	// if (!main->prompt)
	// 	sh_check_braces(main);
	// if (!main->prompt)
	// 	sh_check_fbraces(main);
	if (!main->prompt)
	{
		sh_lexer(main);
		sh_lexer_tree_new(main);
	}
}