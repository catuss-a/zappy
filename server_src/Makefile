
##########################################################################################
## VARIABLES
##########################################################################################
NAME			=	server
MAKE			=	@make --no-print-directory
LIBSOCK			=	libsock
MEMORY_POOL		=	memory_pool
LIST_WRAPPER		=	list_wrapper
CC			=	gcc
INCLUDE			=	-I./include
INCLUDE			+=	-I./$(LIBSOCK)/include
INCLUDE			+=	-I./$(LIST_WRAPPER)/include
CFLAGS			+=	-W -Wall $(INCLUDE)
#CFLAGS			+=	-g3
CFLAGS			+=	-O2
LDFLAGS			=	-L./$(LIBSOCK) -lsock
LDFLAGS			+=	-L./$(LIST_WRAPPER) -llist_wrapper
RM			=	rm -f
DIR_SRC			=	./src
OBJ			=	$(SRC:.c=.o)

##########################################################################################
## SOURCES
##########################################################################################
SRC			=	$(DIR_SRC)/handle_connection.c			\
				$(DIR_SRC)/handle_disconnection.c		\
				$(DIR_SRC)/handle_requests.c			\
				$(DIR_SRC)/handle_map.c				\
				$(DIR_SRC)/handle_msz.c				\
				$(DIR_SRC)/handle_bct.c				\
				$(DIR_SRC)/handle_mct.c				\
				$(DIR_SRC)/handle_tna.c				\
				$(DIR_SRC)/handle_ppo.c				\
				$(DIR_SRC)/handle_plv.c				\
				$(DIR_SRC)/handle_pin.c				\
				$(DIR_SRC)/handle_sgt.c				\
				$(DIR_SRC)/handle_sst.c				\
				$(DIR_SRC)/display_map.c			\
				$(DIR_SRC)/init_default_options_server.c	\
				$(DIR_SRC)/send_to_graphic.c			\
				$(DIR_SRC)/cell_content_to_graphic.c		\
				$(DIR_SRC)/set_next_delay.c			\
				$(DIR_SRC)/print_time.c				\
				$(DIR_SRC)/inventory_to_graphic.c		\
				$(DIR_SRC)/send_map_to_graphic.c		\
				$(DIR_SRC)/send_teams_to_graphic.c		\
				$(DIR_SRC)/send_players_to_graphic.c		\
				$(DIR_SRC)/new_player_to_graphic.c		\
				$(DIR_SRC)/init_game.c				\
				$(DIR_SRC)/find_player.c			\
				$(DIR_SRC)/init_player_client.c			\
				$(DIR_SRC)/request_for_team.c			\
				$(DIR_SRC)/gl_object.c				\
				$(DIR_SRC)/parse_options.c			\
				$(DIR_SRC)/protocol_txt.c			\
				$(DIR_SRC)/start_server.c			\
				$(DIR_SRC)/get_description_of_cell.c		\
				$(DIR_SRC)/push_action.c			\
				$(DIR_SRC)/foreach_player_handles.c		\
				$(DIR_SRC)/count_functions.c			\
				$(DIR_SRC)/foreach_player.c			\
				$(DIR_SRC)/action_voir.c			\
				$(DIR_SRC)/action_avance.c			\
				$(DIR_SRC)/action_droite.c			\
				$(DIR_SRC)/action_gauche.c			\
				$(DIR_SRC)/action_inventaire.c			\
				$(DIR_SRC)/action_prend_objet.c			\
				$(DIR_SRC)/action_pose_objet.c			\
				$(DIR_SRC)/action_expulse.c			\
				$(DIR_SRC)/action_broadcast_txt.c		\
				$(DIR_SRC)/action_incantation.c			\
				$(DIR_SRC)/action_fork.c			\
				$(DIR_SRC)/action_eclore.c			\
				$(DIR_SRC)/action_connect_nbr.c			\
				$(DIR_SRC)/case_vh.c				\
				$(DIR_SRC)/case_diag.c				\
				$(DIR_SRC)/usage.c				\
				$(DIR_SRC)/main.c

##########################################################################################
## RULES
##########################################################################################
all			:
			$(MAKE) $(LIST_WRAPPER)
			$(MAKE) $(LIBSOCK)
			$(MAKE) $(NAME)

$(NAME)			: $(OBJ)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

$(LIBSOCK)		:
			$(MAKE) -C $(LIBSOCK)

$(LIST_WRAPPER)		:
			$(MAKE) -C $(LIST_WRAPPER)

clean			:
			$(RM) $(OBJ)

fclean			: clean
			$(RM) $(NAME)

re			: fclean all

.PHONY			: clean fclean re $(LIBSOCK) $(LIST_WRAPPER)
