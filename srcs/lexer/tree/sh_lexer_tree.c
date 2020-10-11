/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_tree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:03:07 by eboris            #+#    #+#             */
/*   Updated: 2020/10/11 18:56:04 by eboris           ###   ########.fr       */
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
	if ((end == NULL) || (node == NULL) ||
		((node->left == NULL) && (node->right == NULL)))
	{
		if (node->token != NULL)
		{
			//Syntax Error near: %s\n
		}
		else
		{
			//malloc error
		}
	}
	else
	{
		//Делаем связный список
		// ft_printf("\n*** START printing tree... ***\n");
		// sh_lexer_tree_print(main->tree_first, 0);
		// ft_printf("\n***  END  printing tree... ***\n");
	}
}

// Темп! Удалить

void	sh_lexer_tree_print(t_node *node, int a)
{
	int		i;
	char* type[] = {"NONE", "COMPLETE_COMMAND", "LIST", "PIPELINE", "AND_OR",
                    "COMMAND", "CMDNAME", "CMDSUFFIX", "SEPARATOR", "WORD",
                    "NEWLINE", "IO_NUMBER", "LESS", "GREAT", "AND_IF",
                    "OR_IF", "DSEMI", "DLESS", "DGREAT", "LESSAND",
                    "GREATAND", "LESSGREAT", "DLESSDASH", "CLOBBER","LBRACE",
					"RBRACE", "BANG"};

	i = -1;
	ft_printf("\n");
	while (++i < a)
		ft_printf(" ");
	ft_printf("NODE ADRESS   = %p\n", node);
	i = -1;
	while (++i < a)
		ft_printf(" ");
	ft_printf("TOKEN TYPE    = ");
	if (node != NULL)
		ft_printf("%s (%i)\n", type[node->node_type], node->node_type);
	else
		ft_printf("NULL\n");
	i = -1;
	while (++i < a)
		ft_printf(" ");
	ft_printf("TOKEN CONTENT = ");
	if ((node->token != NULL) && (node->token->content != NULL))
		ft_printf("%s\n", node->token->content);
	else
		ft_printf("NULL\n");
	i = -1;
	while (++i < a)
		ft_printf(" ");	
	ft_printf("RIGHT         = %p\n", node->right);
	i = -1;
	while (++i < a)
		ft_printf(" ");	
	ft_printf("LEFT          = %p\n", node->left);
	ft_printf("\n");
	if (node->right != NULL)
		sh_lexer_tree_print(node->right, a + 1);
	ft_printf("\n");
	if (node->left != NULL)
		sh_lexer_tree_print(node->left, a + 1);
}
