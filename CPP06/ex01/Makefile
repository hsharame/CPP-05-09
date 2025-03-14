NAME = serializer
CXX = c++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror -Wconversion -std=c++98
SRCS = main.cpp Serializer.cpp
HEADERS = Data.hpp Serializer.hpp
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
