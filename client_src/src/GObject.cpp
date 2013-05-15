#include "GObject.hpp"
#include "Core.hpp"

namespace			Game
{
  GObject::GObject(Image::eImage image, Coord const& coord)
  {
    this->SetImage(Core::assets[image]);
    this->SetPosition(coord);
  }

  void GObject::launch(void)
  {
  }

  void GObject::update(void)
  {
  }

  void GObject::draw(void)
  {
    Core::window.Draw(*this);
  }

  GObject::~GObject(void) {}
}
