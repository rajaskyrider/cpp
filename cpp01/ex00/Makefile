# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandie@student.42luxembourg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 11:35:25 by rpandipe          #+#    #+#              #
#    Updated: 2024/11/29 11:43:30 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CFLAGS = -Wall -Werror -Wextra -std=c++98
NAME = zombie
SRCS = $(wildcard *.cpp)
OBJDIR      = objs
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
RM = rm -rf

all: $(NAME)

$(OBJDIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CFLAG) -c $< -o $@ 

$(NAME): $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $(OBJS)

clean:
	$(RM) $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re