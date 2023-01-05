# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 10:17:28 by thmeyer           #+#    #+#              #
#    Updated: 2023/01/05 12:27:10 by thmeyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swap.h

CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRCS = 

OBJS = $(SRCS:%.c=objs/%.o)
DIR_OBJS = objs/
LIBFT = Libft/
LIBFT_A = Libft/libft.a

all: directory rsc $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_A)

rsc:
	$(MAKE) -C $(LIBFT)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT)

$(DIR_OBJS)%.o: %.c Makefile $(HEADER)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	$(MAKE) clean -C $(LIBFT)
	$(RM) $(OBJS)
	$(RM) $(DIR_OBJS)
    
fclean: 
	$(MAKE) fclean -C $(LIBFT)
	$(MAKE) clean
	$(RM) $(NAME)

re: 
	$(MAKE) fclean
	$(MAKE) all

directory:
	@mkdir -p $(DIR_OBJS)

.PHONY: all clean fclean re