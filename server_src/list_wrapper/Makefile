
NAME		=	liblist_wrapper.a
SRCS_DIR	=	srcs/
INC_DIR		=	include/
SRCS		=	$(SRCS_DIR)list_at.c			\
			$(SRCS_DIR)list_back.c			\
			$(SRCS_DIR)list_cpush_back.c		\
			$(SRCS_DIR)list_cpush_front.c		\
			$(SRCS_DIR)list_cpush_insert.c		\
			$(SRCS_DIR)list_create.c		\
			$(SRCS_DIR)list_find_if.c		\
			$(SRCS_DIR)list_foreach.c		\
			$(SRCS_DIR)list_front.c			\
			$(SRCS_DIR)list_pop_back.c		\
			$(SRCS_DIR)list_pop.c			\
			$(SRCS_DIR)list_pop_front.c		\
			$(SRCS_DIR)list_push_back.c		\
			$(SRCS_DIR)list_push_front.c		\
			$(SRCS_DIR)list_push_insert.c		\
			$(SRCS_DIR)list_remove.c		\
			$(SRCS_DIR)list_remove_first.c		\
			$(SRCS_DIR)list_remove_last.c
OBJS		=	$(SRCS:.c=.o)
CC		=	gcc
INCLUDE		=	-I$(INC_DIR)
CFLAGS		+=	-W -Wall
CFLAGS		+=	$(INCLUDE)
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

