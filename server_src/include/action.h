

#ifndef		ACTION_H_
# define	ACTION_H_

struct			s_game;
struct			s_player;

typedef	struct		s_action
{
  char			*action;
  struct timeval	delay;
  unsigned int		idx_action;
  int			(*do_action)(struct s_game *game,
				     struct s_player *player,
				     unsigned int idx_action);
}			t_action;

typedef struct		s_incantation
{
  unsigned int		player_required;
  unsigned int		rocks[MAX_ITEMS];
}			t_incantation;

typedef int		(*check_case)(struct s_game *game,
				      struct s_player *dest,
				      t_coord2d *pos);

int			push_action(struct s_game *game,
				    struct s_player *player,
				    unsigned int idx_action,
				    char const *msg);
int			case_nord(struct s_game *game,
				  struct s_player *dest,
				  t_coord2d *pos);
int			case_sud(struct s_game *game,
				 struct s_player *dest,
				 t_coord2d *pos);
int			case_est(struct s_game *game, struct s_player *dest,
				 t_coord2d *pos);
int			case_ouest(struct s_game *game, struct s_player *dest,
				   t_coord2d *pos);
int			case_nordest(struct s_game *game, struct s_player *dest,
				     t_coord2d *pos);
int			case_sudest(struct s_game *game, struct s_player *dest,
				    t_coord2d *pos);
int			case_nordouest(struct s_game *game, struct s_player *dest,
				       t_coord2d *pos);
int			case_sudouest(struct s_game *game, struct s_player *dest,
				      t_coord2d *pos);
int			check_incantation(struct s_game *game, struct s_player *player);
int			action_eclore(struct s_game *game, struct s_player *player,
				      __attribute__((unused))unsigned int idx_action);

#endif		
