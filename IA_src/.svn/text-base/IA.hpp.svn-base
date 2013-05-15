#ifndef				_IA_HPP
# define			_IA_HPP

////
//
// System includes
//
////

#include <iostream>
#include <map>
#include <vector>
#include <utility>

////
//
// Personnal includes
//
////

#include "eItems.hh"
#include "eRole.hh"
#include "eAction.hh"
#include "eMoves.hh"
#include "IAManager.hpp"
#include "Socket.hpp"

////
//
// Class
//
////

namespace			Zappy
{

  typedef std::vector<std::vector<int> >	FieldOfView;
  
  class				IA
  {
  // Typedefs

  public:

    typedef Action::eAction (IA::*ActionFunc)(std::string& data);
    typedef std::map<Action::eAction, ActionFunc> MapAction;
    typedef std::vector<int> MissingItems;
    typedef std::vector<int> DroppingItems;
    typedef std::vector<int> Inventory;
    typedef std::vector<int> DroppedItems;


  // Static const variables
    
  private:

  // Variables
    
  private:

    IAManager			*manager;
    std::string			teamName;
    int				level;
    Role::eRole			role;
    Network::Socket		socket;
    MapAction			mapAction;
    MapActionCoeff		mapActionValues;
    std::string			data;
    FieldOfView			fov;
    int				mapWidth;
    int				mapHeight;
    int				coordInFov;
    MissingItems		missingItems;
    Items::eItems		pickingItem;
    DroppingItems		droppingItems;
    Items::eItems		throwingItem;
    Inventory			inventory;
    int				toEat;
    bool			readyToIncante;
    int				neededBros;
    int				hookedBy;
    bool			mute;
    int				unhook;
    int				winningStreak;

  // Constructors and Destructors

  public:

    IA(IAManager* manager);
    ~IA();

  // Coplien
    
  private:

    IA(IA const&);
    IA&			operator=(IA const&);

  // Getters and Setters

  public:

  // Operators

  public:

  // Member functions

  public:

    void				play(bool creator);
    Action::eAction			handleBroadcast(std::string& data);
    Action::eAction			update(std::string& data);
    void				move(Moves::eMoves move, int value);
    Action::eAction			getBetterAction(void);
    bool				findItem(Items::eItems item);
    Action::eAction			avance(std::string& data);
    Action::eAction			droite(std::string& data);
    Action::eAction			gauche(std::string& data);
    void				voirParseFov(std::string& data);
    Action::eAction			voirStandard(void);
    Action::eAction			voir(std::string& data);
    Action::eAction			inventaire(std::string& data);
    bool				missingItemsEmpty(void);
    Action::eAction			prend(std::string& data);
    Action::eAction			pose(std::string& data);
    Action::eAction		        expulse(std::string& data);
    Action::eAction			broadcast(std::string& data);
    Action::eAction			incante(std::string& data);
    Action::eAction			fork(std::string& data);
    Action::eAction			connect_nbr(std::string& data);
    void				addIA(void);
    void				disconnect(void);

    void				resetFov(int size);
    void				resetMissingItems(void);
    void				resetDroppingItems(void);
    Items::eItems			getMissingItem(void);
    Items::eItems			getFirstOnSquare(void);
    Items::eItems			getFirstItemToThrow(void);
    void				initializeLevelOne(void);
    void				initializeLevelTwo(void);
    void				initializeLevelThree(void);
    void				levelUpOne(void);
    void				levelUpTwo(void);
    void				levelUpThree(void);
  };
}

#endif
