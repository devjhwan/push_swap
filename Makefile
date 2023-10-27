# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghwle <junghwle@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/26 22:32:15 by junghwle          #+#    #+#              #
#    Updated: 2023/10/26 22:32:18 by junghwle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=push_swap

SRCDIR=./src
STACK_DIR=stack
UTILS_DIR=utils
HASH_DIR=hash
OBJDIR=objs
SRCS=main.c parse_input.c stack.c stack_visualizer.c stack_push.c stack_swap.c \
	 stack_rotate.c stack_reverse_rotate.c ft_print.c hash.c
OBJS=$(patsubst %.c, $(OBJDIR)/%.o, $(SRCS))
DEPS=$(OBJS:.o=.d)

INCLUDE=-I./inc
CC=gcc
CFLAGS=-Wall -Werror -Wextra
DEPFLAGS=-MMD

all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS) Makefile
	$(CC) $(CFLAGS) -o $@ $(OBJS)
	echo "(PUSH_SWAP) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/%.c Makefile 
	$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $<
	echo "(PUSH_SWAP) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/$(STACK_DIR)/%.c Makefile 
	$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $<
	echo "(PUSH_SWAP) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/$(HASH_DIR)/%.c Makefile 
	$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $<
	echo "(PUSH_SWAP) COMPILING $@"

$(OBJDIR)/%.o: $(SRCDIR)/$(UTILS_DIR)/%.c Makefile 
	$(CC) $(DEPFLAGS) $(CFLAGS) $(INCLUDE) -c -o $@ $<
	echo "(PUSH_SWAP) COMPILING $@"

$(OBJDIR): Makefile
	mkdir -p $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
.SILENT:
