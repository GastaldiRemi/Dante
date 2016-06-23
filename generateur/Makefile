##
## Makefile for makefie in /home/gastal_r/rendu/CPE_2015/CPE_2015_Lemin/remi
##
## Made by remi gastal_r
## Login   <gastal_r@epitech.net>
##
## Started on  Tue Apr 19 14:47:11 2016 remi gastal_r
## Last update Sun May 22 10:04:37 2016 remi gastal_r
##

ECHO            	=      	 /bin/echo -e
DEFAULT         	=       "\033[00m"
GREEN           	=       "\033[0;32m"
TEAL            	=       "\033[1;36m"
RED			=       "\033[0;31m"

CC			=       gcc -O3

RM			=       rm -rf

NAME			=	generateur

SRC			=       ../sources/generateur/main.c		\
				../sources/generateur/gen_maze_size.c	\
				../sources/generateur/check_case.c	\
				../sources/generateur/init_maze.c	\
				../sources/generateur/break_wall.c	\
				../sources/generateur/write_maze.c

OBJS			=       $(SRC:.c=.o)

CFLAGS			+=	-Wextra -Wall -Werror
CFLAGS			+=	-ansi -pedantic
CFLAGS			+=	-I../include

all     		:       $(NAME)

title                   :
				@$(ECHO) $(GREEN)GENERATEUR$(DEFAULT)

$(NAME)		 	:       $(OBJS)
				@$(CC) -o $(NAME) $(OBJS) && \
				$(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT)  || \
				$(ECHO) $(RED) "[XX]" $(TEAL) $(NAME)

clean   		:
				@$(RM) $(NAME)

fclean			:       clean
				@$(RM) $(OBJS)

re			:       clean fclean all

.PHONNY			:       all clean fclean re

.c.o                    :
				@$(CC) $(CFLAGS) -c $< -o $@  && \
				$(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
				$(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)
