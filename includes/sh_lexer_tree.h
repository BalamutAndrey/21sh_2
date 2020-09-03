/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_tree.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:20:14 by eboris            #+#    #+#             */
/*   Updated: 2020/09/03 18:25:47 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_LEXER_TREE_H
# define SH_LEXER_TREE_H

/*
** sh_lexer_tree.c
*/

/*
** sh_complete_command.c
*/
t_node	*sh_complete_command(t_main *main);
t_node	*sh_complete_command_list_separator(t_main *main);
t_node	*sh_complete_command_list(t_main *main);

/*
** sh_list.c
*/
t_node	*sh_list(t_main *main);
t_node	*sh_list_separatorop_andor(t_main *main);
t_node	*sh_list_andor(t_main *main);

/*
** sh_and_or.c
*/
t_node	*sh_andor(t_main *main);
t_node	*sh_andor_pipeline(t_main *main);
t_node	*sh_andor_andor_andif_linebreak_pipeline(t_main *main);
t_node	*sh_andor_andor_orif_linebreak_pipeline(t_main *main);

/*
** sh_pipeline.c
*/
t_node	*sh_pipeline(t_main *main);
t_node	*sh_pipeline_pipesequence(t_main *main);
t_node	*sh_pipeline_bang_pipesequence(t_main *main);

/*
** sh_pipe_sequence.c
*/
t_node	*sh_pipesequence(t_main *main);
t_node	*sh_pipesequence_command(t_main *main);
t_node	*sh_pipesequence_pipesequence_pipe_linebreak_command(t_main *main);

/*
** sh_command.c
*/
t_node	*sh_command(t_main *main);
t_node	*sh_command_simplecommand(t_main *main);
t_node	*sh_command_compoundcommand(t_main *main);
t_node	*sh_command_compoundcommand_redirectlist(t_main *main);
t_node	*sh_command_functiondefinition(t_main *main);

#endif
