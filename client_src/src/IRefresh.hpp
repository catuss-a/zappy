#ifndef				IREFRESH_HPP_
# define			IREFRESH_HPP_

namespace			Game
{
  class				IRefresh
  {
  public:
    virtual ~IRefresh(void) {}

    virtual void launch(void) = 0;
    virtual void update(void) = 0;
    virtual void draw(void) = 0;
  };
}

#endif
