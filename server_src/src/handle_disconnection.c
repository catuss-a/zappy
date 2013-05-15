

#include <stdio.h>
#include <stdlib.h>

#include "game.h"

void		disconnection_callback(t_users *usr, void *arg)
{
  t_game	*game;
  t_player	*player;

  game = arg;
  player = find_player(game, usr);
  if (player)
    {
      print_time();
      printf("Player %d disconnected\n", player->num);
      if (game->clients[player->num])
	game->clients[player->num]->sock = 0;
      if (player->type == TYPE_GRAPHIC)
	{
	  game->clients[player->num] = NULL;
	  free(player);
	}
      if (player->life.nb > 0)
	{
	  print_time();
	  printf("Player %d is now in ghost mode\n", player->num);
	}
    }
}
