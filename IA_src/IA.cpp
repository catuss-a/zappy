////
//
// System includes
//
////

#include <cstring>
#include <sstream>
#include <sys/wait.h>
#include <cstdlib>

////
//
// Personnal includes
//
////

#include "IAManager.hpp"
#include "IA.hpp"
#include "eRole.hh"
#include "eMoves.hh"

////
//
// Program code
//
////

namespace		        Zappy
{
  // Static const variables initialization

  // Constructors and Destructors

  IA::IA(IAManager* manager) :
    manager(manager),
    teamName(manager->getTeamName()),
    level(1),
    role(Role::STANDARD),
    fov(4),
    missingItems(8),
    droppingItems(8),
    inventory(8),
    toEat(10),
    readyToIncante(false),
    neededBros(0),
    hookedBy(0),
    mute(false),
    unhook(5),
    winningStreak(0)
  {
    this->mapAction[Action::AVANCE] = &IA::avance;
    this->mapAction[Action::DROITE] = &IA::droite;
    this->mapAction[Action::GAUCHE] = &IA::gauche;
    this->mapAction[Action::VOIR] = &IA::voir;
    this->mapAction[Action::INVENTAIRE] = &IA::inventaire;
    this->mapAction[Action::PREND] = &IA::prend;
    this->mapAction[Action::POSE] = &IA::pose;
    this->mapAction[Action::EXPULSE] = &IA::expulse;
    this->mapAction[Action::BROADCAST] = &IA::broadcast;
    this->mapAction[Action::INCANTE] = &IA::incante;
    this->mapAction[Action::FORK] = &IA::fork;
    this->mapAction[Action::CONNECT_NBR] = &IA::connect_nbr;
    
    this->mapActionValues = IAManager::mapRolesValues[this->role];

    this->missingItems[Items::LINEMATE] = 1;

    this->droppingItems[Items::LINEMATE] = 1;

    this->resetFov(4);
  }

  IA::~IA()
  {

  }

  // Methods

  void					IA::resetFov(int size)
  {
    this->fov.resize(size);

    for (int i = 0; i < size; ++i)
      {
	this->fov[i].resize(8);
	for (int j = 0; j < 8; ++j)
	  this->fov[i][j] = 0;
      }
  }

  void					IA::resetMissingItems(void)
  {
    for (int i = 0; i < 8; ++i)
      this->missingItems[i] = 0;
  }

  void					IA::resetDroppingItems(void)
  {
    for (int i = 0; i < 8; ++i)
      this->droppingItems[i] = 0;
  }

  void					IA::play(bool creator)
  {
    (void)creator;
    if (this->socket.connect("127.0.0.1", 4221))
      {
	while (!this->socket.receive(this->data));
	this->socket.send(this->teamName + "\n");
	while (!this->socket.receive(this->data));
	
	while (!this->socket.receive(this->data));

	std::istringstream iss(this->data, std::istringstream::in);
    
	iss >> this->mapWidth >> this->mapHeight;

	this->socket.send(IAManager::mapActionString[Action::VOIR]);
	while (this->socket.isConnected())
	  {
	    while (this->socket.receive(this->data))
	      {
		if (this->data == "mort")
		  break ;
		this->socket.send(IAManager::mapActionString[this->update(this->data)]);
	      }
	  }
      }
    std::cout << this->socket.whatError() << std::endl;
  }
  
  Action::eAction		       	IA::update(std::string& data)
  {
    return ((this->*mapAction[this->getBetterAction()])(data));
  }

  Action::eAction			IA::getBetterAction(void)
  {
    MapActionCoeff::iterator		it = this->mapActionValues.begin();
    MapActionCoeff::iterator		end = this->mapActionValues.end();
    Action::eAction			currAction;
    coefficient				currActionValue = 0;

    for (; it != end; ++it)
      {
    	if (it->second > currActionValue)
    	  {
    	    currAction = it->first;
    	    currActionValue = it->second;
    	  }
      }
    return (currAction);
  }

  void					IA::move(Moves::eMoves move, int value)
  {
    if (move == Moves::FORWARD)
      this->mapActionValues[Action::AVANCE] += 10000 * value;
    else if (move == Moves::RIGHT)
      this->mapActionValues[Action::DROITE] += 1000 + value;
    else if (move == Moves::LEFT)
      this->mapActionValues[Action::GAUCHE] += 1000 + value;
  }

