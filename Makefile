# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ashulha <ashulha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/27 10:44:06 by ashulha           #+#    #+#              #
#    Updated: 2017/06/27 11:14:27 by ashulha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
LIBF = libft/
SRCS = src/
CCFL = -Wall -Wextra -Werror -lncurses -ltermcap -L $(LIBF) -lft

all: $(NAME)

$(NAME):
		@make -C $(LIBF) re
		@gcc $(CCFL) $(SRCS)*.c -o $(NAME)

clean:
		@make -C $(LIBF) clean

fclean:
		@make -C $(LIBF) fclean
		@/bin/rm -rf $(NAME)

re: fclean all
