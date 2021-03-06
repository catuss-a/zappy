

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#include "game.h"

static int	handle_error(t_game *game)
{
  int		ret;

  ret = 0;
  fprintf(stdout, "%c[1;32mListening on port %d ...%c[0m\n", 0x1B,
	  game->options.port, 0x1B);
  if ((!game->map.width || !game->map.height) && (ret = ERROR_VALUE))
    fprintf(stderr, "error: the world is too small\n");
  if (!game->options.max_client && (ret = ERROR_VALUE))
    fprintf(stderr, "error: max_client must be > 0\n");
  if ((game->options.time_unit < 1 || game->options.time_unit > 1000000)
      && (ret = ERROR_VALUE))
    fprintf(stderr, "error: the speed must be between 1 and 1000000\n");
  if ((!game->teams[0].name || !game->teams[1].name) && (ret = ERROR_VALUE))
    fprintf(stderr, "error: you must create at least two teams\n");
  return (ret);
}

static void	set_team_name(int argc, char **argv,
			      t_game *game)
{
  int		cur_idx;
  int		idx_team;

  idx_team = -1;
  cur_idx = optind - 1;
  while (++cur_idx < argc && *argv[cur_idx] != '-')
    {
      game->teams[MOD_MAXCLIENT(++idx_team)].name = argv[cur_idx];
      game->teams[MOD_MAXCLIENT(idx_team)].nb_clients =
	game->options.max_client;
    }
}

int		parse_options(int argc, char **argv,
			      t_game *game)
{
  char		c;

  while ((c = getopt(argc, argv, "p:x:y:t:c:n")) != -1)
    {
      if (c == 'p')
	game->options.port = strtol(optarg, NULL, 10);
      else if (c == 'x')
	game->map.width = strtol(optarg, NULL, 10);
      else if (c == 'y')
	game->map.height = strtol(optarg, NULL, 10);
      else if (c == 't')
	game->options.time_unit = strtol(optarg, NULL, 10);
      else if (c == 'c')
	game->options.max_client = strtol(optarg, NULL, 10);
      else if (c == 'n')
	set_team_name(argc, argv, game);
      else
	return (usage());
    }
  return (handle_error(game));
}
