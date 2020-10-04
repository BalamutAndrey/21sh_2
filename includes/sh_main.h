/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/03 15:57:23 by eboris            #+#    #+#             */
/*   Updated: 2020/10/04 17:27:27 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_MAIN_H
# define SH_MAIN_H

# include <unistd.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include <stdint.h>
# include <termios.h>
# include <term.h>
# include <fcntl.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include "libft.h"
# include "sh_structs.h"
# include "sh_errors.h"
# include "sh_keys.h"
# include "sh_signal.h"
# include "sh_func.h"
# include "sh_read.h"
# include "sh_signal.h"
# include "sh_term.h"
# include "sh_parser.h"
# include "sh_lexer.h"
# include "sh_lexer_tree.h"
# include "sh_lexer_exec.h"
# include "sh_exec.h"

#endif
