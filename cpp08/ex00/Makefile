# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/12 15:16:08 by rpandipe          #+#    #+#              #
#    Updated: 2025/02/12 15:54:06 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
NAME = easyfind
SRCS = $(wildcard *.cpp)
HEADER = $(wildcard *.hpp) $(wildcard *.tpp)
OBJSDIR = objs
OBJS = $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
RM = rm -rf

all: $(NAME)

$(OBJSDIR)/%.o: %.cpp $(HEADER)
	@mkdir -p $(OBJSDIR)
	@$(CXX) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	@$(CXX) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(OBJSDIR)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
