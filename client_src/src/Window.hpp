#ifndef				WINDOW_HPP_
# define			WINDOW_HPP_

# include <string>
# include <SFML/Graphics.hpp>

# include "IRefresh.hpp"

namespace			Game
{
  namespace			Graphics
  {
    class	Window : public sf::RenderWindow, public IRefresh
    {
    public:
      Window(int width = 1024, int height = 768,
	     std::string const& title = "");
      virtual ~Window(void);

      virtual void launch(void);
      virtual void update(void);
      virtual void draw(void);

      int getWidth(void) const;
      int getHeight(void) const;

    private:
      int			width;
      int			height;
      std::string		title;

    private:
      Window(Window const&);
      Window& operator=(Window const&);
    };
  }
}

#endif
