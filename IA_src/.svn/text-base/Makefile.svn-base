NAME	=	IA

SRCS	=	main.cpp		\
		IAManager.cpp		\
		IA.cpp			\
		Socket.cpp

OBJS	=	$(SRCS:.cpp=.o)

CC	=	g++

RM	=	rm -f

CPPFLAGS =	-W -Wall -Wextra

$(NAME) :	$(OBJS)
	$(CC) $(OBJS) -o $(NAME)

all	:	$(NAME)

clean	:
	$(RM) $(OBJS)

fclean	:	clean
	$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re