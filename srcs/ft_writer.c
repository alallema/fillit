/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:42:25 by schiad            #+#    #+#             */
/*   Updated: 2015/12/19 13:44:01 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_writer(char **tab, t_tetr *tetr, int ty, int tx)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < 4)
	{
		y = tetr->pattern[i][0];
		x = tetr->pattern[i][1];
		tab[ty + y][tx + x] = tetr->letter;
		i++;
	}
}
