/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:26:51 by eboris            #+#    #+#             */
/*   Updated: 2020/09/20 17:46:49 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_STRUCTS_H
# define SH_STRUCTS_H

typedef struct			s_heredoc {
	int					str_end;
	char				*delim;
	int					delim_start;
	int					here_start;
	int					here_end;
	struct s_heredoc	*next;
}						t_heredoc;

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
    struct s_token	*next;
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

typedef struct	s_main
{
    char		*ks;
    char        *prompt;
	t_heredoc	*heredoc;
    t_token		*token;
    t_token     *token_curr;
    t_node      *tree_first;
    t_node      *tree_curr;
}				t_main;

#endif
