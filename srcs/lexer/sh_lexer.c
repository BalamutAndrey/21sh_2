/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:13:46 by eboris            #+#    #+#             */
/*   Updated: 2020/09/05 18:46:35 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int		ft_is_whitespace_or_tab(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int		ft_find_end_of_token(int i, char *str)
{
	while (str[i] != '\0' && str[i] != '\n' &&
		!ft_is_whitespace_or_tab(str[i]) && !ft_is_operator(&str[i]))
	{
		if (str[i] == '\\' && str[i + 1])
			i += 2;
		else if (str[i] == '\'' && i - 1 >= 0 && str[i - 1] != '\\')
			i = ft_find_closing_single_quotes(i, str);
		else if (str[i] == '"' && i - 1 >= 0 && str[i - 1] != '\\')
			i = ft_find_closing_double_quotes(i, str);
		if (str[i] != '\0')
			i++;
	}
	return (i);
}

int		ft_check_end_of_token_position(char *str, int *io_nbr_flag)
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
		if (str[i] == '>' || str[i] == '<')
		{
			*io_nbr_flag = 1;
			i++;
		}
//		i = ft_find_end_of_token(i, str, cont_read);
	}
	else if ((i = ft_is_operator(str)) > 0)
		return (i);
	else
		i = ft_find_end_of_token(i, str);
	return (i);
}

int		ft_lexer_hub(t_main *main, t_list *data)
{
	int		i;
	int		io_nbr_flag;
	t_list	*nextlist;

	i = 0;
	while (*main->ks)
	{
		while (ft_is_whitespace_or_tab(*main->ks))
			main->ks++;
		io_nbr_flag = 0;
		i = ft_check_end_of_token_position(main->ks, &io_nbr_flag);
		if (i != 0)
		{
			if (data->content)
			{
				nextlist = ft_lstnew(NULL, 0);
				data->next = nextlist;
				data = data->next;
			}
			ft_check_type_and_add_token(data, main->ks, i, io_nbr_flag);
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
	ft_lexer_hub(main, first);
	ft_print_test(first);
	return (0); 
}
