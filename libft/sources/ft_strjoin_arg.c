/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geliz <geliz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 14:07:59 by geliz             #+#    #+#             */
/*   Updated: 2020/01/18 14:53:11 by geliz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_arg(const char *s, ...)
{
	char	*ret;
	va_list	ap;
	int		i;
	char	*temp;
	char	*temp_ret;

	i = 0;
	ret = NULL;
	va_start(ap, s);
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			temp = va_arg(ap, char *);
			temp_ret = ft_strjoin(ret, temp);
			ft_strdel(&ret);
			ret = temp_ret;
			if (s[++i] == 'f')
				ft_strdel(&temp);
		}
		i++;
	}
	va_end(ap);
	return (ret);
}
