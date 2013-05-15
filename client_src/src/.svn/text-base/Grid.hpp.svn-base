#ifndef				GRID_HPP_
# define			GRID_HPP_

# include <vector>
# include <list>

# include "IRefresh.hpp"
# include "Vector2D.hpp"
# include "GridObject.hpp"
# include "Resource.hpp"

namespace			Game
{
  typedef std::vector<Resource*>	ResourceVector;
  typedef std::list<GridObject*>	PlayerVector;

  struct			Case
  {
    GridObject*			ground;
    ResourceVector		resources;
    PlayerVector		players;

    Case(void) : ground(0), resources(7) {}
  };

  class	Grid : public Vector2D<Case>, public IRefresh
  {
  public:
    Grid(int width, int height);
    virtual ~Grid(void);

    virtual void launch(void);
    virtual void update(void);
    virtual void draw(void);

  private:
    Grid(Grid const&);
    Grid& operator=(Grid const&);

    static void fdraw(Case& ocase);
    static void fupdate(Case& ocase);
    static void init(Case& ocase);
  };
}

#endif
