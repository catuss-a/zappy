#include "Core.hpp"
#include "SceneManager.hpp"

namespace			Game
{
  Core::Core(void) {}

  bool Core::run(Scene::eScene startScene)
  {
    this->launch();
    if (!this->window.IsOpened())
      return (false);
    this->scenes.launch(startScene);
    while (true)
      {
	this->update();
	this->draw();
      }
    this->stop();
  }

  void Core::stop(void)
  {
  }

  void Core::launch(void)
  {
    this->window.launch();
  }

  void Core::update(void)
  {
    this->scenes.update();
  }

  void Core::draw(void)
  {
    this->window.draw();
    this->scenes.draw();
  }

  Core::~Core(void) {}

  Image::AssetManager	Core::assets;
  sf::Event		Core::event;
  sf::Clock		Core::clock;
  sf::Sound		Core::sound;
  Graphics::Window	Core::window;
  Scene::SceneManager	Core::scenes;
  Network::Socket	Core::socket;
}
