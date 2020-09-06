/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:13:46 by eboris            #+#    #+#             */
/*   Updated: 2020/09/06 16:30:03 by geliz            ###   ########.fr       */
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
		else if (str[i] == '\'' && i - 1 >= 0 && str[i - 1] != '\\')
			i = sh_find_closing_single_quotes(i, str);
		else if (str[i] == '"' && i - 1 >= 0 && str[i - 1] != '\\')
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
//		i = ft_find_end_of_token(i, str, cont_read);
	}
	else if ((i = sh_is_operator(str)) > 0)
		return (i);
	else
		i = sh_find_end_of_token(i, str);
	return (i);
}

int		sh_lexer_hub(t_main *main, t_list *data)
{
	int		i;
	int		io_nbr_flag;
	t_list	*nextlist;

	i = 0;
	while (*main->ks)
	{
		while (sh_is_whitespace_or_tab(*main->ks))
			main->ks++;
		io_nbr_flag = 0;
		i = sh_check_end_of_token_position(main->ks, &io_nbr_flag);
		if (i != 0)
		{
			if (data->content)
			{
				nextlist = ft_lstnew(NULL, 0);
				data->next = nextlist;
				data = data->next;
			}
			sh_check_type_and_add_token(data, main->ks, i, io_nbr_flag);
		}
		main->ks = main->ks + i;
	}
	return (0);
}

//TEMPORARY FUNC, delete it later :)
void	ft_print_test(t_list *first)
{
	t_token	*t;
	t_list 	*print;

	print = first;
	while (print)
	{
		t = print->content;
		ft_printf("%s\n", t->content);
		ft_printf("***%i***\n", t->type);
		print = print->next;
	}
}

int		sh_lexer(t_main *main)
{
	t_list	*first;

	first = ft_lstnew(NULL, 0);
	sh_lexer_hub(main, first);
	ft_print_test(first);
	return (0); 
}
