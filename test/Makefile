#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 12:49:25 by ssoraka           #+#    #+#              #
#    Updated: 2019/03/11 20:57:23 by ssoraka          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME1 = list
NAME2 = arr
NAME3 = rbtree
NAME4 = hmap

C_FLAGS = -g

LIBFT = ./../libft.a
LIBFT_HEADER = -I ./../


all: libs_refresh $(NAME4) $(NAME3) $(NAME2) $(NAME1) fclean

libs_refresh:
	@make -C ./../

$(NAME4): ./hmap_main_test.c $(LIBFT)
	gcc -o $(NAME4) ./hmap_main_test.c $(LIBFT) $(LIBFT_HEADER)
	./$(NAME4)

$(NAME3):  ./rbtree_main_test.c $(LIBFT)
	gcc -o $(NAME3) ./rbtree_main_test.c $(LIBFT) $(LIBFT_HEADER)
	./$(NAME3)

$(NAME2):  ./arr_main_test.c $(LIBFT)
	gcc -o $(NAME2) ./arr_main_test.c $(LIBFT) $(LIBFT_HEADER)
	./$(NAME2)

$(NAME1):  ./list_main_test.c $(LIBFT)
	gcc -o $(NAME1) ./list_main_test.c $(LIBFT) $(LIBFT_HEADER)
	./$(NAME1)


clean:
	rm -rf *.o

fclean: clean
	rm -rf $(LIB) $(NAME1) $(NAME2) $(NAME3) $(NAME4)

re: fclean all