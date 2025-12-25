NAME			= PmergeMe
CC				= c++
CPPFLAGS		= $(VERSIONFLAGS) $(WFLAGS) $(DFLAGS)
VERSIONFLAGS	= -std=c++98
WFLAGS			= -Wall -Wextra -Werror
DFLAGS			= -DDEBUG=true

OBJDIR			= obj
SRCDIR			= .

FILE			= main.cpp PmergeMe.cpp
OBJ				= $(addprefix $(OBJDIR)/, $(FILE:.cpp=.o))

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp PmergeMe.hpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
