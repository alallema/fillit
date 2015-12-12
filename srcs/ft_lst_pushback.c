/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 13:51:33 by alallema          #+#    #+#             */
/*   Updated: 2015/12/10 12:57:11 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>
#include <stdio.h>

void		ft_lst_pushback(t_tetr **begin_list, char **data)
{
	t_tetr	*elem;
	char	c;

	c = 'B';
	elem = *begin_list;
	if (*begin_list == NULL)
		*begin_list = ft_create_elem(data, c);
	else
	{
		while (elem->next)
		{
			elem = elem->next;
			c++;
		}
		elem->next = ft_create_elem(data, c);
	}
}
