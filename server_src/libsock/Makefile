
NAME		=	libsock.a
SRCS_DIR	=	src/
INC_DIR		=	include/
SRCS		=	$(SRCS_DIR)raise_error.c			\
			$(SRCS_DIR)circ_buffer.c			\
			$(SRCS_DIR)new_circ_buffer.c			\
			$(SRCS_DIR)sock_accept.c			\
			$(SRCS_DIR)sock_handle.c			\
			$(SRCS_DIR)sock_handle_select.c			\
			$(SRCS_DIR)sock_receive.c			\
			$(SRCS_DIR)sock_send.c				\
			$(SRCS_DIR)sock_disconnect.c			\
			$(SRCS_DIR)sock_socket_disconnect.c		\
			$(SRCS_DIR)sock_read_on_socket.c		\
			$(SRCS_DIR)sock_write_on_socket.c		\
			$(SRCS_DIR)sock_free_user.c			\
			$(SRCS_DIR)sock_find_user.c			\
			$(SRCS_DIR)sock_reception_handler.c		\
			$(SRCS_DIR)sock_get_elapsed_time.c		\
			$(SRCS_DIR)sock_get_timeout.c			\
			$(SRCS_DIR)sock_set_timeout.c			\
			$(SRCS_DIR)sock_stop.c				\
			$(SRCS_DIR)sock_run.c				\
			$(SRCS_DIR)sock_add_fd.c			\
			$(SRCS_DIR)sock_remove_fd.c			\
			$(SRCS_DIR)sock_mod_fd.c			\
			$(SRCS_DIR)sock_handle_epoll.c			\
			$(SRCS_DIR)sock_init.c
OBJS		=	$(SRCS:.c=.o)

CC		=	gcc
INCLUDE		=	-I$(INC_DIR)
CFLAGS		+=	-W -Wall
CFLAGS		+=	$(INCLUDE)
CFLAGS		+=	-O2
#CFLAGS		+=	-g3
AR		=	ar -r
RANLIB		=	ranlib
RM		=	rm -f

$(NAME)		:	$(OBJS) 
		$(AR) $(NAME) $(OBJS)
		$(RANLIB) $(NAME)

all		:	$(NAME)


clean		:
		$(RM) $(OBJS)

fclean		:	clean
		$(RM) $(NAME)

re		:	fclean all


.PHONY		:	all clean fclean re

