/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_char_filler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:25:21 by schiad            #+#    #+#             */
/*   Updated: 2016/01/03 16:46:05 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

void		ft_square_char_filler(char **tab, int nb)
{
	int		j;
	char	*tmp;

	j = 34;
	while (j)
	{
		j--;
		ft_bzero(tab[j], 33);
	}
	tmp = (char *)malloc(sizeof(char) * (nb + 1));
	ft_strncpy(tmp, ".................................", nb);
	tmp[nb] = '\n';
	tmp[nb + 1] = '\0';
	while (j < nb)
	{
		ft_strcpy(tab[j], tmp);
		j++;
	}
	free(tmp);
}
