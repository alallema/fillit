/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:44:17 by schiad            #+#    #+#             */
/*   Updated: 2015/12/19 17:37:21 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	ft_remover(char **tab, t_tetr *tetr, int ty, int tx)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < 4)
	{
		y = tetr->pattern[i][0];
		x = tetr->pattern[i][1];
		tab[ty + y][tx + x] = '.';
		i++;
	}
}
