
NAME			=	client

MAKE			=	@make --no-print-directory

LIBTHREAD		=	libthread

SRC			=	src/Socket.cpp			\
				src/Core.cpp			\
				src/Window.cpp			\
				src/SceneManager.cpp		\
				src/AssetManager.cpp		\
				src/ProtocolManager.cpp		\
				src/GlobalView.cpp		\
				src/Launcher.cpp		\
				src/GObject.cpp			\
				src/GridObject.cpp		\
				src/Resource.cpp		\
				src/Grid.cpp			\
				src/Tooltip.cpp			\
				src/Zappy.cpp			\
				src/Player.cpp			\
				src/PlayerView.cpp		\
				src/InventoryView.cpp		\
				src/Broadcast.cpp		\
				src/main.cpp

OBJ			=	$(SRC:.cpp=.o)

CXX			=	g++
INCLUDE			=	-I./src -I./$(LIBTHREAD)/include
CXXFLAGS		+=	-W -Wall $(INCLUDE) -O2
LDFLAGS			=	-L./$(LIBTHREAD) -lthread -pthread \
				-lsfml-system -lsfml-graphics -lsfml-audio -lsfml-window

RM			=	rm -f

all			:
			$(MAKE) $(LIBTHREAD)
			$(MAKE) $(NAME)

$(NAME)			: $(OBJ)
			$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

$(LIBTHREAD)		:
			$(MAKE) -C $(LIBTHREAD)

clean			:
			$(RM) $(OBJ)

fclean			: clean
			$(RM) $(NAME)

re			: fclean all

.PHONY			: clean fclean re $(LIBTHREAD)