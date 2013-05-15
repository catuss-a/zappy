#ifndef				_EACTIONS_HH
# define			_EACTIONS_HH

////
//
// System includes
//
////

////
//
// Personnal includes
//
////

////
//
// Class
//
////

namespace			Zappy
{
  namespace			Action
  {
    typedef enum		e_eAction
      {
	AVANCE,
	DROITE,
	GAUCHE,
	INVENTAIRE,
	PREND,
	POSE,
	EXPULSE,
	BROADCAST,
	INCANTE,
	FORK,
	CONNECT_NBR,
	VOIR
      }				eAction;
  }
}

#endif
