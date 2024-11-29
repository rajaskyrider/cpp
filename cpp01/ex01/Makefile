# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 12:13:35 by rpandipe          #+#    #+#              #
#    Updated: 2024/11/29 12:18:59 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
NAME = zombiehorde
SRCS = $(wildcard *.cpp)
OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
RM = rm -rf

all = $(NAME)

$(OBJDIR)/%.o : %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CFLAG) -c $< -o $@

$(NAME): $(OBJS)
	$(CXX) $(CFLAG) -o $@ $(OBJS)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all