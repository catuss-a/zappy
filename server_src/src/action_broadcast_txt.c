

#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "game.h"

static void	to_graphic(t_game *game, t_player *player, char *msg)
{
  char		buff[512];

  (void)player;
  bzero(buff, sizeof(buff));
  sprintf(buff, G_PLAYER_BROAD, player->num, msg);
  send_to_graphic(game, buff);
}

static void	set_vector_diagonal(t_coord2d *vect, t_coord2d *diff,
				    int w, int h)
{
  if (diff->x > 0 && diff->y > 0)
    {
      vect->y = diff->y > h / 2 ? -1 : 1;
      vect->x = diff->x > w / 2 ? -1 : 1;
    }
  else if (diff->x > 0 && diff->y < 0)
    {
      vect->y = abs(diff->y) > h / 2 ? 1 : -1;
      vect->x = diff->x > w / 2 ? -1 : 1;
    }
  else if (diff->x < 0 && diff->y > 0)
    {
      vect->y = diff->y > h / 2 ? -1 : 1;
      vect->x = abs(diff->x) > w / 2 ? 1 : -1;
    }
  else if (diff->x < 0 && diff->y < 0)
    {
      vect->y = abs(diff->y) > h / 2 ? 1 : -1;
      vect->x = abs(diff->x) > w / 2 ? 1 : -1;
    }
}

static void	find_received_pos(t_game *game, t_player *dest,
				  t_player *player,
				  t_coord2d *pos)
{
  int		w;
  int		h;
  t_coord2d	vect;
  t_coord2d	diff;

  diff.y = player->pos.y - dest->pos.y;
  diff.x = player->pos.x - dest->pos.x;
  vect.y = 0;
  vect.x = 0;
  h = game->map.height;
  w = game->map.width;
  if (diff.y == 0 && diff.x < 0)
    vect.x = abs(diff.x) > w / 2 ? 1 : -1;
  else if (diff.y == 0 && diff.x > 0)
    vect.x = diff.x > w / 2 ? -1 : 1;
  if (diff.x == 0 && diff.y < 0)
    vect.y = abs(diff.y) > h / 2 ? 1 : -1;
  else if (diff.x == 0 && diff.y > 0)
    vect.y = diff.y > h / 2 ? -1 : 1;
  set_vector_diagonal(&vect, &diff, w, h);
  pos->x = MOD_COORD_X(dest->pos.x + vect.x, w);
  pos->y = MOD_COORD_Y(dest->pos.y + vect.y, h);
}

int		get_id_pos_by_coord(t_game *game, t_player *dest, t_coord2d *pos)
{
  unsigned int	k;
  static check_case gl_id_case[] = {
    case_nord, case_nordouest, case_ouest,
    case_sudouest, case_sud, case_sudest,
    case_est, case_nordest };
  static unsigned int size = sizeof(gl_id_case) / sizeof(*gl_id_case);

  if (dest->pos.x == pos->x && dest->pos.y == pos->y)
    return (0);
  k = -1;
  while (++k < size)
    if (gl_id_case[k](game, dest, pos) == SUCCESS_VALUE)
      return (k + 1);
  return (-1);
}

int		action_broadcast_txt(t_game *game, t_player *player,
				     unsigned int idx_action)
{
  unsigned int	idx_client;
  t_coord2d	pos;
  char		*msg;
  char		*to_send;
  char		flag;

  printf("broadcast\n");
  msg = (char*)player->actions[idx_action].action + strlen(BROADCAST_TXT);
  while (*msg && *msg == ' ' && ++msg);
  flag = 0;
  idx_client = -1;
  while (++idx_client < MAX_CLIENT)
    if (game->clients[idx_client] != player
	&& IS_GAMING(game->clients[idx_client]))
      {
	flag = 1;
	find_received_pos(game, game->clients[idx_client], player, &pos);
	asprintf(&to_send, "message %d,%s",
		 get_id_pos_by_coord(game, game->clients[idx_client], &pos), msg);
	sock_send(game->clients[idx_client]->sock, to_send);
	free(to_send);
      }
  sock_send(player->sock, flag ? OK : KO);
  to_graphic(game, player, msg);
  return (SUCCESS_VALUE);
}
