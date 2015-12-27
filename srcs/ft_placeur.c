/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:47:11 by schiad            #+#    #+#             */
/*   Updated: 2015/12/27 17:28:01 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int		ft_placeur(char **tab, t_tetr *tetr, int nb_tetr)
{
	int	y;
	int	x;
	int	placed;

	y = -1;
	while (tab[++y])
	{
		x = -1;
		while (tab[y][++x])
		{
			if (ft_check_place(tab, tetr, y, x))
			{
				placed = 1;
				ft_writer(tab, tetr, y, x);
				if (tetr->next)
					if ((nb_tetr - 1) == (placed = ft_placeur(tab
									, tetr->next, nb_tetr - 1)))
						return (placed + 1);
				if (!tetr->next)
					return (placed);
				ft_remover(tab, tetr, y, x);
			}
		}
	}
	return (0);
}
