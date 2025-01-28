# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/25 17:31:32 by rpandipe          #+#    #+#              #
#    Updated: 2025/01/28 11:16:19 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CFLAG = -Wall -Werror -Wextra -std=c++98
NAME = intern
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
