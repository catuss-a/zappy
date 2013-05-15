#ifndef				BROADCAST_HPP_
# define			BROADCAST_HPP_

# include <sstream>
# include <SFML/Graphics.hpp>

# include "GObject.hpp"
# include "IRefresh.hpp"

namespace		Game
{
  class			Broadcast : public sf::String, public IRefresh
  {
  public:
    Broadcast(void);
    virtual ~Broadcast(void);

    virtual void launch(void);
    virtual void update(void);
    virtual void draw(void);

    void setCase(Coord const& coord);
    int getTimer(void) const;

  private:
    int			timer;
    Coord		gCase;

  private:
    Broadcast(Broadcast const&);
    Broadcast& operator=(Broadcast const&);
  };
}

#endif
