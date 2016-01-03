/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_dots.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/03 16:59:39 by schiad            #+#    #+#             */
/*   Updated: 2016/01/03 17:09:43 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nb_dots(char **tab)
{
	int i;
	int j;
	int dots;

	dots = 0;
	j = 0;
	while (tab[j])
	{
		i = 0;
		while (tab[j][i])
		{
			if (tab[j][i] == '.')
				dots++;
			i++;
		}
		j++;
	}
	return (dots);
}
