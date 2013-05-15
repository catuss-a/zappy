#ifndef				_IAMANAGER_HPP
# define			_IAMANAGER_HPP

////
//
// System includes
//
////

#include <iostream>
#include <list>
#include <map>

////
//
// Personnal includes
//
////

#include "eAction.hh"
#include "eRole.hh"
#include "eItems.hh"

////
//
// Class
//
////

namespace			Zappy
{
  class				IA;

  // Typedefs

  typedef int coefficient;
  typedef std::map<Action::eAction, coefficient> MapActionCoeff;

  class				IAManager
  {
  // Static const variables
    
  private:

  // Variables
    std::string			teamName;

  public:

    static std::map<Role::eRole, MapActionCoeff> mapRolesValues;
    static std::map<Action::eAction, std::string> mapActionString;
    static std::map<Items::eItems, std::string> mapItemString;

  private:

  // Constructors and Destructors

  public:

    IAManager(std::string& teamName);
    ~IAManager();

  // Coplien
    
  private:

    // IAManager(IAManager const&);
    // IAManager&			operator=(IAManager const&);

  public:

  // Getters and Setters
  // Operators

    std::string const& getTeamName(void) const;

  public:

  // Member functions

  public:

    void			addIA(void);
    void			run(void);
  };
}

#endif
