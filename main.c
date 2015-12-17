/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 15:50:20 by alallema          #+#    #+#             */
/*   Updated: 2015/12/17 11:49:15 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

int		main(int argc, char **argv)
{
	t_tetr *tetr;

	tetr = NULL;
	if (argc != 2)
		ft_putstr("error\n");
	if (argc == 2)
		tetr = ft_read_file(argv[1]);
	if (tetr == NULL)
		ft_putstr("error\n");
	return (0);
}
