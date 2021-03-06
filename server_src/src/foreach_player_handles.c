

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "game.h"

int		handle_smallest_time_action(__attribute__((unused))t_game *game,
					    t_player *player,
					    void *arg)
{
  t_timeval	**timeout;

  if (ACTION_READY(player, player->cur_action))
    {
      timeout = (t_timeval**)arg;
      if (*timeout == NULL
	  || timercmp(&player->actions[player->cur_action].delay, *timeout, <=))
	*timeout = &player->actions[player->cur_action].delay;
    }
  return (SUCCESS_VALUE);
}

int		handle_smallest_time_life(__attribute__((unused))t_game *game,
					  t_player *player,
					  void *arg)
{
  t_timeval	**timeout;

  timeout = (t_timeval**)arg;
  if (*timeout == NULL || timercmp(&player->life.delay, *timeout, <=))
    *timeout = &player->life.delay;
  return (SUCCESS_VALUE);
}

int		handle_check_life(t_game *game, t_player *player,
				  __attribute__((unused))void *arg)
{
  t_timeval	cur_date;

  if (player->type == TYPE_PLAYER)
    {
      (void)gettimeofday(&cur_date, NULL);
      if (timercmp(&player->life.delay, &cur_date, <=))
	{
	  print_time();
	  printf("Player %d lost a life.\n", player->num);
	  player->life.nb -= 1;
	  (void)set_next_delay(&player->life.delay, 126, game->options.time_unit);
	}
      if (player->life.nb <= 0)
	handle_dying_player(game, player);
    }
  return (SUCCESS_VALUE);
}

int		handle_do_action(t_game *game, t_player *p,
				 __attribute__((unused))void *arg)
{
  t_timeval	cur_time;

  (void)gettimeofday(&cur_time, NULL);
  if (ACTION_READY(p, p->cur_action))
    if (timercmp(&p->actions[p->cur_action].delay, &cur_time, <=))
      {
	print_time();
	printf("Player %d runs action ", p->num);
	if (p->actions[p->cur_action].do_action(game, p, p->cur_action) == STOP)
	  return (STOP);
	free(p->actions[p->cur_action].action);
	bzero(&p->actions[p->cur_action], sizeof(t_action));
	p->cur_action = (p->cur_action + 1) % MAX_ACTIONS;
	if (ACTION_READY(p, p->cur_action))
	  {
	    (void)set_next_delay(&cur_time,
				 gl_protocol[p->actions[p->cur_action].idx_action]
				 .delay.tv_sec, game->options.time_unit);
	    p->actions[p->cur_action].delay.tv_sec = cur_time.tv_sec;
	    p->actions[p->cur_action].delay.tv_usec = cur_time.tv_usec;
	  }
	else
	  p->cur_action = 0;
      }
  return (SUCCESS_VALUE);
}

int		handle_level_up(__attribute__((unused))t_game *game,
				t_player *player,
				void *arg)
{
  t_player	*cur_player;
  char		msg[16];

  cur_player = (t_player*)arg;
  if (player != cur_player
      && player->pos.x == cur_player->pos.x
      && player->pos.y == cur_player->pos.y
      && player->level == cur_player->level)
    {
      ++player->level;
      sprintf(msg, "niveau actuel : %d\n", player->level);
      sock_send(player->sock, msg);
      return (SUCCESS_VALUE);
    }
  return (ERROR_VALUE);
}
