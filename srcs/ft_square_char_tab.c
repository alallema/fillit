/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_char_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:22:54 by schiad            #+#    #+#             */
/*   Updated: 2015/12/19 17:40:07 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <main.h>

char	**ft_square_char_tab(int nb)
{
	char	**tab;
	int		i;

	tab = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < nb)
	{
		tab[i] = ft_strnew(nb + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
