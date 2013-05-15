template<typename T>
AScene<T>::AScene(T* obj, eScene id) : events(obj), id(id)
{
  this->events.manage(sf::Event::Closed, &AScene<T>::close);
}

template<typename T>
AScene<T>::~AScene(void) {}

template<typename T>
eScene AScene<T>::getId(void) const
{
  return (this->id);
}

template<typename T>
void AScene<T>::close(void)
{
  exit(EXIT_SUCCESS);
}
