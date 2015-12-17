/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:01:39 by alallema          #+#    #+#             */
/*   Updated: 2015/12/17 12:20:11 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <libft.h>
#include <main.h>

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
		i++;
	}
	close(fd);
	fd = open(av, O_RDONLY);
	s = (char *)malloc(sizeof(char) * i + 1);
	while (read(fd, s, (i + 1)))
		return (ft_check_tetr(s, i));
	close(fd);
	return (0);
}
