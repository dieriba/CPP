SRC		=	main.cpp \
			Base.cpp \
			A.cpp \
			B.cpp \
			C.cpp
OBJS	=	$(SRC:.cpp=.o)

DEPS 	=	$(SRC:.cpp=.d)

CC		=	c++ -g3

CFLAGS	=	-Wall -Wextra -Werror -MMD -std=c++98

NAME	=	base

.cpp.o :	
			$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME):	$(OBJS)	
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all:		$(NAME)

clean:
			rm -rf *.o
			rm -rf *.d
			
fclean:		clean
			rm -rf $(NAME)

re:			fclean all

-include : $(DEPS)

.PHONY:		all clean fclean re