/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:02:16 by geliz             #+#    #+#             */
/*   Updated: 2020/11/01 15:52:05 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

bool	sh_lexer_start(t_main *main)
{
	// if ((ft_strncmp(main->ks, "exit ", 5) == 0) ||
	// 		(ft_strncmp(main->ks, "exit\0", 5) == 0))
	// {
	// 	sh_term_restore(main);
	// 	sh_remove_struct(&main);
	// }
	while (main->cursor_line_curr < main->cursor_line)
	{
		ft_putstr_fd(tgoto(tgetstr("do", NULL), 0, 5), main->fd);
		main->cursor_line_curr++;
	}
	//ft_putstr_fd("Your bunny wrote: ", main->fd);
	//ft_putstr_fd(main->ks, main->fd);
	ft_putstr_fd(tgetstr("do", NULL), main->fd);
	ft_putstr_fd(tgetstr("cr", NULL), main->fd);
	sh_parser(main);
	return (true);
}

int		sh_is_it_protected(char *str)
{
	int		i;
	int		j;

	i = ft_strlen(str);
	j = 0;
	while (i > 0 && str[i - 1] == '\\')
	{
		i--;
		j++;
	}
	if (j % 2 == 0)
		return (0);
	else
		return (1);
}

int		sh_is_str_empty(char *str)
{
	int		i;

	i = 0;
	if (!str)
		return (1);
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

void	sh_parser(t_main *main)
{
	int		empty;

	empty = sh_is_str_empty(main->ks);
	if (!main->prompt && !main->heredoc)
		sh_check_quotes(main);
	if (!main->prompt && !main->heredoc)
		sh_check_slash(main);
	if (!main->prompt && !main->heredoc)
		sh_check_pipe(main);
	if (!main->prompt || !ft_strcmp(main->prompt, "Heredoc"))
		sh_check_heredoc(main);
	if (!main->prompt && empty == 0)
	{
		sh_lexer(main);
		sh_lexer_tree_new(main);
		if (main->tree_first != NULL)
			sh_exec_struct_create(main);
		if (main->exec_first != NULL)
			sh_exec(main);
		//else
			//Почистить всю фигню !!!
	}
}
