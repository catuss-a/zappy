#ifndef				RESOURCE_HPP
# define			RESOURCE_HPP

# include "GridObject.hpp"

namespace			Game
{
  class				Resource : public GridObject
  {
  public:
    Resource(Image::eImage image, Grid& grid,
	     int x, int y, int px, int py);
    virtual ~Resource(void);

    virtual void launch(void);
    virtual void update(void);
    virtual void draw(void);

    void setNumber(int number);
    int getNumber(void) const;

  private:
    int				number;

  private:
    Resource(Resource const&);
    Resource& operator=(Resource const&);
  };
}

#endif
