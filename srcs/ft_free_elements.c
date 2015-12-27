/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 17:07:12 by schiad            #+#    #+#             */
/*   Updated: 2015/12/27 17:20:59 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <main.h>

void	ft_free_elements(t_tetr *elem)
{
	t_tetr	*next;

	next = elem->next;
	free(elem);
	if (next)
		ft_free_elements(next);
}
