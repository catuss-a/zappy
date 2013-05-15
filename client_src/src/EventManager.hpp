#ifndef				EVENTMANAGER_HPP_
# define			EVENTMANAGER_HPP_

# include <map>
# include <utility>
# include <SFML/Graphics.hpp>

# include "Core.hpp"

namespace			Game
{
  namespace			Event
  {
    typedef sf::Event::EventType	eEvent;
    typedef sf::Key::Code		eKey;
    typedef sf::Mouse::Button		eMouse;

    template<typename T>
    class			EventManager
    {
    public:
      typedef void (T::*cbEvent)(void);
      typedef void (T::*cbMouse)(int x, int y);
      typedef std::pair<cbEvent, cbMouse>	EventPair;
      typedef std::pair<cbEvent, cbEvent>	KeyPair;
      typedef std::pair<cbMouse, cbMouse>	MousePair;
      typedef std::map<eEvent, EventPair>	EventMap;
      typedef std::map<eKey, KeyPair>		KeyMap;
      typedef std::map<eMouse, MousePair>	MouseMap;
      typedef typename EventMap::iterator	EventIt;
      typedef typename KeyMap::iterator		KeyIt;
      typedef typename MouseMap::iterator	MouseIt;

    public:
      EventManager(T* obj);
      ~EventManager(void);

      void update(void);

      void manage(cbMouse f);
      void manage(eEvent event, cbEvent f);
      void manage(eEvent event, cbMouse f);
      void manage(eKey event, cbEvent press, cbEvent release = 0);
      void manage(eMouse event, cbMouse press, cbMouse release = 0);

    private:
      T*			obj;
      KeyMap			keyMap;
      MouseMap			mouseMap;
      EventMap			eventMap;
      cbMouse			mouse;

    private:
      EventManager(EventManager const&);
      EventManager& operator=(EventManager const&);

      void event(void);
      void keyP(void);
      void keyR(void);
      void mouseP(void);
      void mouseR(void);
    };

#include "EventManager.cpp"

  }
}

#endif
