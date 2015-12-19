/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_clace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:45:29 by schiad            #+#    #+#             */
/*   Updated: 2015/12/19 17:35:35 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int		ft_check_place(char **tab, t_tetr *tetr, int ty, int tx)
{
	int	placeable;
	int	x;
	int	y;
	int	i;

	placeable = 1;
	i = 0;
	while (i < 4 && placeable)
	{
		y = tetr->pattern[i][0];
		x = tetr->pattern[i][1];
		if (tab[ty + y][tx + x] != '.')
			placeable = 0;
		i++;
	}
	return (placeable);
}
