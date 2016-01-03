/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:05:09 by schiad            #+#    #+#             */
/*   Updated: 2016/01/03 19:50:48 by schiad           ###   ########.fr       */
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
	while (retour && (dots > (1 + (2 * i))))
	{
		i--;
		ft_putnbr(i);
		ft_putchar('\n');
		ft_square_char_filler(tab, i);
		retour = ft_placeur(tab, tetr, nb);
		ft_print_result(tab);
		dots = ft_nb_dots(tab);
		ft_putnbr(dots);
		ft_putchar('\n');
		ft_putstr("end\n");
	}
	if (!retour)
		i++;
	ft_square_char_filler(tab, i);
	ft_placeur(tab, tetr, nb);
	ft_print_result(tab);
	ft_free_square(tab);
	ft_free_elements(tetr);
}
