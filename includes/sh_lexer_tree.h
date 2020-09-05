/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_lexer_tree.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 17:20:14 by eboris            #+#    #+#             */
/*   Updated: 2020/09/05 18:38:21 by eboris           ###   ########.fr       */
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

/*
** sh_compound_command.c
*/
t_node	*sh_compoundcommand(t_main *main);
t_node	*sh_compoundcommand_bracegroup(t_main *main);
t_node	*sh_compoundcommand_subshell(t_main *main);

/*
** sh_compound_command_clause.c
*/
t_node	*sh_compoundcommand_forclause(t_main *main);
t_node	*sh_compoundcommand_caseclause(t_main *main);
t_node	*sh_compoundcommand_ifclause(t_main *main);
t_node	*sh_compoundcommand_whileclause(t_main *main);
t_node	*sh_compoundcommand_untilclause(t_main *main);

/*
** sh_subshell.c
*/
t_node	*sh_subshell(t_main *main);
t_node	*sh_subshell_bracket_compoundlist_bracket(t_main *main);

/*
** sh_compound_list.c
*/
t_node	*sh_compoundlist(t_main *main);
t_node	*sh_compoundlist_term(t_main *main);
t_node	*sh_compoundlist_newlinelist_term(t_main *main);
t_node	*sh_compoundlist_term_separator(t_main *main);
t_node	*sh_compoundlist_newlinelist_term_separator(t_main *main);

/*
** sh_term.c
*/
t_node	*sh_term(t_main *main);
t_node	*sh_term_term_separator_andor(t_main *main);
t_node	*sh_term_andor(t_main *main);

/*
** sh_for_clause.c
*/
t_node	*sh_forclause(t_main *main);
t_node	*sh_forclause_for_name_linebreak_dogroup(t_main *main);
t_node	*sh_forclause_for_name_linebreak_in_sequentialsep_dogroup(t_main *main);
t_node	*sh_forclause_for_name_linebreak_in_wordlist_sequentialsep_dogroup
	(t_main *main);

/*
** sh_name.c
*/
t_node	*sh_name(t_main *main);
t_node	*sh_name_name(t_main *main);

/*
** sh_in.c
*/
t_node	*sh_in(t_main *main);
t_node	*sh_in_in(t_main *main);

/*
** sh_wordlist.c
*/
t_node	*sh_wordlist(t_main *main);
t_node	*sh_wordlist_wordlist_word(t_main *main);
t_node	*sh_wordlist_word(t_main *main);

/*
** sh_case_clause.c
*/
t_node	*sh_caseclause(t_main *main);
t_node	*sh_caseclause_case_word_linebreak_in_linebreak_caselist_esac
	(t_main *main);
t_node	*sh_caseclause_case_word_linebreak_in_linebreak_caselistns_esac
	(t_main *main);
t_node	*sh_caseclause_case_word_linebreak_in_linebreak_esac(t_main *main);

/*
** sh_case_list_ns.c
*/
t_node	*sh_caselistns(t_main *main);
t_node	*sh_caselistns_caselist_caseitemns(t_main *main);
t_node	*sh_caselistns_caseitemns(t_main *main);

/*
** sh_case_list.c
*/
t_node	*sh_caselist(t_main *main);
t_node	*sh_caselist_caselist_caseitem(t_main *main);
t_node	*sh_caselist_caseitem(t_main *main);

/*
** sh_case_item_ns.c
*/
t_node	*caseitemns(t_main *main);
t_node	*caseitemns_pattern_bracket_linebreak(t_main *main);
t_node	*caseitemns_pattern_bracket_compoundlist_linebreak(t_main *main);
t_node	*caseitemns_bracket_pattern_bracket_linebreak(t_main *main);
t_node	*caseitemns_bracket_pattern_bracket_compoundlist_linebreak
	(t_main *main);

/*
** sh_case_item.c
*/
t_node	*sh_caseitem(t_main *main);
t_node	*sh_caseitem_pattern_bracket_linebreak_dsemi_linebreak(t_main *main);
t_node	*sh_caseitem_pattern_bracket_compoundlist_dsemi_linebreak(t_main *main);
t_node	*sh_caseitem_bracket_pattern_bracket_linebreak_dsemi_linebreak
	(t_main *main);
t_node	*sh_caseitem_bracket_pattern_bracket_compoundlist_dsemi_linebreak
	(t_main *main);

/*
** sh_pattern.c
*/
t_node	*sh_pattern(t_main *main);
t_node	*sh_pattern_word(t_main *main);
t_node	*sh_pattern_pattern_pipe_word(t_main *main);

#endif
