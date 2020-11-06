/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_tree_error.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 16:57:19 by eboris            #+#    #+#             */
/*   Updated: 2020/11/06 18:55:29 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** TEMPORARY FUNC, delete it later :)
*/
void	ft_print_test_2(t_token *first)
{
	char* type[] = {"NONE", "COMPLETE_COMMAND", "LIST", "PIPELINE", "AND_OR",
					"COMMAND", "CMDNAME", "CMDSUFFIX", "SEPARATOR", "WORD",
					"NEWLINE", "IO_NUMBER", "LESS", "GREAT", "AND_IF",
					"OR_IF", "DSEMI", "DLESS", "DGREAT", "LESSAND",
					"GREATAND", "LESSGREAT", "DLESSDASH", "CLOBBER","LBRACE",
					"RBRACE", "BANG"};
	int	i = 1;
	t_envvar	*t;

	while (first)
	{
		ft_printf("%2i. %s - %i: %s\n", i, first->content, first->type, type[first->type]);
		first = first->next;
		i++;
	}
}

void	sh_lexer_tree_error(t_main *main)
{
	ft_fprintf(STDERR_FILENO, \
		"21sh: syntax error near unexpected token '%s'\n", \
		main->token_curr->content);
//	ft_print_test_2(main->token);
	sh_remove_token(main);
	sh_remove_tree(main);
	sh_remove_exec(main);
}
