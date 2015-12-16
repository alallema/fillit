/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:50:42 by alallema          #+#    #+#             */
/*   Updated: 2015/12/16 18:58:42 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

void    ft_print_list(t_tetr *tetr)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (tetr)
	{
		while (tetr->pattern[i] && i < 5)
		{
			while (j < 3)
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
		i = 0;
	}
}
