/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alallema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 13:12:20 by alallema          #+#    #+#             */
/*   Updated: 2015/12/19 17:27:16 by alallema         ###   ########.fr       */
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

void					ft_resolver(t_tetr *tetr, int nb);
int						ft_check_place(char **tab, t_tetr *tetr, int ty, int tx);
int						ft_placeur(char **tab, t_tetr *tetr, int nb_tetr);
void					ft_writer(char **tab, t_tetr *tetr, int ty, int tx);
void					ft_remover(char **tab, t_tetr *tetr, int ty, int tx);
char					**ft_square_char_tab(int nb);
void					ft_square_char_filler(char **tab, int nb);
void					ft_print_result(char **tab);
void					ft_free_square(char **tab);

t_tetr					*ft_create_elem(int **pattern, char letter);
void					ft_lst_pushback(t_tetr **begin_list, int **data);
int						ft_lst_size(t_tetr *tetr);
void					ft_print_list(t_tetr *tetr);
t_tetr					*ft_create_list(char *s, int n);
t_tetr					*ft_check_tab(char *s, int n);
t_tetr					*ft_create_list(char *tab, int n);
t_tetr					*ft_read_file(char *av);
int						**ft_create_pattern(char *str);
void					ft_check_pattern(int **pattern);

#endif
