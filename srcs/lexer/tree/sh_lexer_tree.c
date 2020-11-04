/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:03:07 by eboris            #+#    #+#             */
/*   Updated: 2020/11/04 16:23:32 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_lexer_tree_new(t_main *main)
{
	t_node	*node;
	t_node	*end;

	node = sh_lexer_create_node(main, NULL, SEPARATOR);
	main->tree_first = node;
	main->tree_curr = node;
	main->token_curr = main->token;
	end = sh_complete_command(main, node);
}
