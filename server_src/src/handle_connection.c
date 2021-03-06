

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list_wrapper.h"
#include "game.h"

void			connection_callback(t_users *usr,
					    void *arg)
{
  t_pending_clients	*n;
  t_game		*game;

  print_time();
  printf("New player connected on socket %d\n", usr->sock);
  game = arg;
  if ((n = list_cpush_back(&game->pending, sizeof(t_pending_clients))))
    {
      n->p_player = malloc(sizeof(*(n->p_player)));
      bzero(n->p_player, sizeof(*n->p_player));
      if (n->p_player)
	{
	  n->p_player->sock = usr->sock;
	  sock_send(usr->sock, "BIENVENUE\n");
	}
      else
	sock_send(usr->sock, "ko\n");
    }
  else
    sock_send(usr->sock, "ko\n");
}
