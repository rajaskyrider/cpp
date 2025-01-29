# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/29 17:13:54 by rpandipe          #+#    #+#              #
#    Updated: 2025/01/29 17:15:02 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CFLAG = -Wall -Werror -Wextra -std=c++98
NAME = convert
SRCS = $(wildcard *.cpp)
OBJSDIR = objs
OBJS = $(addprefix $(OBJSDIR)/, $(SRCS:.cpp=.o))
RM = rm -rf

all: $(NAME)

$(OBJSDIR)/%.o : %.cpp
	@mkdir -p $(OBJSDIR)
	@$(CXX) $(CFLAG) -c $< -o $@

$(NAME): $(OBJS)
	@$(CXX) $(CFLAG) -o $@ $(OBJS)

clean:
	@$(RM) $(OBJSDIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all