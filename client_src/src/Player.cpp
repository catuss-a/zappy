#include <sstream>
#include <iostream>

#include "Player.hpp"

namespace			Game
{
  Player::Player(Grid& grid, int num) :
    GridObject(Image::CASE, grid, 0, 0), num(num), inventory(7)
  {
    setNewTeamColor(this->team);
    this->SetColor(this->teamColors[this->team]);
  }

  void Player::launch(void) {}
  void Player::update(void) {GridObject::update();}
  void Player::draw(void) {GridObject::draw();}

  void Player::setStatus(std::stringstream& data)
  {
    int			orientation;

    data >> this->coord.x;
    data >> this->coord.y;
    data >> orientation;
    data >> this->lvl;
    data >> this->team;
    this->orientation = static_cast<eOrientation>(orientation);
  }

  void Player::setOrientation(eOrientation orientation)
  {
    this->orientation = orientation;
  }

  void Player::setLvl(int lvl)
  {
    this->lvl = lvl;
  }

  void Player::setInventaire(std::stringstream& data)
  {
    int			len = this->inventory.size();
    Coord		caseCoord;
    int			val;

    for (int i = 0; i < len; ++i)
      {
	data >> val;
	inventory[i] = val;
      }
  }

  int Player::getNum(void) const
  {
    return (this->num);
  }

  int Player::getLvl(void) const
  {
    return (this->lvl);
  }

  std::string const& Player::getTeam(void) const
  {
    return (this->team);
  }

  InventoryVector const& Player::getInventory(void) const
  {
    return (this->inventory);
  }

  void Player::initColors(void)
  {
    idColor = 0;
    colors.resize(15);
    colors[0] = sf::Color(255, 0, 0);
    colors[1] = sf::Color(255, 255, 0);
    colors[2] = sf::Color(255, 0, 255);
    colors[3] = sf::Color(0, 255, 0);
    colors[4] = sf::Color(0, 255, 255);
    colors[5] = sf::Color(0, 0, 255);
    colors[6] = sf::Color(120, 0, 0);
    colors[7] = sf::Color(120, 255, 0);
    colors[8] = sf::Color(120, 0, 255);
    colors[9] = sf::Color(255, 120, 0);
    colors[10] = sf::Color(0, 120, 0);
    colors[11] = sf::Color(0, 120, 255);
    colors[12] = sf::Color(255, 0, 120);
    colors[13] = sf::Color(0, 255, 120);
    colors[14] = sf::Color(0, 0, 120);
  }

  void Player::setNewTeamColor(std::string const& team)
  {
    if (teamColors.find(team) != teamColors.end())
      return ;
    if (++idColor > colors.size())
      idColor = 0;
    teamColors[team] = colors[idColor];
  }

  Player::~Player(void) {}

  std::map<std::string, sf::Color>	Player::teamColors;
  std::vector<sf::Color>		Player::colors;
  size_t				Player::idColor;
}
