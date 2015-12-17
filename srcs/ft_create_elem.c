/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 13:57:13 by alallema          #+#    #+#             */
/*   Updated: 2015/12/17 12:18:56 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>

t_tetr		*ft_create_elem(int **pattern, char letter)
{
	t_tetr	*elem;

	elem = (t_tetr*)malloc(sizeof(t_tetr));
	if (pattern == NULL)
		return (NULL);
	if (elem != NULL)
	{
		elem->letter = letter;
		elem->pattern = pattern;
		elem->next = NULL;
	}
	return (elem);
}
