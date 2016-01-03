/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:05:09 by schiad            #+#    #+#             */
/*   Updated: 2016/01/03 16:52:45 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

void		ft_resolver(t_tetr *tetr, int nb)
{
	char	**tab;
	int		i;
	int		retour;

	retour = 1;
	tab = ft_square_char_tab(33);
	i = 33;
	while (retour)
	{
		i--;
		ft_putnbr(i);
		ft_putchar('\n');
		ft_square_char_filler(tab, i);
		retour = ft_placeur(tab, tetr, nb);
		ft_print_result(tab);
	}
	if (!retour)
		i++;
	ft_square_char_filler(tab, i);
	ft_placeur(tab, tetr, nb);
	ft_print_result(tab);
	ft_free_square(tab);
	ft_free_elements(tetr);
}
