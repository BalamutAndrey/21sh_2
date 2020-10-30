/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:13:46 by eboris            #+#    #+#             */
/*   Updated: 2020/10/30 17:56:17 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"
#include <signal.h>

int		sh_is_whitespace_or_tab(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

int		sh_find_end_of_token(int i, char *str)
{
	while (str[i] != '\0' && str[i] != '\n' &&
		!sh_is_whitespace_or_tab(str[i]) && !sh_is_operator(&str[i]))
	{
		if (str[i] == '\\')
			i++;
		else if (str[i] == '\'' && (i == 0 || str[i - 1] != '\\'))
			i = sh_find_closing_single_quotes(i, str);
		else if (str[i] == '"' && (i == 0 || str[i - 1] != '\\'))
			i = sh_find_closing_double_quotes(i, str);
		if (str[i] != '\0')
			i++;
	}
	return (i);
}

int		sh_check_end_of_token_position(char *str, int *io_nbr_flag)
{
	int		i;

	i = 0;
	if (ft_isdigit(str[i]) == 1)
	{
		while (ft_isdigit(str[i]) == 1)
			i++;
		if (sh_is_it_io_redirect_operator(&str[i]) > 0)
			*io_nbr_flag = 1;
		else
			i = sh_find_end_of_token(i, str);
	}
	else if ((i = sh_is_operator(str)) > 0)
		return (i);
	else
		i = sh_find_end_of_token(i, str);
	return (i);
}

void	sh_lexer_hub(t_main *main, t_token *token)
{
	int		i;
	int		j;
	int		io_nbr_flag;
	int		fin;

	i = 0;
	j = 0;
	fin = main->heredoc ? main->heredoc->here_start - 1 : ft_strlen(main->ks);
	while (j < fin)
	{
		j += i;
		while (sh_is_whitespace_or_tab(main->ks[j]))
			j++;
		io_nbr_flag = 0;
		i = sh_check_end_of_token_position(&main->ks[j], &io_nbr_flag);
//		if (i != 0)
//		{
//			if (token->content)
//			{
//				token->next = sh_new_token(0, NULL, main);
				token->next = sh_check_type_and_add_token(&main->ks[j], i, io_nbr_flag, main);
				token = token->next;
//			}
//			sh_check_type_and_add_token(token, &main->ks[j], i, io_nbr_flag);
//		}
//		j += i;
	}
}

/*
** TEMPORARY FUNC, delete it later :)
*/
void	ft_print_test(t_token *first)
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

/*
**	ft_print_test(first); can use it before return in sh_lexer
*/

//void	sh_add_newline_token(t_main *main, t_token *first)
//{

//}

int		sh_lexer(t_main *main)
{
	t_token	*first;

	first = sh_new_token(0, NULL, main);
	sh_lexer_hub(main, first);
//	sh_add_newline_token(main, first);
	if (main->prompt)
		sh_remove_token_list(first);
	main->token = first->next;
	free(first);
	first = NULL;
	if (main->heredoc)
		sh_add_heredoc_content(main);
	sh_quote_remove(main, main->token);
	ft_print_test(main->token);
	return (0);
}
