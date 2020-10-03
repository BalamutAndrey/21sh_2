/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:36:57 by geliz             #+#    #+#             */
/*   Updated: 2020/10/03 15:32:54 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

t_redirect	*temp_create_redir_list(void)
{
	t_redirect	*new;
	t_redirect	*first;

	first = ft_memalloc(sizeof(t_redirect));
	first->io_num = 1;
	first->type = GREAT;
//	first->filename = ft_strdup("Here is heredoc content :)\nmuch more\nii");
	first->filename = ft_strdup("../test_here/POWER_OEW_1");
	new = ft_memalloc(sizeof(t_redirect));
	first->next = new;
	new->io_num = 1;
	new->type = GREAT;
	new->filename = ft_strdup("../test_here/POWER_OEW_2");
	new->next = ft_memalloc(sizeof(t_redirect));
	new = new->next;
	new->io_num = 1;
	new->type = DGREAT;
	new->filename = ft_strdup("../test_here/POWER_OEW_3");
	return (first);
}

void	temp_exec(void)
{
	int		cpid;
	char	*t[] = {"/bin/ls", NULL};
	char	*y[] = {"/bin/cat", "poqewooqweoqweoqoeq", NULL};

	cpid = fork();
	if (cpid == 0)
	{
		execv(t[0], t);
	}
/*	else
	{
		cpid = fork();
		if (cpid == 0)
			execv(y[0], y);
	}*/
}

void	sh_add_opened_fd(t_main *main, int nbr)
{
	t_fds	*last;
	
	if (!main->opfds)
	{
		main->opfds = ft_memalloc(sizeof(t_fds));
		main->opfds->nbr = nbr;
		main->opfds->next = NULL;
	}
	else
	{
		last = main->opfds;
		while (last->next)
			last = last->next;
		last->next = ft_memalloc(sizeof(t_fds));
		last->next->nbr = nbr;
		last->next->next = NULL;
		last = NULL;
	}
}

void	sh_redirect_from_heredoc(t_redirect *new, t_main *main)
{
	ft_fprintf(new->io_num, "%s", new->filename);
}

void	sh_set_default_io_value(t_main *main)
{
	main->defio[0] = 0;
	main->defio[1] = 1;
	main->defio[2] = 2;
}

void	sh_exec(t_main *main)
{
	t_redirect	*new;

	sh_set_default_io_value(main);
	new = temp_create_redir_list();
	while (new)
	{
		if (new->type == GREAT)
			sh_redirect_to_file(new, main);
		else if (new->type == GREATAND)
			sh_redirect_to_ionumber(new, main);
		else if (new->type == DGREAT)
			sh_redirect_to_file_append(new, main);
		else if (new->type == LESS)
			sh_redirect_from_file(new, main);
		else if (new->type == DLESS)
			sh_redirect_from_heredoc(new, main);
//		else if (new->type == LESSAND)
//			sh_redirect_from_ionumber(new, main);
		new = new->next;
	}
	temp_exec();
}
