/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 15:50:20 by alallema          #+#    #+#             */
/*   Updated: 2015/12/19 18:03:35 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <main.h>

int			main(int argc, char **argv)
{
	t_tetr	*tetr;
	int		n;

	tetr = NULL;
	if (argc == 2)
	{
		tetr = ft_read_file(argv[1]);
		n = ft_lst_size(tetr);
	}
	if (argc != 2 || tetr == NULL)
		ft_putstr("error\n");
	else
		ft_resolver(tetr, n);
	return (0);
}
