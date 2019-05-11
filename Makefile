# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ffoissey <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/05 18:25:23 by ffoissey          #+#    #+#              #
#    Updated: 2019/04/02 14:29:08 by ffoissey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
FILE_CHECKER = checker exec
FILE_PUSH_SWAP = push_swap make_simple algo algo500 order tool_push_swap post_process algo_tool
FILE_COM = print_stack process tool tool2
LIB = libft/libft.a
SRCS_CHECKER = $(patsubst %,srcs_checker/ft_%.c,$(FILE_CHECKER))
OBJS_CHECKER = $(patsubst %,objs_checker/ft_%.o,$(FILE_CHECKER))
SRCS_PUSH_SWAP = $(patsubst %,srcs_push_swap/ft_%.c,$(FILE_PUSH_SWAP))
OBJS_PUSH_SWAP = $(patsubst %,objs_push_swap/ft_%.o,$(FILE_PUSH_SWAP))
SRCS_COM = $(patsubst %,srcs_com/ft_%.c,$(FILE_COM))
OBJS_COM = $(patsubst %,objs_checker/ft_%.o,$(FILE_COM))
DIR_OBJS_CHECKER = objs_checker/
DIR_OBJS_PUSH_SWAP = objs_push_swap/
INCLUDES += -I includes/
INCLUDES += -I libft/includes
INCLUDES += -I libft/includes/get_next_line
INCLUDES += -I libft/includes/ft_printf
HEAD += includes/checker.h
HEAD += includes/push_swap.h
HEAD +=	includes/common.h
CFLAGS = -Wall -Werror -Wextra
CC = clang

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(DIR_OBJS_CHECKER) $(OBJS_CHECKER) $(OBJS_COM) $(LIB)
	$(CC) $(CFLAGS) $(OBJS_CHECKER) $(OBJS_COM) $(LIB) $(INCLUDES) -o $@

$(OBJS_COM): objs_checker/%.o: srcs_checker/%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(DIR_OBJS_CHECKER):
	mkdir objs_checker

$(OBJS_CHECKER): objs_checker/%.o: srcs_checker/%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(PUSH_SWAP): $(DIR_OBJS_PUSH_SWAP) $(OBJS_PUSH_SWAP) $(OBJS_COM) $(LIB)
	$(CC) $(CFLAGS) $(OBJS_PUSH_SWAP) $(OBJS_COM) $(LIB) $(INCLUDES) -o $@

$(DIR_OBJS_PUSH_SWAP):
	mkdir objs_push_swap

$(OBJS_PUSH_SWAP): objs_push_swap/%.o: srcs_push_swap/%.c $(HEAD)
	$(CC) $(CFLAGS) -c $< $(INCLUDES) -o $@

$(LIB): FORCE
	make -C libft/

clean:
	make clean -C libft/
	rm -Rf $(DIR_OBJS_CHECKER) $(DIR_OBJS_PUSH_SWAP) $(OBJS_CHECKER) $(OBJS_PUSH_SWAP) $(DIR_OBJS_COM) $(OBJS_COM)

fclean: clean
	make fclean -C libft/
	rm -f $(CHECKER) $(PUSH_SWAP)

re: fclean all

up:
	git add -A && git commit -m"up" && git push

FORCE:

.PHONY: clean fclean re all FORCE
