

#ifndef		ZAPPY_H_
# define	ZAPPY_H_

# include	<sys/time.h>

# include	"libsock.h"
# include	"private_libsock.h"
# include	"coord2d.h"
# include	"defines.h"
# include	"macros.h"
# include	"map.h"
# include	"team.h"
# include	"protocol.h"
# include	"action.h"
# include	"player.h"

typedef struct			s_game_options
{
  int				port;
  unsigned int			max_client;
  unsigned int			time_unit;
}				t_game_options;

typedef struct			s_pending_clients
{
  struct s_pending_clients	*prev;
  struct s_pending_clients	*next;
  t_player			*p_player;
}				t_pending_clients;

typedef struct			s_game
{
  t_pending_clients		*pending;
  t_player			*clients[MAX_CLIENT];
  t_teams			teams[MAX_CLIENT];
  t_map				map;
  t_game_options		options;
}				t_game;

int	usage(void);
int	init_game(t_game *game);
int	init_default_options_server(t_game *game);
int	start_server(t_game *options);
void	connection_callback(t_users *usr, void *arg);
void	disconnection_callback(t_users *usr, void *arg);
void	request_callback(t_users *user, char const *msg, void *arg);
int	parse_options(int argc, char **argv, t_game *game);
void	display_map(t_map *map);
unsigned int	count_food_on_map(t_map *map);
unsigned int	count_current_actions(t_player *player);
int	request_for_team(t_users *usr, t_game *game, char const *msg);
void	send_to_graphic(t_game *game, char const *msg);
void	send_map_to_graphic(t_game *game, t_users *usr);
void	send_cell_to_graphic(t_game *game, int sock, t_coord2d *pos);
void	send_to_graphic(t_game *game, char const *msg);
void	new_player_to_graphic(t_player *player, t_game *game);
void	send_teams_to_graphic(t_game *game, int sock);
void	send_players_to_graphic(t_game *game, int sock);
void	cell_content_to_graphic(t_game *game, t_coord2d *pos);
void	inventory_to_graphic(t_game *game, t_player *player);
int	handle_map(t_game *game);
int	handle_smallest_time_action(t_game *game, t_player *player,
					    void *arg);
int	handle_do_action(t_game *game, t_player *player,
				 __attribute__((unused))void *arg);
int	handle_level_up(t_game *game, t_player *player,
				__attribute__((unused))void *arg);
int	handle_smallest_time_life(t_game *game, t_player *player,
					  void *arg);
void	handle_dying_player(t_game *game, t_player *player);
int	set_next_delay(struct timeval *delay, unsigned int t,
			       unsigned int time_unit);
int	print_time(void);
int	handle_graphic(t_game *game);
int	foreach_player(t_game *game, t_handle_player handle_player, void *arg);
int	handle_check_life(t_game *game, t_player *player, void *arg);
int	get_id_pos_by_coord(t_game *game, t_player *dest, t_coord2d *pos);
int	init_player_client(t_game *game, t_users *usr, t_teams *team);
t_player	*find_player(t_game *game, t_users *usr);
char	find_by_sock(void *ptr, void *arg);
int	get_player_num(char const *msg);
void	avance_player(t_game *game, t_player *player,
		      t_direction direction);
int	push_action(t_game *game, t_player *player,
		    unsigned int idx_action, char const *msg);
void	get_description_of_cell(t_game *game, t_player *player,
				t_coord2d *pos, char **msg);
void	handle_msz(t_game *game, t_users *usr, char const *msg);
void	handle_bct(t_game *game, t_users *usr, char const *msg);
void	handle_mct(t_game *game, t_users *usr, char const *msg);
void	handle_tna(t_game *game, t_users *usr, char const *msg);
void	handle_ppo(t_game *game, t_users *usr, char const *msg);
void	handle_plv(t_game *game, t_users *usr, char const *msg);
void	handle_pin(t_game *game, t_users *usr, char const *msg);
void	handle_plv(t_game *game, t_users *usr, char const *msg);
void	handle_sgt(t_game *game, t_users *usr, char const *msg);
void	handle_sst(t_game *game, t_users *usr, char const *msg);

#endif		
