CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes
SRCS = srcs/Animal.cpp      srcs/Cat.cpp         srcs/Dog.cpp         srcs/WrongAnimal.cpp srcs/WrongCat.cpp    srcs/main.cpp  
OBJS = $(SRCS:.cpp=.o)
NAME = animals.exe

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
