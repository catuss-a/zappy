
NAME		=		libthread.a

MAKE		=		@make --no-print-directory

CXX		=		g++

INCLUDE		=		-I./include
CXXFLAGS	+=		-W -Wall $(INCLUDE)

SRC_FILE	=		./src/

SRC		=		$(SRC_FILE)CondVar.cpp		\
				$(SRC_FILE)Mutex.cpp		\
				$(SRC_FILE)Thread.cpp		\
				$(SRC_FILE)ScopedLock.cpp

OBJ		=		$(SRC:.cpp=.o)

RM		=		rm -f

AR		=		ar rcs
RANLIB		=		ranlib

all		:
		$(MAKE) $(NAME)

$(NAME)		: $(OBJ)
		$(AR) $(NAME) $(OBJ)
		$(RANLIB) $(NAME)

clean		:
		$(RM) $(OBJ)

fclean		: clean
		$(RM) $(NAME)

re		: fclean all

.cpp.o		:
		$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY		: all re clean fclean
