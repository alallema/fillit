/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 15:50:20 by alallema          #+#    #+#             */
/*   Updated: 2015/12/12 12:40:30 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

int		main(int argc, char **argv)
{
	if (argc != 2)
		ft_putstr("error\n");
	if (argc == 2)
		ft_read_file(argv[1]);
	return (0);
}
