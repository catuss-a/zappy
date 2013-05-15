#include "GlobalView.hpp"
#include "Resource.hpp"
#include "PlayerView.hpp"

namespace			Game
{
  GlobalView::GlobalView(void) :
    Scene::AScene<GlobalView>(this, Scene::GLOBALVIEW), grid(2, 2),
    proto(this), zoom(1), horizon(None), vertical(None), tooltip(0),
    focusedPlayer(NULL), focus(true)
  {
    this->events.manage(sf::Key::Up, &GlobalView::keyUpP,
			&GlobalView::keyUpR);
    this->events.manage(sf::Key::Down, &GlobalView::keyDownP,
			&GlobalView::keyDownR);
    this->events.manage(sf::Key::Left, &GlobalView::keyLeftP,
			&GlobalView::keyLeftR);
    this->events.manage(sf::Key::Right, &GlobalView::keyRightP,
			&GlobalView::keyRightR);
    this->events.manage(sf::Key::Escape, &GlobalView::keyEscape);
    this->events.manage(sf::Mouse::Left, &GlobalView::mouseLeft, NULL);
    this->events.manage(sf::Mouse::Right, &GlobalView::mouseRight, NULL);
    this->events.manage(&GlobalView::mouse);
    this->proto.manage("msz", &GlobalView::msz);
    this->proto.manage("sgt", &GlobalView::sgt);
    this->proto.manage("bct", &GlobalView::bct);
    this->proto.manage("pnw", &GlobalView::pnw);
    this->proto.manage("pdi", &GlobalView::pdi);
    this->proto.manage("seg", &GlobalView::seg);
    this->proto.manage("ppo", &GlobalView::ppo);
    this->proto.manage("tna", &GlobalView::tna);
    this->proto.manage("pin", &GlobalView::pin);
    this->proto.manage("pbc", &GlobalView::pbc);
    this->proto.manage("plv", &GlobalView::plv);
    this->proto.manage("ko", &GlobalView::ko);
    Player::initColors();
  }

  void GlobalView::launch(void)
  {
    std::string		data;

    this->tooltip = new Tooltip;
    this->playerView = new PlayerView(this->players);
    this->inventoryView = new InventoryView;
    while (!Core::socket.receive(data))
      usleep(1);
    if (data != "BIENVENUE")
      std::cerr << "Invalid server" << std::endl;
    Core::socket.send("GRAPHIC\n");
    this->proto.update(true);
    this->tooltip->setRange(this->grid.getWidth(),
			    this->grid.getHeight());
    this->tooltip->setCaseCoord(Coord(-1, -1));
  }

  void GlobalView::update(void)
  {
    if (!Core::socket.isConnected())
      {
	std::cerr << Core::socket.whatError() << std::endl;
	exit(EXIT_FAILURE);
      }
    if (this->focusedPlayer)
      this->focusPlayer();
    this->proto.update();
    this->events.update();
    this->updateView();
    this->tooltip->update();
    this->playerView->update();
    this->inventoryView->update();
  }

  void GlobalView::draw(void)
  {
    this->grid.draw();
    this->drawPlayers();
    this->drawBroadcast();
    this->tooltip->draw();
    this->playerView->draw();
    this->inventoryView->draw();
  }

  void GlobalView::focusPlayer(void)
  {
    Core::window.GetDefaultView().
      SetCenter(this->focusedPlayer->GetPosition());
  }

  void GlobalView::drawPlayers(void)
  {
    PlayerMap::iterator			it = this->players.begin();
    PlayerMap::iterator			end = this->players.end();

    for (; it != end; ++it)
      {
	it->second->update();
	it->second->draw();
      }
  }

  void GlobalView::drawBroadcast(void)
  {
    BroadcastList::iterator		it = this->broadcasts.begin();
    BroadcastList::iterator		end = this->broadcasts.end();

    while (it != end)
      {
	(*it)->update();
	(*it)->draw();
	if (!(*it)->getTimer())
	  {
	    delete *it;
	    it = this->broadcasts.erase(it);
	  }
	else
	  ++it;
      }
  }

