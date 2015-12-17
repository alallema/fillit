/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 13:51:33 by alallema          #+#    #+#             */
/*   Updated: 2015/12/17 12:13:30 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <stdlib.h>
#include <libft.h>

void		ft_lst_pushback(t_tetr **begin_list, int **data)
{
	t_tetr	*elem;
	char	c;

	c = 'B';
	elem = *begin_list;
	if (data == NULL)
		*begin_list = NULL;
	if (*begin_list != NULL)
	{
		while (elem->next)
		{
			elem = elem->next;
			c++;
		}
		elem->next = ft_create_elem(data, c);
	}
}
