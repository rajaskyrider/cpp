# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 21:20:23 by rpandipe          #+#    #+#              #
#    Updated: 2025/03/04 19:15:58 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = PmergeMe
SRCS = $(wildcard *.cpp)
HEADER = $(wildcard *.hpp)
OBJSDIR = objs
OBJS = $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
RM = rm -rf

all: $(NAME)

$(OBJSDIR)/%.o:%.cpp $(HEADER)
	@mkdir -p $(OBJSDIR)
	@$(CXX) $(CFLAGS) -c $< -o $@

$(NAME):$(OBJS)
	@$(CXX) $(CFLAGS) -o $@ $(OBJS)

clean:
	@$(RM) $(OBJSDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re