  void					IA::voirParseFov(std::string& data)
  {
    unsigned int			i = 0;
    int					j = 0;

    this->resetFov(this->fov.size());

    while (i < data.length() && j < 4)
      {
	if (!strncmp(&data.c_str()[i], "linemate", 8))
	  {
	    ++this->fov[j][Items::LINEMATE];
	    i += 8;
	  }
	else if (!strncmp(&data.c_str()[i], "deraumere", 9))
	  {
	    ++this->fov[j][Items::DERAUMERE];
	    i += 9;
	  }
	else if (!strncmp(&data.c_str()[i], "sibur", 5))
	  {
	    ++this->fov[j][Items::SIBUR];
	    i += 5;
	  }
	else if (!strncmp(&data.c_str()[i], "mendiane", 8))
	  {
	    ++this->fov[j][Items::MENDIANE];
	    i += 8;
	  }
	else if (!strncmp(&data.c_str()[i], "phiras", 6))
	  {
	    ++this->fov[j][Items::PHIRAS];
	    i += 6;
	  }
	else if (!strncmp(&data.c_str()[i], "thystame", 8))
	  {
	    ++this->fov[j][Items::THYSTAME];
	    i += 8;
	  }
	else if (!strncmp(&data.c_str()[i], "nourriture", 10))
	  {
	    ++this->fov[j][Items::NOURRITURE];
	    i += 10;
	  }
	else if (!strncmp(&data.c_str()[i], "joueur", 6))
	  {
	    ++this->fov[j][Items::PLAYER];
	    i += 6;
	  }
	else if (!strncmp(&data.c_str()[i], " ", 1))
	  ++i;
	else if (!strncmp(&data.c_str()[i], "{", 1))
	  ++i;
	else if (!strncmp(&data.c_str()[i], "}", 1))
	  ++i;
	else if (!strncmp(&data.c_str()[i], ",", 1))
	  {
	    ++i;
	    ++j;
	  }
	else
	  ++i;
      }
  }

  bool					IA::findItem(Items::eItems item)
  {
    bool				found = false;

    for (unsigned int i = 0; i < this->fov.size(); ++i)
      {
	if (this->fov[i][item] && 
	    ((i == 0 && this->fov[i][Items::PLAYER] == 1) ||
	     (i != 0 && this->fov[i][Items::PLAYER] == 0) ||
	     item == Items::PLAYER))
	  {
	    if (i == 0)
	      {
		if (item == Items::PLAYER && this->fov[0][Items::PLAYER] == 1)
		  continue ;
		this->coordInFov = 0;
	      }
	    else if (i == 1)
	      {
		this->move(Moves::FORWARD, 1);
		this->move(Moves::LEFT, 1);
		this->coordInFov = 1;
	      }
	    else if (i == 2)
	      {
		this->move(Moves::FORWARD, 1);
		this->coordInFov = 2;
	      }
	    else if (i == 3)
	      {
		this->move(Moves::FORWARD, 1);
		this->move(Moves::RIGHT, 1);
		this->coordInFov = 3;
	      }
	    found = true;
	    break ;
	  }
      }
    return (found);
  }

  Items::eItems				IA::getMissingItem(void)
  {
    int					i = 0;

    for (; i < 7 && !(this->missingItems[i]); ++i);
    return ((Items::eItems)i);
  }

  Action::eAction			IA::voir(std::string& data)
  {
    bool				found = false;
    Items::eItems			item;

    this->voirParseFov(data);
    if (this->toEat > 0)
      {
    	if ((found = this->findItem(Items::NOURRITURE)))
	  {
	    this->mapActionValues[Action::PREND] = 1;
	    IAManager::mapActionString[Action::PREND] = "prend " +
	      IAManager::mapItemString[Items::NOURRITURE] + "\n";
	    --this->toEat;
	    this->pickingItem = Items::NOURRITURE;
	  }
      }
    if (!found)
      {
	if ((item = this->getMissingItem()) != Items::PLAYER)
	  {
	    if ((found = this->findItem(item)))
	      {
		this->mapActionValues[Action::PREND] = 1;
		IAManager::mapActionString[Action::PREND] = "prend " +
		  IAManager::mapItemString[item] + "\n";
		this->pickingItem = item;
	      }
	  }
	else if (!this->hookedBy)
	  {
	    found = true;
	    if (this->level == 1)
	      this->levelUpOne();
	  }
      }
    if (!found)
      this->move(Moves::FORWARD, 1);
    return (this->getBetterAction());
  }

  Items::eItems				IA::getFirstOnSquare(void)
  {
    int					i = 0;

    for (; i < 7 && !(this->fov[0][i]); ++i);
    return ((Items::eItems)i);    
  }
  
  Items::eItems				IA::getFirstItemToThrow(void)
  {
    int					i = 0;

    for (; i < 7 && !(this->droppingItems[i]); ++i);    
    return ((Items::eItems)i);
  }

