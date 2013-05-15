

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

static void	to_graphic(t_game *game, t_player *player, t_player *egg)
{
  char		buff[512];

  (void)game;
  bzero(buff, sizeof(buff));
  sprintf(buff, G_FORK_END, egg->num, player->num, egg->pos.x, egg->pos.y);
  send_to_graphic(game, buff);
}

static int	set_eclore_action(t_game *game, t_player *egg)
{
  unsigned int	idx_action;
  static unsigned int size = sizeof(gl_protocol) / sizeof(*gl_protocol);

  idx_action = -1;
  while (++idx_action < size)
    {
      if (!strncmp(gl_protocol[idx_action].action, ECLORE,
		   strlen(gl_protocol[idx_action].action)))
	{
	  push_action(game, egg, idx_action, ECLORE);
	  return (SUCCESS_VALUE);
	}
    }
  return (ERROR_VALUE);
}

static t_player *new_egg(t_game *game, t_player *player, int num)
{
  t_player	*egg;

  egg = malloc(sizeof(*egg));
  if (egg)
    {
      bzero(egg, sizeof(*egg));
      egg->num = num;
      egg->type = TYPE_EGG;
      egg->team = player->team;
      egg->pos.x = player->pos.x;
      egg->pos.y = player->pos.y;
      egg->direction = player->direction;
      egg->sock = 0;
      egg->life.nb = DEFAULT_LIFE;
      egg->level = 1;
      to_graphic(game, player, egg);
      (void)set_eclore_action(game, egg);
    }
  return (egg);
}

static int	put_egg_in_game(t_game *game,
				t_player *player,
				unsigned int num)
{
  game->clients[num] = new_egg(game, player, num);
  return (SUCCESS_VALUE);
}

int		action_fork(t_game *game, t_player *player,
			    unsigned int idx_action)
{
  unsigned int	num;

  printf("fork\n");
  num = -1;
  (void)idx_action;
  while (++num < MAX_CLIENT)
    if (game->clients[num] == NULL)
      return (put_egg_in_game(game, player, num));
  return (ERROR_VALUE);
}
