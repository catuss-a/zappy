#ifndef				GRIDOBJECT_HPP
# define			GRIDOBJECT_HPP

# include "GObject.hpp"

namespace			Game
{
  class				Grid;

  class				GridObject : public GObject
  {
  public:
    GridObject(Image::eImage image, Grid& grid,
	       int x, int y, Coord const& coord = Coord());
    virtual ~GridObject(void);

    virtual void launch(void);
    virtual void update(void);
    virtual void draw(void);

    void setCoord(Coord const& coord);
    Coord const& getCoord(void) const;

  protected:
    Grid&			grid;
    Coord			delta;
    Coord			coord;

  private:
    GridObject(GridObject const&);
    GridObject& operator=(GridObject const&);
  };
}

#endif
