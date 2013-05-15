#include "Resource.hpp"

namespace			Game
{
  Resource::Resource(Image::eImage image, Grid& grid,
		     int x, int y, int px, int py) :
    GridObject(image, grid, x, y, Coord(px, py)), number(0)
  {
    this->SetScale(0.26, 0.26);
  }

  Resource::~Resource(void) {}

  void Resource::launch(void)
  {
    GridObject::launch();
  }

  void Resource::update(void)
  {
    GridObject::update();
  }

  void Resource::draw(void)
  {
    if (this->number)
      GridObject::draw();
  }

  void Resource::setNumber(int number)
  {
    this->number = number;
  }

  int Resource::getNumber(void) const
  {
    return (this->number);
  }
}
