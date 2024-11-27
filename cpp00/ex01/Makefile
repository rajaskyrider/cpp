# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/27 15:30:41 by rpandipe          #+#    #+#              #
#    Updated: 2024/11/27 15:34:21 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = phonebook
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re