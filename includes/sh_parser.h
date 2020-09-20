/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_parser.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/05 16:06:56 by geliz             #+#    #+#             */
/*   Updated: 2020/09/20 18:45:41 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_PARSER_H
# define SH_PARSER_H

/*
** sh_parser.c
*/
void	sh_parser(t_main *main);
/*
** sh_check_quotes.c
*/
void	sh_check_quotes(t_main *main);
void	sh_check_dquotes(t_main *main);

void	sh_check_slash(t_main *main);
void	sh_check_heredoc(t_main *main);
int		sh_find_heredoc(t_main *main, int i);

#endif
