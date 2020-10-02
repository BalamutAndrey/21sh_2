/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 17:36:57 by geliz             #+#    #+#             */
/*   Updated: 2020/10/02 19:18:08 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_add_opened_fd(t_main *main, int nbr);
void	sh_redirect_to_file(t_redirect *new, t_main *main);

t_redirect	*temp_create_redir_list(void)
{
	t_redirect	*new;
	t_redirect	*first;

	first = ft_memalloc(sizeof(t_redirect));
	first->io_num = 1;
	first->type = GREAT;
	first->filename = ft_strdup("POWER_OEW");
//	first->filename = ft_strdup("TEMP_REDIRECT_FILE");
	first->next = NULL;
	return (first);
}

void	sh_redirect_to_ionumber(t_redirect *new, t_main *main)
{
	int		i;
	int		fd;

	i = 0;
	if (ft_strcmp("-", new->filename) == 0)
		close(new->io_num);
	else if (ft_isdigit(new->filename[i] == 1))
	{	
		while (ft_isdigit(new->filename[i]) == 1)
			i++;
	}
	if (new->filename[i] == '\0')
	{
		{
			fd = ft_atoi(new->filename);
			sh_add_opened_fd(main, fd);
			dup2(fd, new->io_num);
		}
	}
	else
		sh_redirect_to_file(new, main);
	// сильно туплю, перепиши всё это утром!!! :)
}

void	sh_redirect_to_file(t_redirect *new, t_main *main)
{
	int		fd;

	//sh_check_directory_chmod(new->filename) STAT/LSTAT директорию, где будет файл, куда идет редир, да и сам файл
	fd = open(new->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	sh_add_opened_fd(main, fd);
	dup2(fd, new->io_num);
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

void	temp_exec(void)
{
	int		cpid;
	char	*t[] = {"/bin/ls", NULL};

	cpid = fork();
	if (cpid == 0)
	{
		execv(t[0], t);
	}
}

void	sh_exec(t_main *main)
{
	t_redirect	*new;

	new = temp_create_redir_list();
	while (new)
	{
		if (new->type == GREAT)
			sh_redirect_to_file(new, main);
		else if (new->type == GREATAND)
			sh_redirect_to_ionumber(new, main);
		new = new->next;
	}
	temp_exec();
}
