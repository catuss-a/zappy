#ifndef				CORE_HPP_
# define			CORE_HPP_

# include <SFML/Graphics.hpp>
# include <SFML/Audio.hpp>
# include <iostream>

# include "IRefresh.hpp"
# include "Window.hpp"
# include "Socket.hpp"
# include "eScene.hpp"
# include "SceneManager.hpp"
# include "AssetManager.hpp"

namespace			Game
{
  class				Core : public IRefresh
  {
  public:
    Core(void);
    virtual ~Core(void);

    bool run(Scene::eScene startScene);
    void stop(void);

    virtual void launch(void);
    virtual void update(void);
    virtual void draw(void);

  public:
    static sf::Sound		sound;
    static sf::Clock		clock;
    static sf::Event		event;
    static Image::AssetManager	assets;
    static Graphics::Window	window;
    static Scene::SceneManager	scenes;
    static Network::Socket	socket;

  private:
    Core(Core const&);
    Core& operator=(Core const&);
  };
}

#endif
