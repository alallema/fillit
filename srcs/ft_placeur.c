/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:47:11 by schiad            #+#    #+#             */
/*   Updated: 2015/12/19 20:08:23 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int		ft_placeur(char **tab, t_tetr *tetr, int nb_tetr)
{
	int	y;
	int	x;
	int	placed;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (ft_check_place(tab, tetr, y, x))
			{
				placed = 1;
				ft_writer(tab, tetr, y, x);
				if (!tetr->next)
					return (placed);
				else
					if ((nb_tetr - 1) == (placed = ft_placeur(tab
									, tetr->next, nb_tetr - 1)))
						return (placed + 1);
				ft_remover(tab, tetr, y, x);
			}
			x++;
		}
		y++;
	}
	return (0);
}
