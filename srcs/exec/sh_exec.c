/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 16:29:08 by geliz             #+#    #+#             */
/*   Updated: 2020/10/03 18:20:59 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	temp_fill_exec2(t_exec *tmp, char **argv, bool pipe)
{
	tmp->cmd = argv[0];
	tmp->argv = argv;
	tmp->env = NULL;
	tmp->redir = NULL;
	tmp->pipe = pipe;
	tmp->next = NULL;
}

void	temp_add_redirection(t_exec *exec, int io, t_type type, char *filename)
{
	t_redirect	*red;

	if (!exec->redir)
	{
		exec->redir = ft_memalloc(sizeof(t_redirect));
		red = exec->redir;
	}
	else
	{
		red = exec->redir;
		while (red->next)
			red = red->next;
		red->next = ft_memalloc(sizeof(t_redirect));
		red = red->next;
	}
	red->io_num = io;
	red->type = type;
	red->filename = filename;
}


/*
чистить фдшники после каждой команды, проверить с редиректом в начале и середине!!!
на данный момент при редиректе в начале не работает
*/
t_exec	*temp_fill_exec(void)
{
	t_exec	*first;
	t_exec	*tmp;
	
	tmp = ft_memalloc(sizeof(t_exec));
	first = tmp;
	temp_fill_exec2(tmp, ft_strsplit("/bin/ls -la", ' '), false);
	tmp->next = ft_memalloc(sizeof(t_exec));
	tmp = tmp->next;
	temp_fill_exec2(tmp, ft_strsplit("/usr/bin/grep o", ' '), true);
	tmp->next = ft_memalloc(sizeof(t_exec));
	tmp = tmp->next;
	temp_fill_exec2(tmp, ft_strsplit("/usr/bin/grep der", ' '), true);
	tmp->next = ft_memalloc(sizeof(t_exec));
	tmp = tmp->next;
	temp_fill_exec2(tmp, ft_strsplit("/usr/bin/wc -c", ' '), true);
	tmp->next = ft_memalloc(sizeof(t_exec));
	tmp = tmp->next;
	temp_fill_exec2(tmp, ft_strsplit("/usr/bin/sum", ' '), true);
//	temp_add_redirection(tmp, 1, GREAT, "../test_here/NEW_FILE");
	temp_add_redirection(tmp, 1, DGREAT, "../test_here/NEW_FILE");
	return (first);
}

void	sh_standart_exec(t_exec *exec, t_main *main)
{
	execv(exec->argv[0], exec->argv);
}

void	sh_exec(t_main *main)
{
	t_exec	*exec;

	exec = temp_fill_exec();//тут должно быть exec = main->exec, но его пока нет
	while (exec)
	{
		if (exec->redir)
			sh_redirects_hub(exec, main);
		if (exec->pipe == true || (exec->next && exec->next->pipe == true))
			sh_exec_piped_commands(exec, main);
		else
			sh_standart_exec(exec, main);
		exec = exec->next;
	}
}