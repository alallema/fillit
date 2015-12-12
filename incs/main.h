/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:12:20 by alallema          #+#    #+#             */
/*   Updated: 2015/12/12 16:40:53 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <string.h>
# define BUFSIZE		1

typedef struct			s_tetr
{
	char				letter;
	char					**pattern;
//	int					*pos;
	struct s_tetr		*next;
}						t_tetr;

void					ft_lst_pushback(t_tetr **begin, char **data);
t_tetr					*ft_create_elem(char **pattern, char letter);
void					ft_print_list(t_tetr *tetr);
t_tetr					*ft_check_tab(char *s, int n);
t_tetr					*ft_create_list(char *tab, int n);
t_tetr					*ft_read_file(char *av);

#endif
