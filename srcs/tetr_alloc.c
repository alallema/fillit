/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetr_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:16:00 by alallema          #+#    #+#             */
/*   Updated: 2015/12/09 15:13:06 by rpallies         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int			*fill_line(char *str, t_tetr tetr, int i)
{
	int		line[4];

	line = {0, 0, 0, 0};
	while (str[i - 1] != '\n' && str[i])
	{
		t_tetr.pattern[i] = str[i];
		i++;
	}
}

t_tetr		tetr_alloc(char *str)
{
	int			i;
	t_tetr		tetr;

	i = 0;
	tetr = (t_tetr)malloc(sizeof(t_tetr));
	tetr.pattern = (char*)malloc(sizeof(char) * 21);
}
