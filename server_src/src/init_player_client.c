

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"
#include "list_wrapper.h"

char		find_by_sock(void *ptr, void *arg)
{
  return (((t_pending_clients*)ptr)->p_player->sock == *((int*)arg));
}

static int		check_ghosts(t_game *game,
				     t_users *usr, t_teams *team)
{
  char			buff[512];
  unsigned int		i;

  (void)usr;
  i = 0;
  while (i < MAX_CLIENT)
    {
      if (game->clients[i] && game->clients[i]->sock == 0 &&
	  game->clients[i]->team == team)
	{
	  print_time();
	  printf("player %d is no more in ghost mode\n",
		 game->clients[i]->num);
	  if (sprintf(buff, "%d\n%d %d\n", team->nb_clients,
		      game->map.width, game->map.height) == ERROR_VALUE)
	    return (raise_error("sprintf", ERROR_VALUE));
	  sock_send(usr->sock, buff);
	  game->clients[i]->sock = usr->sock;
	  return (1);
	}
      ++i;
    }
  return (0);
}

static void		init_player_stats(t_game *game, t_player *player,
					  t_users *usr)
{
  player->pos.x = rand() % game->map.width;
  player->pos.y = rand() % game->map.height;
  player->level = DEFAULT_LEVEL;
  player->direction = rand() % 4 + 1;
  player->life.nb = DEFAULT_LIFE;
  (void)set_next_delay(&player->life.delay, 126, game->options.time_unit);
  print_time();
  printf("Player %d joined team %s at (%d, %d)\n",
	 player->num,
	 player->team->name,
	 player->pos.x, player->pos.y);
  player->gl_usr = usr;
}

static int		add_player_to_game(t_game *game,
					   t_users *usr,
					   t_teams *team,
					   unsigned int i)
{
  char			buff[512];
  t_pending_clients	*pending;

  pending = list_find_if(&game->pending, &usr->sock, find_by_sock);
  if (pending)
    {
      team->nb_clients -= 1;
      game->clients[i] = pending->p_player;
      list_remove(pending, &game->pending, NULL);
      game->clients[i]->num = i;
      game->clients[i]->team = team;
      game->clients[i]->type = TYPE_PLAYER;
      game->clients[i]->cur_action = 0;
      init_player_stats(game, game->clients[i], usr);
      if (sprintf(buff, "%d\n%d %d\n", team->nb_clients,
		  game->map.width, game->map.height) == ERROR_VALUE)
	return (raise_error("sprintf", ERROR_VALUE));
      sock_send(usr->sock, buff);
      new_player_to_graphic(game->clients[i], game);
      return (SUCCESS_VALUE);
    }
  return (ERROR_VALUE);
}

int		init_player_client(t_game *game,
				   t_users *usr, t_teams *team)
{
  unsigned int	i;

  i = 0;
  if (check_ghosts(game, usr, team))
    return (SUCCESS_VALUE);
  if (team->nb_clients > 0)
    {
      while (i < MAX_CLIENT)
	{
	  if (game->clients[i] == NULL)
	    return (add_player_to_game(game, usr, team, i));
	  ++i;
	}
    }
  sock_send(usr->sock, "ko\n");
  return (ERROR_VALUE);
}
