# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 11:12:53 by rpandipe          #+#    #+#              #
#    Updated: 2025/02/12 12:23:54 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = array
SRCS = $(wildcard *.cpp)
HEADERS = $(wildcard *.hpp) $(wildcard *.tpp)
OBJSDIR = objs
OBJS = $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
RM = rm -rf

all: $(NAME)

$(OBJSDIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJSDIR)
	@$(CXX) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CXX) $(CFLAGS) -o $@ $(OBJS)

clean:
	@$(RM) $(OBJSDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

