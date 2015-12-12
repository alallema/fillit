/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:51:49 by alallema          #+#    #+#             */
/*   Updated: 2015/12/12 18:34:44 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include <main.h>

char	*ft_cut_str(char *s)
{
	int	i;

	i = ft_strlen((char *)s);
	while (s[i] != '#')
		i--;
	ft_putnbr(i);
	ft_putchar('\n');
	if (i % 5 == 0)
		s[i] = '\0';
	else
		s[i + (i % 5)] = '\0';
	i = 0;
	while (s[i] != '#')
		i++;
	if (i % 5 == 0)
		return (&s[i]);
	else
		return (&s[i - (i % 5)]);
}

char	**ft_cut_tab2(char **tab)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		while (tab[i][j] == '.')
			j++;
		while (tab[i][j] == '#')
			j++;
		tab[i][j] = '\0';
		j = 0;
		i++;
	}
	return (tab);
}
char	**ft_cut_tab(char **tab)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	j = 0;
	ret = 0;
	while (tab[i][j] != '#')
	{
		if (tab[i])
		{
			i = 0;
			j++;
		}
		i++;
	}
	ret = j;
	i = 0;
	if (ret != 0)
	{
		while (tab[i])
		{
			j = 0;
			while (tab[i][j + ret])
			{
				tab[i][j] = tab[i][j + ret];
				j++;
			}
			tab[i][j] = '\0';
			i++;
		}
	}
	return (tab);
}

char	**ft_create_tab(char *str)
{
	char*s;
	char **tab;
	int	i;

	i = 0;
	s = ft_strdup(str);
	while (s[i] && i < 20)
		i++;
	s[i] = '\0';
	s = ft_cut_str(s);
	tab = ft_strsplit(s, '\n');
	tab = ft_cut_tab(tab);
	return (ft_cut_tab2(tab));
}

t_tetr	*ft_create_list(char *s, int n)
{
	t_tetr	*tetr;
	int		i;

	i = 0;
	while (s[i])
	{
		if (i % 21 == 0 && s[i] != 0)
			return (NULL);
	}
	while (s[i] && i < n)
	{
		if (i == 0)
			tetr = ft_create_elem(ft_create_tab(&s[i]), 'A');
		if (i % 21 == 0 && i != 20 && i != 0)
		{
			ft_lst_pushback(&tetr, ft_create_tab(&s[i]));
		}
		i++;
	}
	ft_print_list(tetr);
	return (tetr);
}
