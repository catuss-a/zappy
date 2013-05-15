////
//
// System includes
//
////

#include <map>
#include <cstdlib>

////
//
// Personnal includes
//
////

#include "IA.hpp"
#include "IAManager.hpp"
#include "eAction.hh"
#include "eRole.hh"

////
//
// Program code
//
////

namespace		        Zappy
{
  std::map<Role::eRole, MapActionCoeff>	    	IAManager::mapRolesValues;
  std::map<Action::eAction, std::string>	IAManager::mapActionString;
  std::map<Items::eItems, std::string>		IAManager::mapItemString;

  // Static const variables initialization

  // Constructors and Destructors

  IAManager::IAManager(std::string& _teamName) :
    teamName(_teamName)
  {
    // Init STANDARD

    mapRolesValues[Role::STANDARD][Action::AVANCE] = 0;
    mapRolesValues[Role::STANDARD][Action::DROITE] = 0;
    mapRolesValues[Role::STANDARD][Action::GAUCHE] = 0;
    mapRolesValues[Role::STANDARD][Action::INVENTAIRE] = 0;
    mapRolesValues[Role::STANDARD][Action::PREND] = 0;
    mapRolesValues[Role::STANDARD][Action::POSE] = 0;
    mapRolesValues[Role::STANDARD][Action::EXPULSE] = 0;
    mapRolesValues[Role::STANDARD][Action::BROADCAST] = 0;
    mapRolesValues[Role::STANDARD][Action::INCANTE] = 0;
    mapRolesValues[Role::STANDARD][Action::FORK] = 0;
    mapRolesValues[Role::STANDARD][Action::CONNECT_NBR] = 0;
    mapRolesValues[Role::STANDARD][Action::VOIR] = 1;

    // Init mapActionString

    mapActionString[Action::AVANCE] = "avance\n";
    mapActionString[Action::DROITE] = "droite\n";
    mapActionString[Action::GAUCHE] = "gauche\n";
    mapActionString[Action::VOIR] = "voir\n";
    mapActionString[Action::INVENTAIRE] = "inventaire\n";
    mapActionString[Action::PREND] = "prend";
    mapActionString[Action::POSE] = "pose";
    mapActionString[Action::EXPULSE] = "expulse\n";
    mapActionString[Action::BROADCAST] = "broadcast texte\n";
    mapActionString[Action::INCANTE] = "incantation\n";
    mapActionString[Action::FORK] = "fork\n";
    mapActionString[Action::CONNECT_NBR] = "connect_nbr\n";

    // Init mapItemString
    
    mapItemString[Items::LINEMATE] = "linemate";
    mapItemString[Items::DERAUMERE] = "deraumere";
    mapItemString[Items::SIBUR] = "sibur";
    mapItemString[Items::MENDIANE] = "mendiane";
    mapItemString[Items::PHIRAS] = "phiras";
    mapItemString[Items::THYSTAME] = "thystame";
    mapItemString[Items::NOURRITURE] = "nourriture";    
  }

  IAManager::~IAManager() {}
 
  // Getters and Setters

  // Operators

  // Member functions
  
  void			IAManager::addIA(void)
  {
    int			pid;

    if ((pid = fork()) == -1)
      exit(1);
    else if (!pid)
      {
	IA		ia(this);

	ia.play(false);
	exit(0);
      }
  }

  void			IAManager::run(void)
  {
    IA			ia(this);

    ia.play(true);
    // waitpid(-1, NULL, 0);
    wait();
  }

  std::string const& IAManager::getTeamName(void) const
  {
    return (this->teamName);
  }
}