  void GlobalView::fillGrid(Case& ocase, int x, int y, GlobalView* p)
  {
    ResourceVector&		resources = ocase.resources;

    ocase.ground = new GridObject(Image::GROUND, p->grid, x, y);
    resources[0] = new Resource(Image::FOOD, p->grid, x, y, 52, 4);
    resources[1] = new Resource(Image::DOFUS1, p->grid, x, y, 4, 4);
    resources[2] = new Resource(Image::DOFUS2, p->grid, x, y, 12, 18);
    resources[3] = new Resource(Image::DOFUS3, p->grid, x, y, 20, 4);
    resources[4] = new Resource(Image::DOFUS4, p->grid, x, y, 28, 18);
    resources[5] = new Resource(Image::DOFUS5, p->grid, x, y, 36, 4);
    resources[6] = new Resource(Image::DOFUS6, p->grid, x, y, 44, 18);
  }

  void GlobalView::msz(std::stringstream& data)
  {
    int			x = 0;
    int			y = 0;

    data >> x;
    data >> y;
    if (x < 0)
      x = 10;
    if (y < 10)
      y = 10;
    this->grid.resize(x, y);
    this->grid.for_each(&fillGrid, this);
  }

  void GlobalView::sgt(std::stringstream& data)
  {
    int			t;

    data >> t;
  }

  void GlobalView::bct(std::stringstream& data)
  {
    int			x = 0;
    int			y = 0;

    data >> x;
    data >> y;

    if (x < 0 || y < 0 || x >= this->grid.getWidth()
	|| y >= this->grid.getHeight())
      return ;

    ResourceVector&	resources = this->grid(x, y).resources;
    Coord		coord = this->tooltip->getCaseCoord();
    int			val = 0;

    for (size_t i = 0; i < resources.size(); ++i)
      {
	data >> val;
	if (x == coord.x && y == coord.y)
	  this->tooltip->setStoneQuantity(i, val);
	resources[i]->setNumber(val);
      }
  }

  void GlobalView::pnw(std::stringstream& data)
  {
    Player*		player;
    int			num;

    data >> num;
    player = new Player(this->grid, num);
    player->setStatus(data);
    this->players[num] = player;
  }

  void GlobalView::pdi(std::stringstream& data)
  {
    int			num;

    data >> num;
    this->players.erase(num);
  }

  void GlobalView::seg(std::stringstream& data)
  {
    int			team;

    data >> team;
    Core::socket.disconnect();
    exit(EXIT_SUCCESS);
  }

  void GlobalView::ppo(std::stringstream& data)
  {
    int			num;
    Coord		coord;
    int			orientation;

    data >> num;

    if (this->players.find(num) == this->players.end())
      return ;

    data >> coord.x;
    data >> coord.y;

    if (coord.x < 0 || coord.y < 0 || coord.x >= this->grid.getWidth()
	|| coord.y >= this->grid.getHeight())
      return ;

    data >> orientation;
    this->players[num]->setCoord(coord);
    this->players[num]->setOrientation(static_cast<eOrientation>(orientation));
  }

  void GlobalView::tna(std::stringstream& data)
  {
    std::string		team;

    data >> team;
    Player::setNewTeamColor(team);
  }

  void GlobalView::pin(std::stringstream& data)
  {
    int			num;
    int			x;

    data >> num;

    if (this->players.find(num) == this->players.end())
      return ;

    data >> x;
    data >> x;
    this->players[num]->setInventaire(data);
  }

  void GlobalView::pbc(std::stringstream& data)
  {
    int			num;
    Broadcast*		broadcast = new Broadcast;
    std::string		str;

    data >> num;

    if (this->players.find(num) == this->players.end())
      return ;

    this->broadcasts.push_back(broadcast);
    getline(data, str);
    broadcast->SetText(str);
    broadcast->setCase(this->players[num]->getCoord());
  }

  void GlobalView::plv(std::stringstream& data)
  {
    int			num;
    int			lvl;

    data >> num;

    if (this->players.find(num) == this->players.end())
      return ;

    data >> lvl;
    this->players[num]->setLvl(lvl);
  }

  void GlobalView::ko(std::stringstream&)
  {
    std::cerr << "Connection closed (ko)" << std::endl;
    Core::socket.disconnect();
    exit(1);
  }

  void GlobalView::keyEscape(void)
  {
    exit(EXIT_SUCCESS);
  }

