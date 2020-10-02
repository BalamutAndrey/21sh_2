/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:06:56 by geliz             #+#    #+#             */
/*   Updated: 2020/10/02 15:34:25 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_PARSER_H
# define SH_PARSER_H

/*
** sh_parser.c
*/
bool	sh_lexer_start(t_main *main);
void	sh_parser(t_main *main);
/*
** sh_check_quotes.c
*/
void		sh_check_quotes(t_main *main);
void		sh_check_dquotes(t_main *main);
/*
** sh_parser_slash.c
*/
void		sh_check_slash(t_main *main);
/*
** sh_parcer_heredoc.c
*/
void		sh_check_heredoc(t_main *main);
int			sh_is_heredoc_finished(t_main *main);
void		sh_get_heredoc_content(t_main *main);
/*
** sh_parser_heredoc_struct.c
*/
void		sh_create_heredoc_structs(t_main *main);
t_heredoc	*sh_create_heredoc_list(int i);
int			sh_find_heredoc(t_main *main, int i);
void		sh_get_heredoc_info(t_main *main, t_heredoc *here);

#endif
