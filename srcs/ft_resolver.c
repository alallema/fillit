/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:05:09 by schiad            #+#    #+#             */
/*   Updated: 2015/12/19 17:33:27 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void		ft_resolver(t_tetr *tetr, int nb)
{
	char	**tab;
	int		i;
	int		retour;

	retour = 0;
	tab = ft_square_char_tab(33);
	i = 1;
	while (!retour)
	{
		ft_square_char_filler(tab, i);
		retour = ft_placeur(tab, tetr, nb);
		i++;
	}
	ft_print_result(tab);
	ft_free_square(tab);
}
