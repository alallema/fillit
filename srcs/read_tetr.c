/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tetr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 18:51:49 by alallema          #+#    #+#             */
/*   Updated: 2015/12/10 20:50:47 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <libft.h>
#include <main.h>

void	ft_print_list(t_tetr *tetr)
{
	int	i;

	i = 0;
	while (tetr)
	{
		while (tetr->pattern[i])
		{
			ft_putstr(tetr->pattern[i]);
			ft_putchar('\n');
			i++;
		}
		ft_putchar(tetr->letter);
		ft_putchar('\n');
		tetr = tetr->next;
		i = 0;
	}
}

char	*ft_cut_str(char *tab)
{
	int	i;

	i = ft_strlen((char *)tab) - 1;
	while (tab[i] != '#')
		i--;
	if (i % 5 == 0)
		tab[i] = '\0';
	else
		tab[i + (i % 5)] = '\0';
	i = 0;
	while (tab[i] != '#')
		i++;
	if (i % 5 == 0)
		return (&tab[i]);
	else
		return (&tab[i - (i % 5)]);
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

char	**ft_create_tab(char *tab)
{
	char*s;
	char **tab2;
	int	i;

	i = 0;
	s = ft_strdup(tab);
	while (s[i] && i < 20)
		i++;
	s[i] = '\0';
	s = ft_cut_str(s);
	tab2 = ft_strsplit(s, '\n');
	tab2 = ft_cut_tab(tab2);
	return (ft_cut_tab2(tab2));
}

void	ft_create_list(char *tab, int n)
{
	t_tetr	*tetr;
	int		i;

	i = 0;
	while (tab[i] && i < n)
	{
		if (i == 0)
			tetr = ft_create_elem(ft_create_tab(&tab[i]), 'A');
		if (i % 21 == 0 && i != 20 && i != 0)
		{
			ft_lst_pushback(&tetr, ft_create_tab(&tab[i]));
		}
		i++;
	}
	ft_print_list(tetr);
}

void	ft_read_file(char *av)
{
	int		fd;
	char	buf;
	char	*tab;
	int		i;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_putstr("invalid file");
	while (read(fd, &buf, 1))
		i++;
	close(fd);
	fd = open(av, O_RDONLY);
	tab = (char *)malloc(sizeof(char) * i + 1);
	while (read(fd, tab, (i + 1)))
		ft_create_list(tab, i);
	close(fd);
}
