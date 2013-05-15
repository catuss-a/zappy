
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