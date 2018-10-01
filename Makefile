# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oskulska <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/14 21:29:36 by oskulska          #+#    #+#              #
#    Updated: 2018/06/14 21:29:38 by oskulska         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = lem-in

SRCS = main.c create_list.c fill_list.c find_way.c lem_lib.c move_lem.c read.c validation.c create_map.c lem_lib_prt2.c lem_lib_prt3.c

LIBFT = libft/

OBJECTS = $(SRCS:.c=.o)


FLAGS = -Wall -Werror -Wextra

CC = gcc

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo "Creating .o files. Please wait..."
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJECTS) -L $(LIBFT) -lftprintf
	@echo "All .o files successfully created."
	@echo "Executable successfully created."
%.o: %.c
	gcc $(FLAGS) -c $<
clean:
	@echo "Deleting all .o files. Please wait..."
	@rm -f $(OBJECTS)
	@make clean -C $(LIBFT)
	@echo "All .o files deleted."	

fclean: clean
	@echo "Deleting all .o files and executable. Please wait..."
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)
	@echo "All .o files and executable deleted."	

re: fclean all

.PHONY: re all clean fclean
