# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tda-silv <tda-silv@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/17 14:32:32 by tda-silv          #+#    #+#              #
#    Updated: 2022/12/18 04:50:34 by tda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

SRC_DIR		= source/
OBJ_DIR		= object/
INC_DIR		= include/

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

# **************************************************************************** #
# -I | Chemin du dossier où trouver un .h									   #
# -L | Chemin du dossier où trouver un .a									   #
# -l | Nom du .a sans le préfixe "lib"										   #
# **************************************************************************** #

I_HEADERS	= -I $(INC_DIR)
L_LIB		= -lpthread

################################################################################

HEADERS		= ./include/header.h

NAME_FILE	= $(addprefix t_ll_p/,												\
								 ll_p_add_back									\
								 ll_p_clear										\
								 ll_p_last										\
								 ll_p_new										\
								 ll_p_size										\
			   )																\
			  main																\
			  ft_strlen															\
			  ft_putstr_fd														\
			  check_error														\
			  init																\
			  exec_philo														\
			  start_all_thread													\
			  wait_thread														\

SRC			= $(addsuffix .c, $(addprefix $(SRC_DIR), $(NAME_FILE)))
OBJ			= $(addsuffix .o, $(addprefix $(OBJ_DIR), $(NAME_FILE)))

################################################################################

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(I_HEADERS) -c $< -o $@ -D_REENTRANT -DLinux

all: $(NAME) $(HEADERS)

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(I_HEADERS) $(L_LIB) -o $(NAME) -D_REENTRANT -DLinux

################################################################################

valgrind: $(OBJ)
	valgrind --tool=memcheck --track-origins=yes --leak-check=full --show-leak-kinds=all --track-fds=yes ./$(NAME)

################################################################################

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all valgrind clean fclean re
