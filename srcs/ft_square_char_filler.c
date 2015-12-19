/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_char_filler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:25:21 by schiad            #+#    #+#             */
/*   Updated: 2015/12/19 13:50:09 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	ft_square_char_filler(char **tab, int nb)
{
	int	j;

	tmp = (char *)malloc(sizeof(char) * (i + 1));
	ft_strncpyendl(tmp, ".................................", i);
	j = 0;
	while (j < nb)
	{
		ft_strcpy(tab[j], tmp);
		j++;
	}
	free(tmp);
}
