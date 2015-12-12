/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/05 15:50:20 by alallema          #+#    #+#             */
/*   Updated: 2015/12/09 17:14:11 by rpallies         ###   ########.fr       */
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
