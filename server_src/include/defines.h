

#ifndef		DEFINES_H_
# define	DEFINES_H_


typedef enum		e_error
  {
    ERROR_VALUE = -1,
    SUCCESS_VALUE
  }			t_error;


# define MAX_CLIENT 1024
# define MAX_TYPES_ROCKS 6
# define MAX_ITEMS MAX_TYPES_ROCKS + 1
# define MAX_ACTIONS 10


typedef enum		e_objects
  {
    NOURRITURE = 0,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  }			t_objects;


typedef enum		e_direction
  {
    NORD = 1,
    EST,
    SUD,
    OUEST
  }			t_direction;


# define NO_ACTION	0


# define KO		"ko\n"
# define OK		"ok\n"

# define VOIR		"voir"
# define AVANCE		"avance"
# define DROITE		"droite"
# define GAUCHE		"gauche"
# define INVENTAIRE	"inventaire"
# define PREND_OBJET	"prend "
# define POSE_OBJET	"pose "
# define EXPULSE	"expulse"
# define BROADCAST_TXT	"broadcast "
# define INCANTATION	"incantation"
# define FORK		"fork"
# define CONNECT_NBR	"connect_nbr"
# define DIE		"die"
# define ECLORE		"eclore123987poiuytrewqu"

# define ELEVATION_BEGINS "elevation en cours\n"


# define GRAPHIC_CLIENT	"GRAPHIC\n"

# define MAP_SIZE		"msz"
# define CELL_CONTENT		"bct"
# define MAP_CONTENT		"mct"
# define TEAM_NAMES		"tna"
# define PLAYER_POS		"ppo"
# define PLAYER_LEVEL		"plv"
# define PLAYER_INVENTORY	"pin"
# define GET_TIME		"sgt"
# define SET_TIME		"sst"

# define G_MAP_SIZE	"msz %d %d\n"
# define G_TIME_UNIT	"sgt %d\n"
# define G_CELL_CONTENT	"bct %d %d %d %d %d %d %d %d %d\n"
# define G_PLAYER_POS	"ppo %d %d %d %d\n"
# define G_PLAYER_LVL	"plv %d %d\n"
# define G_TEAM_NAME	"tna %s\n"
# define G_NEW_PLAYER	"pnw %d %d %d %d %d %s\n"
# define G_FORK_START	"pfk %d\n"
# define G_FORK_END	"enw %d %d %d %d\n"
# define G_HATCH	"eht %d\n"
# define G_PLAYER_TAKE	"pgt %d %d\n"
# define G_PLAYER_DROP	"pdr %d %d\n"
# define G_PLAYER_INV	"pin %d %d %d %d %d %d %d %d %d %d\n"
# define G_PLAYER_BROAD "pbc %d %s\n"
# define G_INCANT_START	"pic %d %d %d %s\n"
# define G_PLAYER_EXP	"pex %d\n"
# define G_PLAYER_DEAD	"pdi %d\n"


typedef enum		e_type
  {
    TYPE_PLAYER = 0,
    TYPE_GRAPHIC,
    TYPE_EGG
  }			t_type;


# define DEFAULT_LIFE	10
# define DEFAULT_LEVEL	1


# define DEFAULT_TIME_UNIT 100
# define DEFAULT_MAX_CLIENTS 1
# define DEFAULT_PORT 4221


# define DEFAULT_MAP_HEIGHT 20
# define DEFAULT_MAP_WIDTH 20


# define USEC 1000000


# define BUFF_SIZE 1024

#endif		
