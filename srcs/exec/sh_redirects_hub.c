/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_redirects_hub.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:36:57 by geliz             #+#    #+#             */
/*   Updated: 2020/10/11 16:00:54 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

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
	ft_printf("Doesn't work yet =(\n");
//	ft_fprintf(fd[1], "%s", new->filename);
}

void	sh_set_default_io_value(t_main *main)
{
	main->defio[0] = 0;
	main->defio[1] = 1;
	main->defio[2] = 2;
}

void	sh_redirects_hub(t_exec *exec, t_main *main)
{
	t_redirect	*new;

	sh_set_default_io_value(main);
	new = exec->redir;
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
}
