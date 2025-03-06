NAME = divercity
CXX = c++
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp \
	RobotomyRequestForm.cpp PresidentialPardonForm.cpp
HEADERS = Bureaucrat.hpp Form.hpp ShrubberyCreationForm.hpp \
	RobotomyRequestForm.hpp PresidentialPardonForm.hpp
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
