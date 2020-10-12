/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_redirects.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 15:25:36 by geliz             #+#    #+#             */
/*   Updated: 2020/10/12 17:34:00 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_redirect_to_ionumber(t_redirect *new, t_main *main)
{
	int		i;
	int		fd;

	i = 0;
	if (ft_strcmp("-", new->filename) == 0)
		close(new->io_num);
	else if (ft_isdigit(new->filename[i]) == 1)
	{	
		while (ft_isdigit(new->filename[i]) == 1)
			i++;
		if (new->filename[i] == '\0')
		{
			{
				fd = ft_atoi(new->filename);
				sh_add_opened_fd(main, fd);
				dup2(fd, new->io_num);
				if (new->io_num == 1 || new->io_num == 2)
					main->defio[new->io_num] = fd;
			}
		}
	}
	else
		sh_redirect_to_file(new, main);
}

void	sh_redirect_to_file(t_redirect *new, t_main *main)
{
	int		fd;

	//sh_check_directory_chmod(new->filename) STAT/LSTAT директорию, где будет файл, куда идет редир, да и сам файл
	fd = open(new->filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	sh_add_opened_fd(main, fd);
	dup2(fd, new->io_num);
	if (new->io_num == 1 || new->io_num == 2)
		main->defio[new->io_num] = fd;
}

void	sh_redirect_to_file_append(t_redirect *new, t_main *main)
{
	int		fd;
	
	//sh_check_directory_chmod(new->filename) STAT/LSTAT директорию, где будет файл, куда идет редир, да и сам файл
	fd = open(new->filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
	sh_add_opened_fd(main, fd);
	dup2(fd, new->io_num);
	if (new->io_num == 1 || new->io_num == 2)
		main->defio[new->io_num] = fd;
}

void	sh_redirect_from_file(t_redirect *new, t_main *main)
{
	int		fd;

	//sh_check_directory_chmod(new->filename) STAT/LSTAT директорию, где будет файл, куда идет редир, да и сам файл
	fd = open(new->filename, O_RDONLY);
	sh_add_opened_fd(main, fd);
	dup2(fd, new->io_num);
	if (new->io_num == 0)
		main->defio[new->io_num] = fd;
}

void	sh_redirect_from_ionumber(t_redirect *new, t_main *main)
{
	//разобраться, как это вообще работает и зачем?....
}
