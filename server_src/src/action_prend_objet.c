

#include <stdio.h>
#include <string.h>

#include "game.h"

static void	to_graphic(t_game *game, t_player *player, unsigned int idx)
{
  int		offset;
  char		buff[512];

  offset = MAP_OFFSET(player->pos.x, player->pos.y, game->map.width);
  bzero(buff, sizeof(buff));
  sprintf(buff, G_PLAYER_TAKE, player->num, idx);
  send_to_graphic(game, buff);
  inventory_to_graphic(game, player);
  cell_content_to_graphic(game, &player->pos);
}

int		action_prend_objet(t_game *game, t_player *p,
				   unsigned int idx_action)
{
  char		*obj;
  unsigned int	idx;

  printf("prend\n");
  obj = (char*)p->actions[idx_action].action + strlen(PREND_OBJET);
  while (*obj && *obj == ' ')
    ++obj;
  idx = -1;
  while (++idx < MAX_ITEMS)
    if (!strncmp(obj, gl_objects[idx], strlen(gl_objects[idx])))
      if (game->map.map[MAP_OFFSET(p->pos.x, p->pos.y,
				   game->map.width)][idx] > 0)
	{
	  if (idx == NOURRITURE)
	    p->life.nb += 1;
	  else
	    p->bag[idx] += 1;
	  game->map.map[MAP_OFFSET(p->pos.x, p->pos.y, game->map.width)][idx] -= 1;
	  break ;
	}
  sock_send(p->sock, idx < MAX_ITEMS ? OK : KO);
  to_graphic(game, p, idx);
  return (SUCCESS_VALUE);
}