  void GlobalView::mouse(int x, int y)
  {
    Coord	center = Core::window.GetDefaultView().GetCenter();
    int		w = Core::window.getWidth() / 2;
    int		h = Core::window.getHeight() / 2;
    Coord	newCenter = center;;
    Coord	coord;

    if ((!x && !y) || !this->focus)
      return;
    if (x < Core::window.getWidth() / 4)
      center.x -= 15;
    else if (x > Core::window.getWidth() * 5 / 6)
      center.x += 15;
    Core::window.GetDefaultView().SetCenter(center.x, center.y);
    getCaseFromPoint(coord, w, h);
    if (coord.x < 0 || coord.x >= this->grid.getWidth())
      Core::window.GetDefaultView().
	SetCenter((center.x = newCenter.x), newCenter.y);
    if (y < Core::window.getHeight() / 6)
      center.y -= 15;
    else if (y > Core::window.getHeight() * 5 / 6)
      center.y += 15;
    Core::window.GetDefaultView().SetCenter(center.x, center.y);
    getCaseFromPoint(coord, w, h);
    if (coord.y < 0 || coord.y >= this->grid.getHeight())
      Core::window.GetDefaultView().SetCenter(newCenter.x, newCenter.y);
    this->tooltip->setPosition(x - w + center.x, y - h + center.y);
    getCaseFromPoint(coord, x, y);
    this->tooltip->setCaseCoord(coord);
  }

  void GlobalView::keyUpP(void)
  {
    this->setHorizontal(Up);
  }

  void GlobalView::keyDownP(void)
  {
    this->setHorizontal(Down);
  }

  void GlobalView::keyLeftP(void)
  {
    this->setVertical(Left);
  }

  void GlobalView::keyRightP(void)
  {
    this->setVertical(Right);
  }

  void GlobalView::keyUpR(void)
  {
    this->setHorizontal(None);
  }

  void GlobalView::keyDownR(void)
  {
    this->setHorizontal(None);
  }

  void GlobalView::keyLeftR(void)
  {
    this->setVertical(None);
  }

  void GlobalView::keyRightR(void)
  {
    this->setVertical(None);
  }

  void GlobalView::updateView(void)
  {
    sf::Vector2f coord = Core::window.GetDefaultView().GetCenter();

    if (this->vertical == Left)
      coord.x -= 10;
    else if (this->vertical == Right)
      coord.x += 10;
    if (this->horizon == Up)
      coord.y -= 10;
    else if (this->horizon == Down)
      coord.y += 10;
    Core::window.GetDefaultView().SetCenter(coord.x, coord.y);
  }

  void GlobalView::setVertical(eDirection direction)
  {
    this->vertical = direction;
  }

  void GlobalView::setHorizontal(eDirection direction)
  {
    this->horizon = direction;
  }

  void GlobalView::getCaseFromPoint(Coord& caseCoord, int x, int y)
  {
    Coord const& coord = Core::window.GetDefaultView().GetCenter();

    caseCoord.x = (x + coord.x - Core::window.getWidth()) / 72;
    caseCoord.y = (y + coord.y - Core::window.getHeight()) / 37;
    if (caseCoord.x < 0)
      caseCoord.x = -1;
    if (caseCoord.y < 0)
      caseCoord.y = -1;
  }

  void GlobalView::mouseLeft(int x, int y)
  {
    Player*		player;

    if (x > this->playerView->GetSize().x)
      {
	this->focus = true;
	this->inventoryView->setPlayer(NULL);
	this->focusedPlayer = NULL;
	return;
      }
    this->playerView->selectPlayer(y / 30);
    player = this->playerView->getSelectedPlayer();
    this->inventoryView->setPlayer(player);
    this->setFocusOnPlayer(player);
  }

  void GlobalView::mouseRight(int x, int y)
  {
    Coord		caseCoord;

    this->focus = false;
    getCaseFromPoint(caseCoord, x, y);
    x = caseCoord.x;
    y = caseCoord.y;
    caseCoord.x = x;
    caseCoord.y = y;
    this->playerView->setCase(caseCoord);
  }

  void GlobalView::setFocusOnPlayer(Player* player)
  {
    this->focusedPlayer = player;
  }

  GlobalView::~GlobalView(void) {}
}

