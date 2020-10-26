/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/26 17:43:11 by eboris            #+#    #+#             */
/*   Updated: 2020/10/26 17:50:08 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char    *sh_exec_builtin(t_exec *exec, t_main *main)
{
    char    *finish;

    finish = NULL;
    if ((ft_strncmp(exec->argv[0], "cd ", 3) == 0) ||
		(ft_strncmp(exec->argv[0], "cd\0", 3) == 0))
        {
            finish = sh_cd(exec, main);
        }
    return (finish);
}