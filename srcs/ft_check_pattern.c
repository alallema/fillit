/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pattern.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:50:21 by alallema          #+#    #+#             */
/*   Updated: 2015/12/18 14:20:35 by alallema         ###   ########.fr       */
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
	k = 0;
	i = 0;
	while (j < 2)
	{
		i = 0;
		while (pattern[i][j] != 0 & i < 4)
			i++;
		if (i == 4)
		{
			while (k < 4)
			{
				pattern[k][j] = pattern[k][j] - 1;
				k++;
			}
		}
		else if (i != 4 && j == 1)
			return ;
		j++;
	}
	ft_check_pattern(pattern);
}
