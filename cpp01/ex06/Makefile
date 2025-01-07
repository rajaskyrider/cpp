# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/29 20:03:01 by rpandipe          #+#    #+#              #
#    Updated: 2025/01/06 15:37:12 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CFLAG = -Wall -Wextra -Werror -std=c++98
NAME = harlFilter
SRCS = $(wildcard *.cpp)
OBJSDIR = objs
OBJS = $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
RM = rm -rf

all: $(NAME)

$(OBJSDIR)/%.o : %.cpp
	@mkdir -p $(OBJSDIR)
	@$(CXX) $(CFLAG) -c $< -o $@

$(NAME) : $(OBJS)
	$(CXX) $(CFLAG) -o $@ $(OBJS)

clean:
	$(RM) $(OBJSDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
