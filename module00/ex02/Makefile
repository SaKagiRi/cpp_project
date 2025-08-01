NAME			= Account
CC				= c++
CPPFLAGS		= $(VERSIONFLAGS) $(WFLAGS)
VERSIONFLAGS	= -std=c++98
WFLAGS			= -Wall -Wextra -Werror

FILE			= Account.cpp tests.cpp
OBJ				= $(FILE:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $^ -o $@

%.o:%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