  void					IA::initializeLevelOne(void)
  {
    this->level = 1;
    this->toEat = 10;

    this->mapActionValues = IAManager::mapRolesValues[this->role];

    this->resetMissingItems();
    this->missingItems[Items::LINEMATE] = 1 - this->inventory[Items::LINEMATE];
    if (this->missingItems[Items::LINEMATE] < 0)
      this->missingItems[Items::LINEMATE] = 0;

    this->resetDroppingItems();
    this->droppingItems[Items::LINEMATE] = 1;

    this->readyToIncante = false;

    this->neededBros = 0;

    this->hookedBy = 0;

    this->unhook = 5;

    this->winningStreak = 0;

    this->resetFov(4);
  }

  void					IA::levelUpOne(void)
  {
    this->readyToIncante = true;
    if ((this->pickingItem = this->getFirstOnSquare()) != Items::PLAYER)
      {
	this->mapActionValues[Action::PREND] = 10;
	IAManager::mapActionString[Action::PREND] = "prend " +
	  IAManager::mapItemString[this->pickingItem] + "\n";
      }
    this->mapActionValues[Action::POSE] = 1;
    this->throwingItem = this->getFirstItemToThrow();
    IAManager::mapActionString[Action::POSE] = "pose " +
      IAManager::mapItemString[this->throwingItem] + "\n";
    this->mapActionValues[Action::INCANTE] = 1;
  }

  Action::eAction			IA::prend(std::string& data)
  {
    if (data == "ok")
      {
	this->inventory[this->pickingItem] += 1;
	this->fov[0][this->pickingItem] -= 1;
	if (this->missingItems[this->pickingItem] > 0)
	  --this->missingItems[this->pickingItem];
      }
    if (this->mapActionValues[Action::PREND] == 1)
      this->mapActionValues[Action::PREND] = 0;
    else if (this->mapActionValues[Action::PREND] == 10)
      {
	if ((this->pickingItem = this->getFirstOnSquare()) == Items::PLAYER)
	  this->mapActionValues[Action::PREND] = 0;
	else
	  IAManager::mapActionString[Action::PREND] = "prend " +
	    IAManager::mapItemString[this->pickingItem] + "\n";
      }
    return (this->getBetterAction());
  }

  Action::eAction			IA::pose(std::string& data)
  {
    if (data == "ok")
      {
	this->inventory[this->throwingItem] -= 1;
	this->droppingItems[this->throwingItem] -= 1;
      }
    if ((this->throwingItem = this->getFirstItemToThrow()) == Items::PLAYER)
      this->mapActionValues[Action::POSE] = 0;
    else
      IAManager::mapActionString[Action::POSE] = "pose " +
	IAManager::mapItemString[this->throwingItem] + "\n";      
    return (this->getBetterAction());
  }

  Action::eAction			IA::incante(std::string& data)
  {
    if (data == "ko")
      {
    	if (this->level == 1)
	  this->initializeLevelOne();
      }
    else if (data == "elevation en cours")
      {
	while (!this->socket.receive(this->data)
	       || !strncmp(this->data.c_str(), "message", 7)
	       || (this->data[0] >= '0' && this->data[0] <= '9'));
	if (data == "niveau actuel : 2")
	  {
	    std::cout << "LEVEL UP 2" << std::endl;
	    this->mapActionValues = IAManager::mapRolesValues[Role::STANDARD];
	  }
      }
    return (this->getBetterAction());
  }

  Action::eAction			IA::avance(std::string& data)
  {
    (void)data;
    this->mapActionValues[Action::AVANCE] -= 10000;
    this->mute = false;
    return (this->getBetterAction());
  }

  Action::eAction			IA::droite(std::string& data)
  {
    (void)data;
    this->mapActionValues[Action::DROITE] -= 1000;
    if (this->mapActionValues[Action::DROITE] < 1000)
      {
	this->mapActionValues[Action::AVANCE] = 10000 * this->mapActionValues[Action::DROITE];
	this->mapActionValues[Action::DROITE] = 0;
      }
    return (this->getBetterAction());
  }

  Action::eAction			IA::gauche(std::string& data)
  {
    (void)data;
    this->mapActionValues[Action::GAUCHE] -= 1000;
    if (this->mapActionValues[Action::GAUCHE] < 1000)
      {
	this->mapActionValues[Action::AVANCE] = 10000 * this->mapActionValues[Action::GAUCHE];
	this->mapActionValues[Action::GAUCHE] = 0;
      }
    return (this->getBetterAction());
  }

  Action::eAction			IA::inventaire(std::string& data)
  {
    (void)data;
    return (this->getBetterAction());
  }

  Action::eAction			IA::expulse(std::string& data)
  {
    (void)data;
    return (Action::VOIR);
  }

  Action::eAction			IA::broadcast(std::string& data)
  {
    (void)data;
    return (this->getBetterAction());
  }

  Action::eAction			IA::fork(std::string& data)
  {
    (void)data;
    return (Action::VOIR);
  }

  Action::eAction			IA::connect_nbr(std::string& data)
  {
    (void)data;
    return (Action::VOIR);
  }
}
