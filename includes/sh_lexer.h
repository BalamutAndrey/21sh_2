/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 16:38:41 by eboris            #+#    #+#             */
/*   Updated: 2020/09/05 18:47:16 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LEXER_H
# define SH_LEXER_H

typedef enum    e_type {
    NONE,
    COMPLETE_COMMAND,
    LIST,
    PIPELINE,
    AND_OR,
    COMMAND,
    CMDNAME,
    CMDSUFFIX,
    SEPARATOR,

    WORD,
    NEWLINE,
	IO_NUMBER,
	AND_IF,			// &&
	OR_IF,			// ||
	DSEMI,			// ;;
	DLESS,			// <<
	DGREAT,			// >>
	LESSAND,		// <&
	GREATAND,		// >&
	LESSGREAT,		// <>
	DLESSDASH,		// <<-
	CLOBBER,		// >|
	LBRACE,			// {
	RBRACE,			// }
	BANG			// !
}               t_type;


//
//      TOKEN
//
typedef struct      s_token {
    t_type          type;
    char*           content;
}                   t_token;

//
//      AST_TREE
//
typedef struct      s_node {
    t_type          node_type;
    t_token         *token;
    struct s_node   *left;
    struct s_node   *right;
}                   t_node;

int		sh_lexer(t_main *main);

int		ft_find_closing_single_quotes(int i, char *str);
int		ft_find_closing_double_quotes(int i, char *str);

int		ft_is_operator(char *str);

void	ft_check_type_and_add_token(t_list *data, char *str, int i, int io_nbr_flag);

#endif
