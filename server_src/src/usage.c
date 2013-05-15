

#include <stdio.h>

int		usage(void)
{
  fprintf(stderr, "Usage: %s\n", "\t./server \
[[[-p port] -p port] ...] [-x world_x] [-y world_y]\
[-c max_clients] [-t speed] -n team_name_1 team_name_2 ...\n\
Options:\n\t\
-p numero de port\n\t\
-x largeur du Monde\n\t\
-y hauteur du Monde\n\t\
-n nom_de_eequipe_1 nom_de_equipe_2 ...\n\t\
-c nombre de client autorises au commencement du jeu\n\t\
-t delai temporel d'execution des actions.");
  return (1);
}
