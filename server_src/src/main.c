

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>

#include "game.h"

int		main(int argc, char *argv[])
{
  t_game	game;

  srand(time(NULL));
  (void)init_default_options_server(&game);
  if (parse_options(argc, argv, &game) == ERROR_VALUE)
    return (EXIT_FAILURE);
  game.map.nb_cells = game.map.width * game.map.height;
  if (init_game(&game) == ERROR_VALUE)
    return (EXIT_FAILURE);
  start_server(&game);
  return (EXIT_SUCCESS);
}
