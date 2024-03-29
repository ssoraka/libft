#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/11 12:49:25 by ssoraka           #+#    #+#              #
#    Updated: 2019/04/19 16:52:04 by ssoraka          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

GCC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libft.a
HEADER =	libft.h \
			collections/collections_header.h \
			collections/collections_help_header.h \
			collections/collections_struct.h
SRC = ft_abs.c \
ft_atoi.c \
ft_bzero.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_itoa.c \
ft_lstadd.c \
ft_lstdel.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstnew.c \
ft_memalloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_strcat.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_striter.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlen.c \
ft_strmap.c \
ft_strmapi.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strnequ.c \
ft_strnew.c \
ft_strnstr.c \
ft_strrchr.c \
ft_strsplit.c \
ft_strstr.c \
ft_strsub.c \
ft_strtrim.c \
ft_tolower.c \
ft_toupper.c \
ft_znak.c \
get_next_line.c \
ft_mem_arr_free.c \
ft_mem_arr_new.c \
ft_isspace.c \
ft_sqrt.c \
ft_power.c \
ft_skip_chrs.c \
ft_bytes_to_bits.c \
ft_strjoin_free.c \
ft_strrevers.c \
ft_ltoa.c \
ft_strupcase.c \
ft_strlowcase.c \
ft_max.c \
ft_min.c \
ft_swap.c \
ft_is_null.c \
collections/arr_init.c collections/arr_del.c collections/arr_each.c \
collections/arr_get.c collections/arr_add.c \
collections/hmap.c collections/hmap2.c \
collections/ilist_setters.c collections/ilist_setters2.c \
collections/llist_init.c collections/llist_add.c collections/llist_del.c \
collections/llist_get.c collections/llist_stack.c \
collections/lnode.c \
collections/tnode_track.c collections/tnode_init_del.c \
collections/tnode_rebalance.c collections/tnode_rbtree_property.c \
collections/rbtree_add_get.c collections/rbtree_del.c \
collections/rbtree_track.c collections/rbtree_init.c \
collections/arr_iter.c collections/llist_iter.c collections/rbtree_iter.c
OBJS = $(SRC:.c=.o)

.PHONY: clean all fclean re

all: $(NAME)
	gcc main.c libft.a

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)

%.o: %.c ${HEADER}
	$(GCC) $(CFLAGS) -c $< -o $@  $(addprefix -I ./,${HEADER})

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
