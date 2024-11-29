# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 20:03:01 by rpandipe          #+#    #+#              #
#    Updated: 2024/11/30 00:49:57 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
NAME = harl
SRCS = $(wildcard *.cpp)
OBJSDIR = objs
OBJS = $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
RM = rm - rf

all: $(NAME)

$(OBJSDIR)/%.o : %.cpp
	@mkdir -p $(OBJSDIR)
	@$(CXX) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJS)
	$(CXX) $(CFLAG) -o $@ $(OBJS)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
