/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 16:38:41 by eboris            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/09/15 16:06:23 by eboris           ###   ########.fr       */
=======
/*   Updated: 2020/09/17 18:10:58 by geliz            ###   ########.fr       */
>>>>>>> 80722f1fc9a0992835af7c9b6dd39e44953d98ff
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LEXER_H
# define SH_LEXER_H

<<<<<<< HEAD
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
    char            *content;
    struct s_token	*next;
}                   t_token;

//
//      AST_TREE
//
typedef struct      s_node {
//    t_type          node_type;
    t_token         *token;
    struct s_node   *left;
    struct s_node   *right;
}                   t_node;

=======
>>>>>>> 80722f1fc9a0992835af7c9b6dd39e44953d98ff
/*
** sh_lexer.c
*/
int		sh_lexer(t_main *main);
int		sh_lexer_hub(t_main *main, t_token *token);
int		sh_check_end_of_token_position(char *str, int *io_nbr_flag);
int		sh_find_end_of_token(int i, char *str);
int		sh_is_whitespace_or_tab(char c);
/*
** sh_lexer_find_quotes.c
*/
int		sh_find_closing_single_quotes(int i, char *str);
int		sh_find_closing_double_quotes(int i, char *str);
/*
** sh_is_operator.c
*/
int		sh_is_operator(char *str);
int		sh_is_it_io_redirect_operator(char *str);
/*
** sh_check_and_add_token.c
*/
void	sh_check_type_and_add_token(t_token *token, char *str, int i, int io_nbr_flag);
void	sh_add_io_number_token(t_token *token, char *str, int i);
void	sh_add_newline_token(t_token *token);
void	sh_add_word_token(t_token *token, char *str, int i);
/*
**  sh_add_operator_token.c
*/
void	sh_add_operator_token(t_token *token, char *str, int i);
void	sh_add_operator_token_part_two(t_token *token, char *str, int i);
/*
** sh_token_struct.c
*/
t_token	*sh_new_token(int type, char *content, t_main *main);
void	sh_remove_token_list(t_token *token);

#endif
