/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_tetr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 15:29:29 by alallema          #+#    #+#             */
/*   Updated: 2015/12/19 14:04:19 by schiad           ###   ########.fr       */
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

int		ft_check_pos(char **tab, int x, int y)
{
	int ret;

	ret = 0;
	if (y < 4 && tab[x][y + 1] == '#')
		ret++;
	if (x < 3 && tab[x + 1][y] == '#')
		ret++;
	if (y > 0 && tab[x][y - 1] == '#')
		ret++;
	if (x > 0 && tab[x - 1][y] == '#')
		ret++;
	return (ret);
}

int		ft_check_valid(char **tab, int i, int j, int n)
{
	int	pos[4];

	while (tab[i])
	{
		if (tab[i][j] == '#')
		{
			pos[n] = ft_check_pos(tab, i, j);
			n++;
		}
		j++;
		if (j == 5 && i++ < 4)
			j = 0;
	}
	n = 0;
	while (pos[n])
	{
		if (pos[n] == 0)
			return (0);
		if (pos[n] == 1)
			j++;
		n++;
	}
	if (j == 4)
		return (0);
	return (1);
}

int		**ft_create_tab(char **tab, int x, int y)
{
	int	i;
	int	j;
	int	**pattern;

	i = 0;
	j = 0;
	pattern = (int **)malloc(sizeof(pattern) * 5);
	if (pattern == NULL || ft_check_valid(tab, 0, 0, 0) == 0)
		return (NULL);
	while (tab[i])
	{
		pattern[x] = (int *)malloc(sizeof(int *) * 2);
		if (tab[i][j] == '#')
		{
			pattern[x][y--] = j;
			pattern[x++][y] = i;
			y = 1;
		}
		j++;
		if (j == 5 && i++ < 4)
			j = 0;
	}
	ft_check_pattern(pattern);
	return (pattern);
}

int		**ft_create_pattern(char *str)
{
	char*s;
	char**tab;
	int	**pattern;
	int i;
	int y;

	y = 1;
	i = 0;
	s = ft_strdup(str);
	while (s[i] && i < 20)
		i++;
	s[i] = '\0';
	if (ft_check_str(s) == 0)
		return (NULL);
	i = 0;
	tab = ft_strsplit(s, '\n');
	pattern = ft_create_tab(tab, i, y);
	return (pattern);
}
