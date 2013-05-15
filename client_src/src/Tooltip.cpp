#include <sstream>

#include "Tooltip.hpp"
#include "Core.hpp"

namespace			Game
{
  Tooltip::Tooltip(void) :
    GObject(Image::TOOLTIP), stones(7), labels(8),  x(0), y(0), timer(1)
  {
    this->labels[0].SetScale(0.7, 0.7);
    for (size_t i = 1; i < this->labels.size(); ++i)
      this->labels[i].SetScale(0.6, 0.6);
    this->stones[0] = "Nourriture";
    this->stones[1] = "Linemate";
    this->stones[2] = "Deraumere";
    this->stones[3] = "Sibur";
    this->stones[4] = "Menbiane";
    this->stones[5] = "Phiras";
    this->stones[6] = "Thystane";
  }

  void Tooltip::launch(void) {}

  void Tooltip::update(void)
  {
    if (this->x < 0 || this->x >= this->rx
	|| this->y < 0 || this->y >= this->ry || --this->timer)
      return ;
    std::stringstream	ss;

    ss << "bct ";
    ss << this->x;
    ss << " ";
    ss << this->y;
    ss << "\n";
    Core::socket.send(ss.str());
    this->timer = 50;
  }

  void Tooltip::draw(void)
  {
    if (this->x < 0 || this->x >= this->rx
    	|| this->y < 0 || this->y >= this->ry)
      return ;
    GObject::draw();
    for (size_t i = 0; i < this->labels.size(); ++i)
      Core::window.Draw(this->labels[i]);
  }

  void Tooltip::setStoneQuantity(int i, int val)
  {
    std::stringstream	ss;

    ss << this->stones[i];
    ss << ": ";
    ss << val;
    this->labels[i + 1].SetText(ss.str());
  }

  void Tooltip::setCaseCoord(Coord const& caseCoord)
  {
    std::stringstream	ss;
    int			x = caseCoord.x;
    int			y = caseCoord.y;

    if (this->x != x || this->y != y)
      this->timer = 1;
    this->x = x;
    this->y = y;
    ss << this->x;
    ss << "/";
    ss << this->y;
    this->labels[0].SetText(ss.str());
  }

  Coord Tooltip::getCaseCoord(void) const
  {
    return (Coord(this->x, this->y));
  }

  void Tooltip::setRange(int x, int y)
  {
    this->rx = x;
    this->ry = y;
  }

  void Tooltip::setPosition(int x, int y)
  {
    this->SetPosition(x, y);
    for (size_t i = 0; i < this->labels.size(); ++i)
      this->labels[i].SetPosition(x + 10, y + 25 * i);
  }

  Tooltip::~Tooltip(void) {}
}
