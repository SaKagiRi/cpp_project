NAME			= Iter
CC				= c++
CPPFLAGS		= $(VERSIONFLAGS) $(WFLAGS)
VERSIONFLAGS	= -std=c++98
WFLAGS			= -Wall -Wextra -Werror

OBJDIR			= obj
SRCDIR			= .

FILE			= main.cpp
OBJ				= $(addprefix $(OBJDIR)/, $(FILE:.cpp=.o))

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CPPFLAGS) $^ -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJDIR)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

.PHONY: all clean fclean re
