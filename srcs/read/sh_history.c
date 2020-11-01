/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_history.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eboris <eboris@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/11 13:49:25 by eboris            #+#    #+#             */
/*   Updated: 2020/11/01 19:26:55 by eboris           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_main.h"

void	sh_history_add(t_main *main)
{
	if (main->ks[0] != '\0')
	{
		sh_history_newlist(main);
		main->hist_end->prev->com = ft_strdup(main->ks);
	}
}

void	sh_history_create(t_main *main)
{
	t_hist	*new;
	t_hist	*end;

	new = malloc(sizeof(t_hist));
	end = malloc(sizeof(t_hist));
	new->com = NULL;
	end->com = NULL;
	new->next = end;
	new->prev = NULL;
	end->next = NULL;
	end->prev = new;
	main->hist = new;
	main->hist_curr = end;
	main->hist_end = end;
}

void	sh_history_newlist(t_main *main)
{
	t_hist	*new;
	t_hist	*temp;

	temp = main->hist_end->prev;
	new = malloc(sizeof(t_hist));
	new->com = NULL;
	new->next = main->hist_end;
	new->prev = temp;
	temp->next = new;
	main->hist_end->prev = new;
	main->hist_curr = main->hist_end;
}

void	sh_history_read(t_main *main, char k)
{
	if ((main->ks != NULL) && (main->ks_temp == NULL))
	{
		main->ks_temp = ft_strdup(main->ks);
	}
	if (k == 'u')
	{
		if (main->hist_curr->prev != NULL)
		{
			main->hist_curr = main->hist_curr->prev;
			if (main->hist_curr->com != NULL)
			{
				ft_bzero(main->ks, MAX_KS_LEN);
				ft_strcpy(main->ks, main->hist_curr->com);
				main->ks_len = ft_strlen(main->ks);
				main->cursor = main->ks_len;
				//
				//sh_cursor_math(main);
				sh_reprint_ks(main);
			}
			else
			{
				main->hist_curr = main->hist_curr->next;
			}
		}
	}
	else if (k == 'd')
	{
		if (main->hist_curr->next != NULL)
		{
			main->hist_curr = main->hist_curr->next;
			if ((main->hist->prev != NULL) && (main->hist->prev->com == NULL) && (main->hist->next != NULL))
				main->hist_curr = main->hist_curr->next;
			if (main->hist_curr->com != NULL)
			{
				ft_bzero(main->ks, MAX_KS_LEN);
				ft_strcpy(main->ks, main->hist_curr->com);
				main->ks_len = ft_strlen(main->ks);
				main->cursor = main->ks_len;
				//
				//sh_cursor_math(main);
				sh_reprint_ks(main);
			}
			else
			{
				if (main->ks_temp == NULL)
				{
					ft_bzero(main->ks, MAX_KS_LEN);
					main->ks_len = 0;
					main->cursor = 0;
					sh_reprint_ks(main);
				}
				else
				{
					ft_bzero(main->ks, MAX_KS_LEN);
					ft_strcpy(main->ks, main->ks_temp);
					main->ks_len = ft_strlen(main->ks);
					main->cursor = main->ks_len;
					//
					//sh_cursor_math(main);
					sh_reprint_ks(main);
				}
			}
		}
	}
	if (main->ks_temp)
		ft_strdel(&main->ks_temp);
}

// Лишняя функция
void	sh_history_delete(t_main *main)
{
	if (main->hist != NULL)
	{
		main->hist_curr = main->hist;
		while(main->hist_curr != NULL)
		{
			main->hist = main->hist_curr->next;
			if (main->hist_curr->com != NULL)
			{
				ft_strdel(&main->hist_curr->com);
			}
			free(main->hist_curr);
			main->hist_curr = main->hist;
		}
	}
}
