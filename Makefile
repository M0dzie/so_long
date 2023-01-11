# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thmeyer <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/20 10:17:28 by thmeyer           #+#    #+#              #
#    Updated: 2023/01/11 09:44:13 by thmeyer          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NOCOLOR= \033[0m
BGREEN = \033[1;32m

NAME = so_long
HEADER = so_long.h

CC = cc
C_FLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit

RM = rm -rf

SRCS = main.c \
		sl_utils.c \
		check_errors.c

OBJS = $(SRCS:%.c=$(DIR_OBJS)%.o)

DIR_OBJS = Objs/
DIR_LIBFT = Libft/
DIR_MLX = Minilibx/

LIBFT_A = $(DIR_LIBFT)libft.a
LIBMLX_A = $(DIR_MLX)libmlx.a

all: directory rsc $(NAME)

$(NAME): $(LIBFTB_A) $(LIBMLX_A) $(OBJS)
	$(CC) $(C_FLAGS) $(MLX_FLAGS) -o $(NAME) $(OBJS) $(LIBFT_A) $(LIBMLX_A)

rsc:
	@$(MAKE) -C $(DIR_LIBFT)
	@$(MAKE) -C $(DIR_MLX)

$(DIR_OBJS)%.o: %.c Makefile $(HEADER)
	$(CC) $(C_FLAGS) -o $@ -c $<

clean:
	@$(MAKE) clean -C $(DIR_LIBFT)
	@$(MAKE) clean -C $(DIR_MLX)
	$(RM) $(OBJS)
	$(RM) $(DIR_OBJS)
	@echo "$(BGREEN)Clean done$(NOCOLOR)"
    
fclean: 
	@$(MAKE) fclean -C $(DIR_LIBFT)
	@$(MAKE) clean
	$(RM) $(NAME)
	@echo "$(BGREEN)Fclean done$(NOCOLOR)"

re: 
	@$(MAKE) fclean
	@$(MAKE) all

directory:
	@mkdir -p $(DIR_OBJS)

.PHONY: all clean fclean re