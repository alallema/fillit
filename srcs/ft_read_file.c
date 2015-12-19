/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:01:39 by alallema          #+#    #+#             */
/*   Updated: 2015/12/19 14:01:58 by schiad           ###   ########.fr       */
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
//	ft_print_list(tetr);
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
		if (buf == 0)
			return (NULL);
		if (buf != '.' && buf != '#' && buf != '\n')
			return (NULL);
		if (i > 560)
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
	return (0);
}
