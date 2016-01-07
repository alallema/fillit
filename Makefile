# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alallema <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/07 11:44:18 by alallema          #+#    #+#              #
#    Updated: 2016/01/07 11:44:26 by alallema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
STD =		\033[39m

NAME =		fillit
EXEC =		main.c

LDIR =		./libs/
LIBS =		-lft

IDIR =		./incs/
INCS =		libft.h					\
			main.h
INCC =		$(addprefix $(IDIR),$(INCS))

SDIR =		./srcs/
SRCS =		ft_create_elem.c		\
			ft_lst_pushback.c		\
			ft_read_file.c			\
			ft_create_pattern.c		\
			ft_check_pattern.c		\
			ft_lst_size.c			\
			ft_resolver.c			\
			ft_check_place.c		\
			ft_placeur.c			\
			ft_writer.c				\
			ft_remover.c			\
			ft_square_char_tab.c	\
			ft_square_char_filler.c	\
			ft_print_result.c		\
			ft_free_square.c		\
			ft_free_elements.c		\
			ft_nb_dots.c


SRCC =		$(addprefix $(SDIR),$(SRCS))

ODIR =		./objs/
OBJS =		$(SRCS:.c=.o)
OBCC =		$(addprefix $(ODIR),$(OBJS))

NORM =		$(SRCC) $(INCC) $(EXEC)

FLAG =		-Wall -Wextra -Werror -I$(IDIR)

all: $(NAME)

$(NAME): header $(OBCC)
	@echo "  ${BLU}+Compilation:${STD} $@"
	@gcc $(FLAG) $(EXEC) $(OBCC) -L$(LDIR) $(LIBS) -o $(NAME)
	@echo "  ${YEL}Compilation terminee !${STD}"

$(ODIR)%.o: $(SDIR)%.c
	@echo "  ${GRE}+Compilation :${STD} $^"
	@gcc $^ $(FLAG) -c -o $@

header:
	@echo "${YEL}"
	@echo "  ==================="
	@echo "  |  Projet Fillit  |"
	@echo "  ==================="
	@echo "${STD}"

norme: header
	@echo "${GRE}  Verification de la norme${STD}\n"
	@norminette $(NORM)
	@echo "${RED}  \nTotal errors :${STD}" $(shell norminette $(NORM) | grep -v "Norme" | wc -l)

clean: header
	@echo "  ${RED}-Nettoyage des fichiers objet...${STD}"
	@rm -f $(OBCC)

fclean: clean
	@rm -f $(NAME)
	@echo "  ${RED}-Nettoyage de l'exécutable...${STD}"

re: fclean all
