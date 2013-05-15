#include "GridObject.hpp"
#include "Grid.hpp"
#include "Core.hpp"

namespace			Game
{
  GridObject::GridObject(Image::eImage image, Grid& grid,
			 int x, int y, Coord const& delta) :
    GObject(image), grid(grid), delta(delta), coord(x, y)
  {
    this->update();
  }

  void GridObject::launch(void)
  {
    GObject::launch();
  }

  void GridObject::update(void)
  {
    this->SetPosition(delta.x + 72 * this->coord.x +
		      Core::window.getWidth() / 2, delta.y + 37 *
		      this->coord.y + Core::window.getHeight() / 2);
  }

  void GridObject::draw(void)
  {
    GObject::draw();
  }

  void GridObject::setCoord(Coord const& coord)
  {
    this->coord = coord;
  }

  Coord const& GridObject::getCoord(void) const
  {
    return (this->coord);
  }

  GridObject::~GridObject(void) {}
}
