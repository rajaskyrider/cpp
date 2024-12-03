# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 21:23:54 by rpandipe          #+#    #+#              #
#    Updated: 2024/12/03 02:35:58 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
NAME = bsp
SRCS = $(wildcard *.cpp)
OBJDIR = objs
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
RM = rm -rf

all: $(NAME)

$(OBJDIR)/%.o : %.cpp
	@mkdir -p $(OBJDIR)
	@$(CXX) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJS)
	@$(CXX) $(CFLAG) -o $@ $(OBJS)

clean:
	@$(RM) $(OBJDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re