/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:29:29 by alallema          #+#    #+#             */
/*   Updated: 2015/12/17 12:23:19 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

int		ft_check_str(char *s)
{
	int	i;
	int	n;
	int n2;

	i = 0;
	n = 0;
	n2 = 0;
	while (s[i])
	{
		if ((i + 1) % 5 == 0 && s[i] != '\n' && i != 0)
			return (0);
		if (s[i] == '#')
			n++;
		if (s[i] == '.')
			n2++;
		i++;
	}
	if (n2 != 12)
		return (0);
	if (n != 4)
		return (0);
	return (1);
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
	if (x > 0 && tab[x - 1][y] == '#' && x != 4)
		ft_check_pos(tab, x, y, ret + 1);
	return (0);
}

int		**ft_create_tab(char **tab)
{
	int	i;
	int	j;
	int	**pattern;
	int x;
	int y;

	i = 0;
	j = 0;
	x = 0;
	y = 1;
	pattern = (int **)malloc(sizeof(int **) * 5);
	if (pattern == NULL)
		return (pattern);
	while (tab[i])
	{
		pattern[x] = (int *)malloc(sizeof(int *) * 3);
		if (tab[i][j] == '#')
		{
/*			if (ft_check_pos(tab, i, j, 0) == 0)
			{
				pattern[0] = NULL;
				return (pattern);
			}
*/			pattern[x][y] = j;
			y--;
			pattern[x][y] = i;
			x++;
			y = 1;
		}
		j++;
		if (j == 5)
		{
			j = 0;
			i++;
		}
	}
	return (pattern);
}

int		**ft_create(char *str)
{
	char*s;
	char**tab;
	int	**pattern;
	int i;

	i = 0;
	s = ft_strdup(str);
	while (s[i] && i < 20)
		i++;
	s[i] = '\0';
	if (ft_check_str(s) == 0)
		return (NULL);
	tab = ft_strsplit(s, '\n');
	pattern = ft_create_tab(tab);
	return (pattern);
}

t_tetr		*ft_check_tetr(char *s, int n)
{
	int		i;
	t_tetr	*tetr;

	i = 0;
	while (s[i] && i < n)
	{
		if ((i + 1) % 21 == 0 && s[i] != '\n' && i != 0)
			return (NULL);
		i++;
	}
	i = 0;
	while (s[i] && i < n)
	{
		if (i == 0)
			tetr = ft_create_elem(ft_create(&s[i]), 'A');
		if (i % 21 == 0 && i != 20 && i != 0 && tetr != NULL)
		{
			ft_lst_pushback(&tetr, ft_create(&s[i]));
		}
		i++;
	}
	ft_print_list(tetr);
	return (tetr);
}
