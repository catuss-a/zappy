

#ifndef		PLAYER_H_
# define	PLAYER_H_

typedef int	(*t_handle_player)(struct s_game *game,
				   struct s_player *player,
				   void *arg);

extern char		*gl_objects[MAX_ITEMS];

typedef struct		s_life
{
  unsigned int		nb;
  struct timeval	delay;
}			t_life;

typedef struct		s_player
{
  int			num;
  char			type;
  t_teams		*team;
  unsigned int		cur_action;
  t_action		actions[MAX_ACTIONS];
  t_coord2d		pos;
  unsigned int		graphic_pos_x;
  unsigned int		graphic_pos_y;
  char			team_sent;
  unsigned int		direction;
  int			sock;
  t_life		life;
  unsigned int		level;
  unsigned int		bag[MAX_ITEMS];
  
  t_users		*gl_usr;
}			t_player;

#endif 
