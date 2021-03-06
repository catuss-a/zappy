

#ifndef		MACROS_H_
# define	MACROS_H_


# define ACCESS_TO_CELL(x, y, w, h) (MAP_OFFSET(((int)x<0?w-1:x)%w, ((int)y<0?h-1:y)%h, w))
# define MAP_OFFSET(x, y, x_map) ((y * x_map) + x)

# define MOD_COORD_X(x, width) (((int)x < 0 ? (int)width - 1 : (int)x) % (int)width)
# define MOD_COORD_Y(y, height) (((int)y < 0 ? (int)height - 1 : (int)y) % (int)height)


# define ACTION_READY(player, cur_action) (player && player->actions[cur_action].do_action)

# define MOD_MAXCLIENT(x) (x % MAX_CLIENT)

# define IS_GAMING(client) (client && client->team)

# define IS_SAME_POS(pos1, pos2) (pos1.x == pos2.x && pos1.y == pos2.y ? \
				  SUCCESS_VALUE : ERROR_VALUE)

#endif		
