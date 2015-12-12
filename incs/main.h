/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:12:20 by alallema          #+#    #+#             */
/*   Updated: 2015/12/10 20:36:23 by alallema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# define BUFSIZE		1

typedef struct			s_tetr
{
	int					id;
	char				letter;
	char				**pattern;
	struct s_tetr		*next;
}						t_tetr;

void					ft_lst_pushback(t_tetr **begin, char **data);
t_tetr					*ft_create_elem(char **pattern, char letter);
t_tetr					*ft_check_tab(char *s, int n);
void					ft_read_file(char *av);

void					error_display(int errid);
int						check_tetr(int fd);

#endif
