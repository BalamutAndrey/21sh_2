/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_structs.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:26:51 by eboris            #+#    #+#             */
/*   Updated: 2020/10/15 18:44:44 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_STRUCTS_H
# define SH_STRUCTS_H

# define MAX_KS_LEN		256
# define MAX_DIR_LEN	256

typedef	struct			s_fds {
	int					nbr;
	struct s_fds		*next;
}						t_fds;

typedef struct			s_heredoc {
	char				*delim;
    char                *content;
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
    LESS,           // <
    GREAT,          // >
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

typedef struct		s_path
{
	char			*path;
	struct s_path	*next;
}					t_path;

typedef struct		s_hist
{
	char			*com;
	struct s_hist	*next;
	struct s_hist	*prev;
}					t_hist;

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

typedef struct      	s_redirect {
	int					io_num;
	t_type				type;
	char				*filename;
	struct s_redirect	*next;
}						t_redirect;

typedef struct      s_exec {
	char			*cmd;
	char			**argv;
	char			**env;
	t_redirect		*redir;
	bool			pipe;
	int				pipefd[2];
	struct s_exec	*next;
}					t_exec;

typedef struct	s_cursor
{
	uint64_t		line;
	uint64_t		simvol;
	struct s_cursor	*prev;
	struct s_cursor	*next;
}				t_cursor;

typedef struct		s_main
{
	char			*term_name;
	int64_t			fd;
	uint64_t		term_col;
	uint64_t		term_row;
	struct termios	t_start;
	struct termios	t_curr;
	char			**envp;
	char			**envp_curr;
	t_path			*path;
	t_hist			*hist;
	t_hist			*hist_curr;
	t_hist			*hist_end;
	char			*user;
	char			*home;
	char			*dir;
	char			*ks;
	char			*ks_temp;
	uint64_t		ks_len;
	uint64_t		ks_temp_len;
	uint64_t		cursor;
	uint64_t		cursor_line;
	uint64_t		cursor_curr;
	uint64_t		cursor_line_curr;
	bool			cursor_sel;
	uint64_t		cursor_sel_start;
	uint64_t		cursor_sel_end;
	char			*cursor_sel_text;
	char			*prompt;
	uint64_t		prompt_len;
	t_heredoc	    *heredoc;
    t_token			*token;
    t_token     	*token_curr;
    t_node      	*tree_first;
    t_node      	*tree_curr;
	t_exec			*exec_first;
	t_exec			*exec_curr;
	t_fds			*opfds;
	int				defio[3]; //на данный момент значения 0-1-2 принимает в ЭКЗЕКЕ
}					t_main;

/*
** sh_structs.c
*/
t_main				*sh_add_main_struct(char **env);
void				sh_copy_envp(t_main *main);
void				sh_write_struct(t_main *new);
void				sh_remove_struct(t_main **main);
// Добавить чистку енв при выходе!

/*
** sh_path.c
*/
void				sh_path(t_main *main);
void				sh_path_del(t_main *main);
t_path				*sh_path_write(char *param);
t_path				*sh_path_write_struct(t_path *prev, t_path **first, char *str);

#endif
