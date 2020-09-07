/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_io_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 16:42:30 by eboris            #+#    #+#             */
/*   Updated: 2020/09/07 16:51:47 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

/*
** io_file          : '<'       filename
**                  | LESSAND   filename
**                  | '>'       filename
**                  | GREATAND  filename
**                  | DGREAT    filename
**                  | LESSGREAT filename
**                  | CLOBBER   filename
**
** !!! DGREAT, LESSGREAT and CLOBBER -- in file sh_io_file_greats.c !!!
*/

t_node	*sh_iofile(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	if ((temp = sh_iofile_greatleft_filename(main)) != NULL)
		return (temp);
	else if ((temp = sh_iofile_lessand_filename(main)) != NULL)
		return (temp);
	else if ((temp = sh_iofile_greatright_filename(main)) != NULL)
		return (temp);
	else if ((temp = sh_iofile_greatand_filename(main)) != NULL)
		return (temp);
	else if ((temp = sh_iofile_dgreat_filename(main)) != NULL)
		return (temp);
	else if ((temp = sh_iofile_lessgreat_filename(main)) != NULL)
		return (temp);
	else if ((temp = sh_iofile_clobber_filename(main)) != NULL)
		return (temp);
	return (NULL);
}

/*
** io_file          : '<'       filename
*/

t_node	*sh_iofile_greatleft_filename(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}

/*
** io_file          : LESSAND   filename
*/

t_node	*sh_iofile_lessand_filename(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}

/*
** io_file          : '>'       filename
*/

t_node	*sh_iofile_greatright_filename(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}

/*
** io_file          : GREATAND  filename
*/

t_node	*sh_iofile_greatand_filename(t_main *main)
{
	t_node	*temp;

	temp = NULL;
	return (NULL);
}
