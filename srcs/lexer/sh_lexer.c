/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:13:46 by eboris            #+#    #+#             */
/*   Updated: 2020/09/17 18:56:15 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		sh_is_whitespace_or_tab(char c)
{
	if (c == ' ' || c == '\t')
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
	if (str[i] == '\n')
		while (str[i] == '\n')
			i++;
	else if (ft_isdigit(str[i]) == 1)
	{
		while (ft_isdigit(str[i]) == 1)
			i++;
		if (sh_is_it_io_redirect_operator(&str[i]) > 0)
			*io_nbr_flag = 1;
	}
	else if ((i = sh_is_operator(str)) > 0)
		return (i);
	else
		i = sh_find_end_of_token(i, str);
	return (i);
}

int		sh_lexer_hub(t_main *main, t_token *token)
{
	int		i;
	int		io_nbr_flag;

	i = 0;
	while (*main->ks)
	{
		while (sh_is_whitespace_or_tab(*main->ks))
			main->ks++;
		io_nbr_flag = 0;
		i = sh_check_end_of_token_position(main->ks, &io_nbr_flag);
		if (i != 0)
		{
			if (token->content)
			{
				token->next = sh_new_token(0, NULL, main);
				token = token->next;
			}
			sh_check_type_and_add_token(token, main->ks, i, io_nbr_flag);
		}
		main->ks = main->ks + i;
	}
	return (0);
}

//TEMPORARY FUNC, delete it later :)
void	ft_print_test(t_token *first)
{
	while (first)
	{
		ft_printf("%s\n", first->content);
		ft_printf("***%i***\n", first->type);
		first = first->next;
	}
}

int		sh_lexer(t_main *main)
{
	t_token	*first;

	first = sh_new_token(0, NULL, main);
	sh_lexer_hub(main, first);
	if (main->prompt)
		sh_remove_token_list(first);
	main->token = first;
	ft_print_test(first);
//	sh_lexer_tree_new(main);
	return (0); 
}
