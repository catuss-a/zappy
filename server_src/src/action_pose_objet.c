

#include <stdio.h>
#include <string.h>

#include "game.h"

static void	to_graphic(t_game *game, t_player *player, unsigned int idx)
{
  int		offset;
  char		buff[512];

  offset = MAP_OFFSET(player->pos.x, player->pos.y, game->map.width);
  bzero(buff, sizeof(buff));
  sprintf(buff, G_PLAYER_DROP, player->num, idx);
  send_to_graphic(game, buff);
  inventory_to_graphic(game, player);
  cell_content_to_graphic(game, &player->pos);
}

int		action_pose_objet(t_game *game, t_player *player,
				  unsigned int idx_action)
{
  char		*obj;
  unsigned int	idx;

  printf("pose\n");
  obj = (char*)player->actions[idx_action].action + strlen(POSE_OBJET);
  while (*obj && *obj == ' ')
    ++obj;
  idx = -1;
  while (++idx < MAX_ITEMS)
    if (!strncmp(obj, gl_objects[idx], strlen(gl_objects[idx])))
      {
	if (idx == NOURRITURE && player->life.nb > 0)
	  player->life.nb -= 1;
	else
	  player->bag[idx] -= 1;
	  game->map.map[MAP_OFFSET(player->pos.x, player->pos.y,
				   game->map.width)][idx] += 1;
	  break ;
      }
  sock_send(player->sock, idx < MAX_ITEMS ? OK : KO);
  to_graphic(game, player, idx);
  return (SUCCESS_VALUE);
}
