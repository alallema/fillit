/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 13:57:13 by alallema          #+#    #+#             */
/*   Updated: 2015/12/10 12:51:38 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>

t_tetr		*ft_create_elem(char **pattern, char letter)
{
	t_tetr	*elem;

	elem = (t_tetr*)malloc(sizeof(t_tetr));
	if (elem != NULL)
	{
		elem->letter = letter;
		elem->pattern = pattern;
		elem->next = NULL;
	}
	return (elem);
}
