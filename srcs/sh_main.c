/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:58:27 by eboris            #+#    #+#             */
/*   Updated: 2020/09/20 17:10:02 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

int main(int argc, char **argv, char **env)
{
    t_main	*main;

	main = malloc(sizeof(t_main));
	main->heredoc = NULL;
	ft_printf("Starting 21sh...\n");
	if (argc > 1)
	{
		main->ks = argv[1];
		main->prompt = NULL;
		sh_parser(main);
		if (!main->prompt)
			sh_lexer(main);
	}
	sh_lexer_tree_new(main);
    (void)argc;
    (void)*argv;
    (void)*env;
    return (0);
}
