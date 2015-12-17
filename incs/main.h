/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:12:20 by alallema          #+#    #+#             */
/*   Updated: 2015/12/17 17:58:09 by alallema         ###   ########.fr       */
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
	int					**pattern;
//	int					*pos;
	struct s_tetr		*next;
}						t_tetr;

void					ft_lst_pushback(t_tetr **begin, int **data);
t_tetr					*ft_create_elem(int **pattern, char letter);
void					ft_print_list(t_tetr *tetr);
t_tetr					*ft_create_list(char *s, int n);
t_tetr					*ft_check_tab(char *s, int n);
t_tetr					*ft_create_list(char *tab, int n);
t_tetr					*ft_read_file(char *av);
int						**ft_create_pattern(char *str);
int						**ft_check_pattern(int **pattern);

#endif
