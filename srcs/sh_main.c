/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:58:27 by eboris            #+#    #+#             */
/*   Updated: 2020/09/17 19:15:13 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int main(int argc, char **argv, char **env)
{
    t_main	*main;

	main = malloc(sizeof(t_main));
	ft_printf("Starting 21sh...\n");
	if (argc > 1)
	{
		main->ks = argv[1];
		main->prompt = NULL;
		sh_parser(main);
		if (!main->prompt)
			sh_lexer(main);
	}
//	sh_lexer_tree_new(main);
    (void)argc;
    (void)*argv;
    (void)*env;
    return (0);
}
