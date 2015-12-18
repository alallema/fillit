/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:50:42 by alallema          #+#    #+#             */
/*   Updated: 2015/12/18 15:31:21 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

void    ft_print_list(t_tetr *tetr)
{
	int i;
	int j;
	
	while (tetr)
	{
		i = 0;
		while (i < 4)
		{
			j = 0;
			while (j < 2)
			{
				ft_putnbr(tetr->pattern[i][j]);
				j++;
			}
			ft_putchar('\n');
			i++;
		}
		ft_putchar(tetr->letter);
		ft_putchar('\n');
		tetr = tetr->next;
	}
}
