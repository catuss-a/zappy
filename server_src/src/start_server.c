

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <list_wrapper.h>

#include "game.h"

static int	set_next_timeout(t_timeval *timeout)
{
  t_timeval	cur_time;
  t_timeval	res;

  if (timeout)
    {
      (void)gettimeofday(&cur_time, NULL);
      timersub(timeout, &cur_time, &res);
      sock_set_timeout((res.tv_sec >= 0 ? res.tv_sec * USEC : 0)
		       + res.tv_usec);
      return (SUCCESS_VALUE);
    }
 return (SUCCESS_VALUE);
}

static t_state	data_treatment(void *arg)
{
  t_game	*game;
  t_timeval	*timeout;

  game = arg;
  timeout = NULL;
  (void)handle_map(game);
  if (foreach_player(game, handle_do_action, NULL) == STOP)
    return (STOP);
  (void)foreach_player(game, handle_check_life, NULL);
  (void)foreach_player(game, handle_smallest_time_action, &timeout);
  (void)foreach_player(game, handle_smallest_time_life, &timeout);
  (void)set_next_timeout(timeout);
  (void)handle_graphic(game);
  return (CONTINUE);
}

int		start_server(t_game *game)
{
  t_handlers	handlers;

  printf("%c[1;32mConfiguration : Max(%d) WorldX(%d) WorldY(%d) T(%d)%c[0m\n",
	 0x1B, game->options.max_client, game->map.width,
	 game->map.height, game->options.time_unit, 0x1B);
  handlers.reception = request_callback;
  handlers.accept = connection_callback;
  handlers.disconnect = disconnection_callback;
  handlers.treatment = data_treatment;
  handlers.init = NULL;
  handlers.stop = NULL;
  sock_run(game->options.port, -1, game, &handlers);
  return (0);
}
