/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:02:16 by geliz             #+#    #+#             */
/*   Updated: 2020/09/26 18:25:05 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

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
}