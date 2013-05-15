

#ifndef		PROTOCOL_H_
# define	PROTOCOL_H_

struct		s_game;
struct		s_player;

typedef int	(*t_handle_action)(struct s_game *game,
				   struct s_player *player,
				   unsigned int idx_action,
				   void *arg);

typedef struct timeval t_timeval;

typedef	struct	s_protocol
{
  char const	*action;
  t_timeval	delay;
  int		(*do_action)(struct s_game *game,
			     struct s_player *player,
			     unsigned int idx_action);
}		t_protocol;

typedef struct	s_graphic_protocol
{
  char const	*request;
  void		(*handler)(struct s_game *game, t_users *usr,
				char const *msg);
}		t_graphic_protocol;

extern t_protocol		gl_protocol[13];
extern t_graphic_protocol	g_graphic_protocol[9];

int		action_voir(struct s_game *game, struct s_player *player,
			    unsigned int idx_action);
int		action_avance(struct s_game *game, struct s_player *player,
			      unsigned int idx_action);
int		action_droite(struct s_game *game, struct s_player *player,
			      unsigned int idx_action);
int		action_gauche(struct s_game *game, struct s_player *player,
			      unsigned int idx_action);
int		action_inventaire(struct s_game *game, struct s_player *player,
				  unsigned int idx_action);
int		action_prend_objet(struct s_game *game, struct s_player *player,
				   unsigned int idx_action);
int		action_pose_objet(struct s_game *game, struct s_player *player,
				  unsigned int idx_action);
int		action_expulse(struct s_game *game, struct s_player *player,
			       unsigned int idx_action);
int		action_broadcast_txt(struct s_game *game, struct s_player *player,
				     unsigned int idx_action);
int		action_incantation(struct s_game *game, struct s_player *player,
				   unsigned int idx_action);
int		action_fork(struct s_game *game, struct s_player *player,
			    unsigned int idx_action);
int		action_connect_nbr(struct s_game *game, struct s_player *player,
				   unsigned int idx_action);

#endif		
