/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolver.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schiad <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:05:09 by schiad            #+#    #+#             */
/*   Updated: 2015/12/13 18:54:16 by schiad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char    *ft_strcpy(char *dst, const char *src)
{
	int     i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = src[i];
	return (dst);
}

typedef struct		s_tetr
{
	char			letter;
	int				**pattern;
	int				*pos;
	struct s_tetr	*next;
}					t_tetr;

t_tetr		*ft_create_elem(int **pattern, char letter);
void	resolver(t_tetr *tetr);
int		check_place(char **tab, t_tetr *tetr, int ty, int tx);
int		placeur(char **tab, t_tetr *tetr, int nb_tetr);
void    writer(char **tab, t_tetr *tetr,int ty,int tx,int op);

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr)
	{
		i = 0;
		while (i < (size + 1))
		{
			ptr[i] = '\0';
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}

void	ft_new_elem(t_tetr *alte, int **pattern, char letter)
{
	t_tetr *tmp;

	printf("new %c\n", letter);
	tmp = alte;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	tmp->next = ft_create_elem(pattern, letter);

	printf("new %c\n", letter);
}

t_tetr		*ft_create_elem(int **pattern, char letter)
{
	t_tetr	*elem;
	printf("create %c\n", letter);
	int *pos;

	pos = (int *)malloc(sizeof(int) * 2);
	elem = (t_tetr *)malloc(sizeof(t_tetr));
	if (elem != NULL)
	{
		elem->letter = letter;
		elem->pattern = pattern;
		elem->pos = pos;
		elem->pos[0] = 0;
		elem->pos[1] = 0;
		elem->next = NULL;
	}
	printf("created %c\n", letter);
	return (elem);
}

int		main()
{
	t_tetr	*tetr;
	int i;

	int **t1;
	t1 = (int **)malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
	{
		t1[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	t1[0][0] = 0; t1[0][1] = 0;
	t1[1][0] = 0; t1[1][1] = 1;
	t1[2][0] = 1; t1[2][1] = 1;
	t1[3][0] = 2; t1[3][1] = 1;

	int **t2;
	t2 = (int **)malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
	{
		t2[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	t2[0][0] = 0; t2[0][1] = 0;
	t2[1][0] = 0; t2[1][1] = 1;
	t2[2][0] = 0; t2[2][1] = 2;
	t2[3][0] = 0; t2[3][1] = 3;

	int **t3;
	t3 = (int **)malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
	{
		t3[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	t3[0][0] = 0; t3[0][1] = 0;
	t3[1][0] = 1; t3[1][1] = 0;
	t3[2][0] = 1; t3[2][1] = 1;
	t3[3][0] = 1; t3[3][1] = 2;

	int **t4;
	t4 = (int **)malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
	{
		t4[i] = (int *)malloc(sizeof(int) * 2);
		i++;
	}
	t4[0][0] = 0; t4[0][1] = 0;
	t4[1][0] = 0; t4[1][1] = 1;
	t4[2][0] = 1; t4[2][1] = 1;
	t4[3][0] = 1; t4[3][1] = 2;

	tetr = ft_create_elem((int **)t1, 'A');
	ft_new_elem(tetr, (int **)t2, 'B');
	ft_new_elem(tetr, (int **)t3, 'C');
	ft_new_elem(tetr, (int **)t4, 'D');
	printf("a\n");
	resolver(tetr);
}

void	resolver(t_tetr *tetr)
{
	char	**tab;
	int i;


	tab = (char **)malloc(sizeof(char *) * 101);
	i = 0;
	while (i < 101)
	{
		tab[i] = ft_strnew(100);
		i++;
	}
	tab[i] = NULL;
	i = 0;
	while (i < 4)
	{
		ft_strcpy(tab[i], "....\n");
		i++;
	}
	i = 0;
	printf("start prog\n");
	i = 0;
	while (tab[i])
	{
		printf("%s", tab[i]);
		i++;
	}
	//	while (1)
	//		;
	placeur(tab, tetr, 4);
	i = 0;
	printf("end program\n");
	while (tab[i])
	{
		printf("%s", tab[i]);
		i++;
	}
}

int		placeur(char **tab, t_tetr *tetr, int nb_tetr)
{
	int	y;
	int	x;
	int	placed;

	printf("start placeur\n");
	int i = 0;
	while (tab[i])
	{
		printf("%s", tab[i]);
		i++;
	}
	printf("placeur called\n");
	y = 0;
	while (tab[y])
	{
		printf("%c\n", tab[y][0]);
		printf("%d\n", y);
		x = 0;
		while (tab[y][x])
		{
			printf("try place %c in y= %d x= %d", tetr->letter, y, x);
			if (check_place(tab, tetr, y, x))
			{
				placed = 1;
				printf("placeable return ok\n");
				writer(tab, tetr, y, x, 1);
				int i = 0;
				while (tab[i])
				{
					printf("%s\n", tab[i]);
					i++;
				}
				if (!tetr->next)
					return (placed);
				else
					if ((nb_tetr - 1) == (placed = placeur(tab
									, tetr->next, nb_tetr - 1)))
						return (placed + 1);
				writer(tab, tetr, y, x, 0);
			}
			x++;
		}
		y++;
	}
	printf("placeur end\n");
	return (0);
}

int		check_place(char **tab, t_tetr *tetr, int ty, int tx)
{
	printf("checkplace called\n");
	int	placeable;
	int	x;
	int	y;
	int	i;

	placeable = 1;
	i = 0;
	while (i < 4 && placeable)
	{
		y = tetr->pattern[i][0];
		printf("y = %d and ", y);
		x = tetr->pattern[i][1];
		printf("x = %d\n", x);
		if (tab[ty + y][tx + x] != '.')
			placeable = 0;
		printf("i = %d, place = %d\n", i, placeable);
		i++;
	}
	printf("end check place %d\n", placeable);
	return (placeable);
}

void	writer(char **tab, t_tetr *tetr,int ty,int tx,int op)
{
	printf("startwriter\n");
	int	i;
	int	x;
	int	y;

	i = 0;
	while (i < 4)
	{
		printf("writer i = %d\n", i);
		y = tetr->pattern[i][0];
		x = tetr->pattern[i][1];
		if (!op)
			tab[ty + y][tx + x] = '.';
		else
			tab[ty + y][tx + x] = tetr->letter;
		i++;
	}
	if (op)
	{
		tetr->pos[0] = ty;
		tetr->pos[1] = tx;
	}
}
