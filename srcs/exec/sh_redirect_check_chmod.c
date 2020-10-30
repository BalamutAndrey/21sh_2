/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_redirect_check_chmod.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 15:06:19 by geliz             #+#    #+#             */
/*   Updated: 2020/10/30 17:59:10 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

char	*sh_redirect_error_find_dir(t_main *main, t_redirect *new)
{
	int			i;
	char		*ret;

	i = ft_strlen(new->filename);
	while (i != 0 && new->filename[i] != '/')
		i--;
	if (i == 0)
		ret = sh_strdup(main->dir, main);
	else
		ret = sh_strsub(new->filename, 0, i, main);
	return (ret);
}

void	sh_redirect_less_error_check(t_main *main, t_redirect *new)
{
	char		*dir;
	struct stat	buff;
	
	dir = sh_redirect_error_find_dir(main, new);
	if (access(dir, F_OK) != 0)
		new->error = -3;
	if (new->error == 0)
		lstat(dir, &buff);
	if (new->error == 0 && !S_ISLNK(buff.st_mode) && !S_ISDIR(buff.st_mode))
		new->error = -1;
	if (new->error == 0 && S_ISLNK(buff.st_mode))
		stat(dir, &buff);
	if (new->error == 0 && !S_ISDIR(buff.st_mode))
		new->error = -1;
	if (new->error == 0 && !(buff.st_mode & S_IXUSR) &&
		!(buff.st_mode & S_IXGRP) && !(buff.st_mode & S_IXOTH))
		new->error = -2;
	if (new->error == 0 && access(new->filename, F_OK) != 0)
		new->error = -3;
	if (new->error == 0)
		lstat(new->filename, &buff);
	if (new->error == 0 && !S_ISLNK(buff.st_mode) && !S_ISREG(buff.st_mode))
		new->error = -4;
	if (new->error == 0 && S_ISLNK(buff.st_mode))
		stat(new->filename, &buff);
	if (new->error == 0 && !(buff.st_mode & S_IRUSR) &&
		!(buff.st_mode & S_IRGRP) && !(buff.st_mode & S_IROTH))
		new->error = -2;
}

void	sh_redirect_check_chmod(t_main *main, t_redirect *new)
{
	if (new->type == LESS)
	{
		sh_redirect_less_error_check(main, new);
	}
}

/*
** errors:
** -1 -- Not a directory
** -2 -- Permission denied
** -3 -- No such file or directory
** -4 -- Not a file or link
*/