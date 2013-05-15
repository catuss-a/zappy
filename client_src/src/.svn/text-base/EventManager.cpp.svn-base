template<typename T>
EventManager<T>::EventManager(T* obj) :
  obj(obj), mouse(NULL) {}

template<typename T>
EventManager<T>::~EventManager(void) {}

template<typename T>
void EventManager<T>::event(void)
{
  sf::Event::MouseMoveEvent mouse = Core::event.MouseMove;
  EventIt event = this->eventMap.find(Core::event.Type);

  if (event != this->eventMap.end())
    event->second.first ? (obj->*event->second.first)()
      : (obj->*event->second.second)(mouse.X, mouse.Y);
}

template<typename T>
void EventManager<T>::keyP(void)
{
  KeyIt event = this->keyMap.find(Core::event.Key.Code);

  if (event != this->keyMap.end() && event->second.first)
    (obj->*event->second.first)();
}

template<typename T>
void EventManager<T>::keyR(void)
{
  KeyIt event = this->keyMap.find(Core::event.Key.Code);

  if (event != this->keyMap.end() && event->second.second)
    (obj->*event->second.second)();
}

template<typename T>
void EventManager<T>::mouseP(void)
{
  sf::Event::MouseButtonEvent& mouse = Core::event.MouseButton;
  MouseIt event = this->mouseMap.find(Core::event.MouseButton.Button);

  if (event != this->mouseMap.end() && event->second.first)
    (obj->*event->second.first)(mouse.X, mouse.Y);
}

template<typename T>
void EventManager<T>::mouseR(void)
{
  sf::Event::MouseButtonEvent& mouse = Core::event.MouseButton;
  MouseIt event = this->mouseMap.find(Core::event.MouseButton.Button);

  if (event != this->mouseMap.end() && event->second.second)
    (obj->*event->second.second)(mouse.X, mouse.Y);
}

template<typename T>
void EventManager<T>::update(void)
{
  if (mouse)
    (this->obj->*mouse)(Core::window.GetInput().GetMouseX(),
			Core::window.GetInput().GetMouseY());
  while (Core::window.GetEvent(Core::event))
    {
      if (Core::event.Type == sf::Event::KeyPressed)
	this->keyP();
      else if (Core::event.Type == sf::Event::KeyReleased)
	this->keyR();
      else if (Core::event.Type == sf::Event::MouseButtonPressed)
	this->mouseP();
      else if (Core::event.Type == sf::Event::MouseButtonReleased)
	this->mouseR();
      else
	this->event();
    }
}

template<typename T>
void EventManager<T>::manage(eEvent event, cbEvent f)
{
  this->eventMap[event] = EventPair(f, 0);
}

template<typename T>
void EventManager<T>::manage(eEvent event, cbMouse f)
{
  this->eventMap[event] = EventPair(0, f);
}

template<typename T>
void EventManager<T>::manage(eKey event, cbEvent press, cbEvent release)
{
  this->keyMap[event] = KeyPair(press, release);
}

template<typename T>
void EventManager<T>::manage(eMouse event, cbMouse press, cbMouse release)
{
  this->mouseMap[event] = MousePair(press, release);
}

template<typename T>
void EventManager<T>::manage(cbMouse mouse)
{
  this->mouse = mouse;
}
