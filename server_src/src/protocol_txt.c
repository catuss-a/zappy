

#include <stdlib.h>

#include "game.h"


t_protocol		gl_protocol[] =
  {
    {VOIR, {7, 0}, action_voir},
    {AVANCE, {7, 0}, action_avance},
    {DROITE, {7, 0}, action_droite},
    {GAUCHE, {7, 0}, action_gauche},
    {INVENTAIRE, {1, 0}, action_inventaire},
    {PREND_OBJET, {7, 0}, action_prend_objet},
    {POSE_OBJET, {7, 0}, action_pose_objet},
    {EXPULSE, {7, 0}, action_expulse},
    {BROADCAST_TXT, {7, 0}, action_broadcast_txt},
    {INCANTATION, {300, 0}, action_incantation},
    {FORK, {42, 0}, action_fork},
    {CONNECT_NBR, {0, 0}, action_connect_nbr},
    {ECLORE, {600, 0}, action_eclore}
  };

t_graphic_protocol	g_graphic_protocol[] =
  {
    {MAP_SIZE, handle_msz},
    {CELL_CONTENT, handle_bct},
    {MAP_CONTENT, handle_mct},
    {TEAM_NAMES, handle_tna},
    {PLAYER_POS, handle_ppo},
    {PLAYER_LEVEL, handle_plv},
    {PLAYER_INVENTORY, handle_pin},
    {GET_TIME, handle_sgt},
    {SET_TIME, handle_sst}
  };
