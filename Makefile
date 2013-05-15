##
## Makefile for zappy in /home/moreau_c//repo/zappy
## 
## Made by christopher moreau
## Login   <moreau_c@epitech.net>
## 
## Started on  Thu Jun  9 14:50:56 2011 christopher moreau
## Last update Sun Jul 10 23:10:59 2011 ghjuvan-carlu bianchi
##

SERVER			=	server
CLIENT			=	client
IA			=	IA

MAKE			=	@make --no-print-directory
CP			=	@cp

all			:
			$(MAKE) $(SERVER)
			$(MAKE) $(CLIENT)
			$(MAKE) $(IA)

$(CLIENT)		:
			$(MAKE) -C $(CLIENT)_src
			$(CP) $(CLIENT)_src/$(CLIENT) .

$(SERVER)		:
			$(MAKE) -C $(SERVER)_src
			$(CP) $(SERVER)_src/$(SERVER) .

$(IA)			:
			$(MAKE) -C $(IA)_src
			$(CP) $(IA)_src/$(IA) .

clean			:
			$(RM) $(SERVER)
			$(RM) $(CLIENT)
			$(RM) $(IA)

fclean			: clean
			$(MAKE) fclean -C $(SERVER)_src
			$(MAKE) fclean -C $(CLIENT)_src
			$(MAKE) fclean -C $(IA)_src

re			: fclean
			$(MAKE) re -C $(SERVER)_src
			$(CP) $(SERVER)_src/$(SERVER) .
			$(MAKE) re -C $(CLIENT)_src
			$(CP) $(CLIENT)_src/$(CLIENT) .
			$(MAKE) re -C $(IA)_src
			$(CP) $(IA)_src/$(IA) .

.PHONY			: client server ia