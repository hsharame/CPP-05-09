NAME = form
CXX = c++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Bureaucrat.cpp Form.cpp
HEADERS = Bureaucrat.hpp Form.hpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS) 

%.o: %.cpp
		$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
