/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:58:27 by eboris            #+#    #+#             */
/*   Updated: 2020/11/08 12:59:32 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

t_main	*g_main;

int main(int argc, char **argv, char **env)
{
    t_main			*main;
	extern t_main	*g_main;

	//ft_printf("Starting 21sh...\n");
	g_main = sh_add_main_struct(env);
	main = g_main;
	if (argc > 1)
	{
		// main = malloc(sizeof(t_main));
		// main->heredoc = NULL;
		// main->token = NULL;
		ft_strcpy(main->ks, argv[1]);
		// main->prompt = NULL;
		sh_copy_envp(main);
		//sh_path(main);
		// sh_parser(main);
		// sh_lexer(main);
		sh_lexer_start(main);
		//sh_lexer_tree_new(main);
		sh_exit(main, 0);
	/*	if (!main->prompt)
		{
			sh_lexer(main);
			sh_lexer_tree_new(main);
		}*/
	}
	else
	{
		if (sh_term_check_errors_start(argc, argv, env))
			exit(0);
		// main_struct = sh_add_main_struct(env);
		// main = main_struct;
		sh_term_init(main);
		sh_signal_set();
		sh_copy_envp(main);
		sh_path(main);
		//sh_read_ks(main);
		sh_readline(main);
		sh_term_restore(main);
		sh_remove_struct(&main);
	}
//	main->opfds = NULL;
//	sh_exec(main);
	//sh_lexer_tree_new(main);
    (void)argc;
    (void)*argv;
    (void)*env;
    return (0);
}
