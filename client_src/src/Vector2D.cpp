template<typename T>
Vector2D<T>::Vector2D(int width, int height) :
  width(width), height(height), vector(width * height) {}

template<typename T>
Vector2D<T>::~Vector2D(void) {}

template<typename T>
T& Vector2D<T>::operator()(int x, int y)
{
  return (this->vector[y * this->width + x]);
}

template<typename T>
T& Vector2D<T>::get(int x, int y)
{
  return (this->vector[y * this->width + x]);
}

template<typename T>
void Vector2D<T>::for_each(void (*func)(T&))
{
  int		x;

  for (int y = 0; y < this->height; ++y)
    for (x = 0; x < this->width; ++x)
      func(this->get(x, y));
}

template<typename T>
void Vector2D<T>::for_each(void (*func)(T&, int x, int y))
{
  int		x;

  for (int y = 0; y < this->height; ++y)
    for (x = 0; x < this->width; ++x)
      func(this->get(x, y), x, y);
}

template<typename T>
template<typename U>
void Vector2D<T>::for_each(U& obj)
{
  int		x;

  for (int y = 0; y < this->height; ++y)
    for (x = 0; x < this->width; ++x)
      obj(this->get(x, y));
}

template<typename T>
template<typename U>
void Vector2D<T>::for_each(void (*func)(T&, int, int, U*), U* arg)
{
  int		x;

  for (int y = 0; y < this->height; ++y)
    for (x = 0; x < this->width; ++x)
      func(this->get(x, y), x, y, arg);
}

template<typename T>
void Vector2D<T>::resize(int width, int height)
{
  this->width = width;
  this->height = height;
  this->vector.resize(width * height);
}

template<typename T>
int Vector2D<T>::getWidth(void) const
{
  return (this->width);
}

template<typename T>
int Vector2D<T>::getHeight(void) const
{
  return (this->height);
}
