NAME		:= megaphone
CXX			:= c++
CXXFLAGS	:= -Wall -Wextra -Werror -std=c++98

SRCS		:= megaphone.cpp
OBJS		:= $(SRCS:.cpp=.o)

.PHONY: all clean fclean re

all:	$(NAME)

$(NAME) :$(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o:	%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all
