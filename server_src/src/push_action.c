

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "game.h"

static void	to_graphic(t_game *game, t_player *player)
{
  char		buff[512];

  (void)game;
  bzero(buff, sizeof(buff));
  sprintf(buff, G_FORK_START, player->num);
  send_to_graphic(game, buff);
}

static void	set_first_action(t_game *game, t_player *player,
				 int idx, unsigned int idx_action)
{
  t_timeval	delay;

  if (idx == 0 && player->cur_action == 0)
    {
      (void)set_next_delay(&delay, gl_protocol[idx_action].delay.tv_sec,
			   game->options.time_unit);
      player->actions[idx].delay.tv_sec = delay.tv_sec;
      player->actions[idx].delay.tv_usec = delay.tv_usec;
    }
}

int		push_action(t_game *game, t_player *player,
			    unsigned int idx_action, char const *msg)
{
  unsigned int	idx;

  idx = -1;
  while (++idx < MAX_ACTIONS)
    if (player->actions[idx].do_action == NULL)
      {
	print_time();
	printf("Player %d requested '%s' action\n", player->num,
	       gl_protocol[idx_action].action);
	if (!strncmp(INCANTATION, msg, strlen(INCANTATION)))
	  {
	    if (check_incantation(game, player) == ERROR_VALUE)
	      return (ERROR_VALUE);
	    else
	      sock_send(player->sock, ELEVATION_BEGINS);
	  }
	if (!strncmp(FORK, msg, strlen(FORK)))
	  to_graphic(game, player);
	player->actions[idx].action = strdup(msg);
	player->actions[idx].idx_action = idx_action;
	player->actions[idx].do_action = gl_protocol[idx_action].do_action;
	set_first_action(game, player, idx, idx_action);
	return (SUCCESS_VALUE);
      }
  return (ERROR_VALUE);
}
