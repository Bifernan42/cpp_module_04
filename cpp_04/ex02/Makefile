CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -Iincludes -MMD -MP
SRCS = srcs/Animal.cpp \
    srcs/Cat.cpp         \
    srcs/Dog.cpp        \
    srcs/WrongAnimal.cpp \
    srcs/WrongCat.cpp \
    srcs/main.cpp \
    srcs/Brain.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)
NAME = animals.exe

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

-include $(DEPS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS) $(DEPS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
