/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pattern.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:57:48 by alallema          #+#    #+#             */
/*   Updated: 2015/12/17 17:58:28 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

int		**ft_check(int *pos, int **pattern, int j)
{
	int i;

	i = 0;
	while (pos[i] != 0 && i < 4)
		i++;
	if (i != 4)
		return (pattern);
	i = 0;
	while (i < 4)
	{
		pos[i] = pos[i] - 1;
		pattern[i][j] = pos[i];
		ft_putnbr(pattern[i][j]);
		i++;
	}
	ft_putchar('\n');
	ft_check(pos, pattern, j);
	return (pattern);
}

int		**ft_check_pattern(int **pattern)
{
	int i;
	int j;
	int *pos;

	j = 0;
	while (j < 2)
	{
		pos = (int *)malloc(sizeof(int) * 5);
		i = 0;
		while (i < 4)
		{
			pos[i] = pattern[i][j];
			i++;
		}
		j++;
		pattern = ft_check(pos, pattern, j);
	}
	return (pattern);
}
