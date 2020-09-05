/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:58:27 by eboris            #+#    #+#             */
/*   Updated: 2020/09/05 16:05:54 by geliz            ###   ########.fr       */
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
		sh_parcer(main);
	}
    (void)argc;
    (void)*argv;
    (void)*env;
    return (0);
}
