# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdaillet <mdaillet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/27 15:23:15 by mdaillet          #+#    #+#              #
#    Updated: 2021/08/31 16:28:31 by mdaillet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

SRCS = srcs/main.c \
	   srcs/ft_utils.c \
	   srcs/ft_arg_check.c \
	   srcs/ft_print.c \
	   srcs/ft_action.c \

CFLAGS = -Wall -Wextra -Werror -pthread

CC = gcc

INC = inc/

HEADER = $(INC)philo.h

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) 
	 $(CC) $(CFLAGS) -o $@ $(OBJ)
	@echo "\nCompilation done !"
	@echo "How to use : ./philo [nb of philo] [time to die] [time to eat] [time to sleep] [nb time philo has to eat]"
	@echo "The last argument is optional"


%.o: %.c $(HEADER)
	$(CC) -c $(CFLAGS) -I $(INC) $< -o $@

norme :
	norminette srcs/

clean :
	$(RM) $(OBJ)
	@echo "Cleaning OBJS"
	
fclean : clean
	$(RM) $(NAME)
	@echo "Cleaning all"

re : fclean all

.PHONY : all norme clean fclean re
