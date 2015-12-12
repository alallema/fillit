/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 15:50:20 by alallema          #+#    #+#             */
/*   Updated: 2015/12/10 12:58:32 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

void	error_display(int errid)
{
	if (errid == 0)
		ft_putendl_fd("#Err[00] : Wrong argument count (1 expected)", 2);
	else if (errid == 1)
		ft_putendl_fd("#Err[01] : File not found", 2);
	else if (errid == 2)
		ft_putendl_fd("#Err[02] : Submitted file is invalid", 2);
	else
		ft_putendl_fd("#Err[??] : Unknown error", 2);
}

int		file_checking(int fd)
{
	if (fd == -1)
	{
		error_display(1);
		return (1);
	}
	if (check_tetr(fd))
	{
		error_display(2);
		return (1);
	}
	close(fd);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;

	ret = 0;
	if (argc != 2)
	{
		error_display(0);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	ret = file_checking(fd);
	if (argc == 2)
		ft_read_file(argv[1]);
	return (ret);
	return (file_checking(fd));
}
