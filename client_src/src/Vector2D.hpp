#ifndef				VECTOR2D_HPP_
# define			VECTOR2D_HPP_

# include <vector>

namespace			Game
{
  template<typename T>
  class				Vector2D
  {
  public:
    Vector2D(int width = 0, int height = 0);
    ~Vector2D(void);

    T& operator()(int x, int y);
    T& get(int x, int y);

    template<typename U>
    void for_each(U& obj);
    void for_each(void (*func)(T&));
    void for_each(void (*func)(T&, int, int));

    template<typename U>
    void for_each(void (*func)(T&, int, int, U*), U* arg);

    void resize(int width, int height);
    int getWidth(void) const;
    int getHeight(void) const;

  protected:
    int				width;
    int				height;
    std::vector<T>		vector;

  private:
    Vector2D(Vector2D const&);
    Vector2D& operator=(Vector2D const&);
  };

#include "Vector2D.cpp"

}

#endif
