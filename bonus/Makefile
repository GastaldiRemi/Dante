##
## Makefile for bonus in /home/gastal_r/rendu/dante/bonus
## 
## Made by 
## Login   <gastal_r@epitech.net>
## 
## Started on  Wed May  4 04:36:24 2016 
## Last update Sun May 22 03:46:11 2016 
##

ECHO		=	/bin/echo -e
DEFAULT		=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED		=	"\033[0;31m"

NAME		=	bonus

CC		=	gcc -D _DEFAULT_SOURCE

CFLAGS          +=      -Wextra -Wall -Werror
CFLAGS          +=      -ansi -pedantic
CFLAGS          +=      -I./include
CFLAGS          +=      -L/home/${USER}/.froot/lib/ -llapin
CFLAGS          +=      -L/usr/local/lib
CFLAGS          +=      -lsfml-audio
CFLAGS          +=      -lsfml-graphics
CFLAGS          +=      -lsfml-window
CFLAGS          +=      -lsfml-system
CFLAGS          +=      -lstdc++
CFLAGS          +=      -ldl
CFLAGS          +=      -lm
CFLAGS          +=      -llapin
CFLAGS          +=      -D LAPIN_ALLOCATOR_OVERLOAD
CFLAGS          +=      -L$(LP_LIBRARY_PATH)
CFLAGS          +=      -I$(C_INCLUDE_PATH)

SRC		=	sources/main.c				\
			sources/menu.c				\
			sources/aff_all.c			\
			sources/bunny_response.c		\
			sources/x_fonction.c			\
			sources/generateur/generateur.c		\
			sources/generateur/gen_maze_size.c	\
			sources/generateur/break_wall.c		\
			sources/generateur/check_case.c		\
			sources/generateur/write_maze.c		\
			sources/generateur/init_maze.c		\
			sources/profondeur/check_dir.c		\
			sources/profondeur/check_fonc.c		\
			sources/profondeur/get_path.c		\
			sources/profondeur/list_fonc.c		\
			sources/profondeur/profondeur.c		\
			sources/profondeur/utils.c		\
			sources/largeur/check_case.c		\
			sources/largeur/get_path.c		\
			sources/largeur/largeur.c		\
			sources/largeur/list_fonc.c		\
			sources/astar/check_dir.c		\
			sources/astar/check_list.c		\
			sources/astar/get_path.c		\
			sources/astar/list_fonc.c		\
			sources/astar/astar.c			\
			sources/astar/my_math.c	

OBJ		=	$(SRC:.c=.o)

all:		title $(NAME)

title:
		@$(ECHO) $(GREEN)BONUS$(TEAL)DANTE$(DEFAULT)

clean:
		@rm -f $(OBJ)

fclean:		clean
		@rm -f $(NAME)

re:		clean fclean all

$(NAME):	$(OBJ)
		@$(CC) -o $(NAME) $(OBJ) $(CFLAGS) && \
		 $(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT)  || \
		 $(ECHO) $(RED) "[XX]" $(TEAL) $(NAME)

.c.o:
		@$(CC) $(CFLAGS) -c $< -o $@  && \
		 $(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)
