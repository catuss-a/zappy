

#ifndef		MAP_H_
# define	MAP_H_

typedef unsigned int	t_cell[MAX_ITEMS];

typedef struct		s_map
{
  unsigned int		width;
  unsigned int		height;
  unsigned int		nb_cells;
  t_cell		*map;
}			t_map;

#endif		
