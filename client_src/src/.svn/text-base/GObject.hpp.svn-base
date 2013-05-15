#ifndef				AGOBJECT_HPP
# define			AGOBJECT_HPP

# include <SFML/Graphics.hpp>

# include "IRefresh.hpp"
# include "eImage.hpp"

namespace			Game
{
  typedef sf::Vector2f		Coord;

  class GObject : public IRefresh, public sf::Sprite
  {
  public:
    GObject(Image::eImage image, Coord const& delta = Coord());
    virtual ~GObject(void);

    virtual void launch(void);
    virtual void update(void);
    virtual void draw(void);

  protected:
    //    SpriteManager		manager;

  private:
    GObject(GObject const&);
    GObject& operator=(GObject const&);
  };
}

#endif
