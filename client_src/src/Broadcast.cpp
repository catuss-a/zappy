#include "Core.hpp"
#include "Broadcast.hpp"

namespace			Game
{
  Broadcast::Broadcast(void) : timer(10)
  {
    this->SetScale(0.5, 0.5);
  }

  void Broadcast::launch(void) {}

  void Broadcast::update(void)
  {
    --this->timer;
    this->SetPosition(72 * this->gCase.x + Core::window.getWidth() / 2,
		      + 37*this->gCase.y + Core::window.getHeight() / 2);
  }

  void Broadcast::draw(void)
  {
    Core::window.Draw(*this);
  }

  int Broadcast::getTimer(void) const
  {
    return (this->timer);
  }

  void Broadcast::setCase(Coord const& coord)
  {
    this->gCase = coord;
  }

  Broadcast::~Broadcast(void) {}
}
