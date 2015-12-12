/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:29:29 by alallema          #+#    #+#             */
/*   Updated: 2015/12/12 20:15:50 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

char	*ft_check_str(char *s)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (i % 5 == 0 && s[i] != '\n')
			return (NULL);
		if (s[i] == '#')
			n++;
		i++;
	}
	if (n != 4)
		return (NULL);
	return (s);
}

int		ft_check_pos(char **tab, int x, int y, int ret)
{
	if (ret == 1)
		return (1);
	if (tab[x][y + 1] == '#' && y < 4)
		ft_check_pos(tab, x, y, ret + 1);
	if (tab[x + 1][y] == '#' && x < 4)
		ft_check_pos(tab, x, y, ret + 1);
	if (tab[x][y - 1] == '#' && y != 0)
		ft_check_pos(tab, x, y, ret + 1);
	if (tab[x - 1][y] == '#' && x != 4)
		ft_check_pos(tab, x, y, ret + 1);
	return (0);
}

char	**ft_create_tab(char **tab)
{
	int	i;
	int	j;
	int	pattern[2][4];
	int x;
	int y;

	i = 0;
	j = 0;
	x = 0;
	y = 0;
	while (tab[i][j] && i < 4)
	{
		if (tab[i][j] == '#')
		{
			if (ft_check_pos(tab, i, j, 0) == 0)
			{
				tab[0] = NULL;
				return (NULL);
			}
			pattern[x][y] = j;
			y++;
			pattern[x][y] = x;
			x++;
		}
		if (j == 4)
			i++;
		j++;
	}
	return (pattern);
}

char    **ft_create(char *str)
{
	char*s;
	char **tab;
	int i;

	i = 0;
	s = ft_strdup(str);
	while (s[i] && i < 20)
		i++;
	s[i] = '\0';
	s = ft_check_str(s);
	tab = ft_strsplit(s, '\n');
	tab = ft_create_tab(tab);
	return (tab);
}

t_tetr		*ft_check_tetr(char *s, int n)
{
	int		i;
	t_tetr	tetr;

	i = 0;
	while (s[i])
	{
		if (i % 21 == 0 && s[i] != '\n')
			return (NULL);
		i++;
	}
	while (s[i] && i < n)
	{
		if (i == 0)
			tetr = ft_create_elem(ft_create(&s[i]), 'A');
		if (i % 21 == 0 && i != 20 && i != 0)
		{
			ft_lst_pushback(&tetr, ft_create(&s[i]));
		}
		i++;
	}
	ft_print_list(tetr);
	return (tetr);
}
