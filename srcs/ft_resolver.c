/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:05:09 by schiad            #+#    #+#             */
/*   Updated: 2016/01/07 10:46:30 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

void		ft_resolver(t_tetr *tetr, int nb)
{
	char	**tab;
	int		i;
	int		retour;
	int		dots;

	retour = 1;
	dots = 999;
	tab = ft_square_char_tab(33);
	i = 30;
	while (retour && dots > ((i * 2) - 2))
	{
		i--;
		ft_square_char_filler(tab, i);
		retour = ft_placeur(tab, tetr, nb);
		dots = ft_nb_dots(tab);
	}
	if (!retour)
		i++;
	ft_square_char_filler(tab, i);
	ft_placeur(tab, tetr, nb);
	ft_print_result(tab);
	ft_free_square(tab);
	ft_free_elements(tetr);
}
