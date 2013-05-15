#include "PlayerView.hpp"
#include "Core.hpp"

namespace			Game
{
  PlayerView::PlayerView(PlayerMap& players) :
    GObject(Image::PLAYERVIEW), players(players), playerVector(20),
    select(new GObject(Image::SELECTION)), idPlayer(0)
  {
    for (size_t i = 0; i < this->playerVector.size(); ++i)
      this->playerVector[i].second.SetScale(0.8, 0.8);
  }

  void PlayerView::launch(void) {}

  void PlayerView::update(void)
  {
    Coord const& coord = Core::window.GetDefaultView().GetCenter();
    PlayerMap::iterator		it = this->players.begin();
    PlayerMap::iterator		end = this->players.end();
    std::stringstream		ss;
    Coord			pos;
    size_t			j;

    pos.x = coord.x - Core::window.getWidth() / 2;
    pos.y = coord.y - Core::window.getHeight() / 2;
    for (j = 0; it != end && j < this->playerVector.size(); ++it)
      if (this->gCase == it->second->getCoord())
	{
	  ss.str("");
	  ss.clear();
	  ss << it->second->getNum();
	  ss << " (";
	  ss << it->second->getTeam();
	  ss << ") [";
	  ss << it->second->getLvl();
	  ss << ']';
	  this->playerVector[j].first = it->second;
	  this->playerVector[j].second.SetText(ss.str());
	  this->playerVector[j].second.SetPosition(10 + pos.x,
						   pos.y + 30 * j);
	  ++j;
	  ss.str("");
	  ss.clear();
	  ss << "plv ";
	  ss << it->second->getNum();
	  ss << "\n";
	  Core::socket.send(ss.str());
	}
    for (; j < this->playerVector.size(); ++j)
      this->playerVector[j].second.SetText("");
    this->SetPosition(pos.x, pos.y);
  }

  void PlayerView::draw(void)
  {
    int			pos = this->select->GetPosition().y;

    GObject::draw();
    for (size_t i = 0; i < this->playerVector.size(); ++i)
      {
	std::string const& str = this->playerVector[i].second.GetText();

	if (!str.empty())
	  {
	    Core::window.Draw(this->playerVector[i].second);
	    if (this->playerVector[i].second.GetPosition().y == pos)
	      this->select->draw();
	  }
      }
  }

  Player* PlayerView::getSelectedPlayer(void)
  {
    std::string	player = this->playerVector[this->idPlayer].
      second.GetText();

    return (player.empty() ? NULL :
	    this->playerVector[this->idPlayer].first);
  }

  void PlayerView::setCase(Coord const& gCase)
  {
    this->gCase = gCase;
  }

  void PlayerView::selectPlayer(int i)
  {
    Coord const& coord = Core::window.GetDefaultView().GetCenter();

    this->idPlayer = i;
    this->select->SetPosition(coord.x - Core::window.getWidth() / 2 + 1,
	      coord.y - Core::window.getHeight() / 2 + 30 * i);
  }

  PlayerView::~PlayerView(void) {}
}

