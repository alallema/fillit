/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pattern.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:50:21 by alallema          #+#    #+#             */
/*   Updated: 2015/12/20 14:55:10 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

void	ft_check_pattern(int **pattern)
{
	int i;
	int j;
	int k;

	j = 0;
	while (j < 2)
	{
		i = 0;
		k = 4;
		while (i < 4)
		{
			if (pattern[i][j] < k)
				k = pattern[i][j];
			i++;
		}
		if (k != 0)
		{
			i = 0;
			while (i < 4)
			{
				pattern[i][j] = (pattern[i][j] - k);
				i++;
			}
		}
		else if (i != 4 && j == 1)
			return ;
		j++;
	}
}
