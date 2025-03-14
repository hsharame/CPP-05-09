NAME = real_type
CXX = c++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror -Wconversion -std=c++98
SRCS = main.cpp Base.cpp Identify.cpp
HEADERS = Base.hpp A.hpp B.hpp C.hpp Identify.hpp
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
