/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:01:39 by alallema          #+#    #+#             */
/*   Updated: 2015/12/17 19:56:58 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libft.h>
#include <main.h>

/*void    ft_check(int *pos,t_tetr *tetr, int j)
{
	int i;

	i = 0;
	while (pos[i] != 0 && i < 4)
		i++;
	if (i != 4)
		return ;
	i = 0;
	while (i < 4)
	{
		pos[i] = pos[i] - 1;
		tetr->pattern[i][j] = pos[i];
		ft_putnbr(tetr->pattern[i][j]);
		i++;
	}
	ft_putchar('\n');
//	ft_modif_pattern(pos, tetr, j);
	ft_check(pos, tetr, j);
}

void    ft_check_pattern(t_tetr *tetr)
{
	int i;
	int j;
	int	*pos;
	
	while (tetr)
	{
		j = 0;
		while (j < 2)
		{
			pos = (int *)malloc(sizeof(int) * 5);
			i = 0;
			while (i < 4)
			{
				pos[i] = tetr->pattern[i][j];
				i++;
			}
			j++;
			ft_check(pos, tetr, j);
		}
		tetr = tetr->next;
	}
}
*/
t_tetr      *ft_create_list(char *s, int n)
{
	int     i;
	t_tetr  *tetr;
	
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
//	ft_check_pattern(tetr);
	ft_print_list(tetr);
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
		ft_putstr("invalid file");
	while (read(fd, &buf, 1))
	{
		if (buf == 0)
			return (NULL);
		if (buf != '.' && buf != '#' && buf != '\n')
			return (NULL);
		if (i > 560)
			return (NULL);
		i++;
	}
	close(fd);
	fd = open(av, O_RDONLY);
	s = (char *)malloc(sizeof(char) * i + 1);
	while (read(fd, s, (i + 1)))
		return (ft_create_list(s, i));
	close(fd);
	return (0);
}
