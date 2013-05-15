

#include <stdio.h>

#include "game.h"

int		action_inventaire(t_game *game, t_player *player,
				  __attribute__((unused))unsigned int idx_action)
{
  char		msg[512];

  printf("inventaire\n");
  sprintf(msg, "{%s %u, %s %u, %s %u, %s %u, %s %u, %s %u, %s %u}\n",
  	  gl_objects[NOURRITURE], player->life.nb,
  	  gl_objects[LINEMATE], player->bag[LINEMATE],
  	  gl_objects[DERAUMERE], player->bag[DERAUMERE],
  	  gl_objects[SIBUR], player->bag[SIBUR],
  	  gl_objects[MENDIANE], player->bag[MENDIANE],
  	  gl_objects[PHIRAS], player->bag[PHIRAS],
  	  gl_objects[THYSTAME], player->bag[THYSTAME]);
  sock_send(player->sock, msg);
  inventory_to_graphic(game, player);
  return (SUCCESS_VALUE);
}
