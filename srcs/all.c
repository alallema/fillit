/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pattern.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 11:50:21 by alallema          #+#    #+#             */
/*   Updated: 2015/12/20 14:55:10 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

void	ft_check_pattern(int **pattern)
{
	int i;
	int j;
	int k;

	j = 0;
	while (j < 2)
	{
		i = 0;
		k = 4;
		while (i < 4)
		{
			if (pattern[i][j] < k)
				k = pattern[i][j];
			i++;
		}
		if (k != 0)
		{
			i = 0;
			while (i < 4)
			{
				pattern[i][j] = (pattern[i][j] - k);
				i++;
			}
		}
		else if (i != 4 && j == 1)
			return ;
		j++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_clace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:45:29 by schiad            #+#    #+#             */
/*   Updated: 2015/12/19 17:35:35 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int		ft_check_place(char **tab, t_tetr *tetr, int ty, int tx)
{
	int	placeable;
	int	x;
	int	y;
	int	i;

	placeable = 1;
	i = 0;
	while (i < 4 && placeable)
	{
		y = tetr->pattern[i][0];
		x = tetr->pattern[i][1];
		if (tab[ty + y][tx + x] != '.')
			placeable = 0;
		i++;
	}
	return (placeable);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 13:57:13 by alallema          #+#    #+#             */
/*   Updated: 2015/12/26 17:16:52 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include <stdlib.h>

t_tetr		*ft_create_elem(int **pattern, char letter)
{
	t_tetr	*elem;

	elem = (t_tetr*)malloc(sizeof(t_tetr));
	if (pattern == NULL)
		return (NULL);
	if (elem != NULL)
	{
		elem->letter = letter;
		elem->pattern = pattern;
		elem->next = NULL;
	}
	return (elem);
}
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_elements.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/26 17:07:12 by schiad            #+#    #+#             */
/*   Updated: 2015/12/26 17:28:42 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <main.h>

void	ft_free_elements(t_tetr *elem)
{
	t_tetr	*next;

	next = elem->next;
	free (elem);
	if (next)
		ft_free_elements(next);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:28:30 by schiad            #+#    #+#             */
/*   Updated: 2015/12/19 17:48:41 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_free_square(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab[i]);
	free(tab);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_pushback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 13:51:33 by alallema          #+#    #+#             */
/*   Updated: 2015/12/17 12:13:30 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <stdlib.h>
#include <libft.h>

void		ft_lst_pushback(t_tetr **begin_list, int **data)
{
	t_tetr	*elem;
	char	c;

	c = 'B';
	elem = *begin_list;
	if (data == NULL)
		*begin_list = NULL;
	if (*begin_list != NULL)
	{
		while (elem->next)
		{
			elem = elem->next;
			c++;
		}
		elem->next = ft_create_elem(data, c);
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 15:13:45 by alallema          #+#    #+#             */
/*   Updated: 2015/12/19 13:52:02 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int		ft_lst_size(t_tetr *tetr)
{
	int i;

	i = 0;
	while (tetr)
	{
		i++;
		tetr = tetr->next;
	}
	return (i);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeur.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:47:11 by schiad            #+#    #+#             */
/*   Updated: 2015/12/19 20:08:23 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

int		ft_placeur(char **tab, t_tetr *tetr, int nb_tetr)
{
	int	y;
	int	x;
	int	placed;

	y = 0;
	while (tab[y])
	{
		x = 0;
		while (tab[y][x])
		{
			if (ft_check_place(tab, tetr, y, x))
			{
				placed = 1;
				ft_writer(tab, tetr, y, x);
				if (!tetr->next)
					return (placed);
				else
					if ((nb_tetr - 1) == (placed = ft_placeur(tab
									, tetr->next, nb_tetr - 1)))
						return (placed + 1);
				ft_remover(tab, tetr, y, x);
			}
			x++;
		}
		y++;
	}
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:50:42 by alallema          #+#    #+#             */
/*   Updated: 2015/12/19 13:54:34 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

void	ft_print_list(t_tetr *tetr)
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_result.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:18:35 by schiad            #+#    #+#             */
/*   Updated: 2015/12/19 19:25:53 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

void	ft_print_result(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_putstr(tab[i]);
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:01:39 by alallema          #+#    #+#             */
/*   Updated: 2015/12/27 15:32:51 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libft.h>
#include <main.h>

t_tetr		*ft_create_list(char *s, int n)
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
			tetr = ft_create_elem(ft_create_pattern(&s[i]), 'A');
		if (i % 21 == 0 && i != 20 && i != 0 && tetr != NULL)
			ft_lst_pushback(&tetr, ft_create_pattern(&s[i]));
		i++;
	}
	return (tetr);
}

t_tetr		*ft_read_file(char *av)
{
	int		fd;
	char	buf;
	char	*s;
	int		i;

	i = 0;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (NULL);
	while (read(fd, &buf, 1))
	{
		if ((buf != '.' && buf != '#' && buf != '\n') || buf == 0 || i > 560)
			return (NULL);
		i++;
	}
	if ((i + 1) % 21 != 0)
		return (NULL);
	close(fd);
	fd = open(av, O_RDONLY);
	s = (char *)malloc(sizeof(char) * i + 1);
	while (read(fd, s, (i + 1)))
		return (ft_create_list(s, i));
	close(fd);
	free(s);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remover.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:44:17 by schiad            #+#    #+#             */
/*   Updated: 2015/12/19 17:37:21 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

void	ft_remover(char **tab, t_tetr *tetr, int ty, int tx)
{
	int i;
	int x;
	int y;

	i = 0;
	while (i < 4)
	{
		y = tetr->pattern[i][0];
		x = tetr->pattern[i][1];
		tab[ty + y][tx + x] = '.';
		i++;
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:05:09 by schiad            #+#    #+#             */
/*   Updated: 2015/12/26 17:29:52 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

void		ft_resolver(t_tetr *tetr, int nb)
{
	char	**tab;
	int		i;
	int		retour;

	retour = 0;
	tab = ft_square_char_tab(33);
	i = 0;
	while (((i / 2) * (i / 2)) < nb)
		i++;
	i--;
	while (!retour)
	{
		ft_square_char_filler(tab, i);
		retour = ft_placeur(tab, tetr, nb);
		i++;
	}
	ft_print_result(tab);
	ft_free_square(tab);
	ft_free_elements(tetr);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_char_filler.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:25:21 by schiad            #+#    #+#             */
/*   Updated: 2015/12/19 20:05:42 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

void		ft_square_char_filler(char **tab, int nb)
{
	int		j;
	char	*tmp;

	tmp = (char *)malloc(sizeof(char) * (nb + 1));
	ft_strncpy(tmp, ".................................", nb);
	tmp[nb] = '\n';
	j = 0;
	while (j < nb)
	{
		ft_strcpy(tab[j], tmp);
		j++;
	}
	free(tmp);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_square_char_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:22:54 by schiad            #+#    #+#             */
/*   Updated: 2015/12/19 19:29:41 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <main.h>

char	**ft_square_char_tab(int nb)
{
	char	**tab;
	int		i;

	tab = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < nb)
	{
		tab[i] = ft_strnew(nb + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 13:42:25 by schiad            #+#    #+#             */
/*   Updated: 2015/12/19 17:36:56 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

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
