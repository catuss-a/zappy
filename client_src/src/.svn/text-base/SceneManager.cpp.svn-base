#include "SceneManager.hpp"

namespace		Game
{
  namespace		Scene
  {
    SceneManager::SceneManager(void) {}

    SceneManager::~SceneManager(void) {}

    void SceneManager::launch(eScene scene)
    {
      this->currentScene = scene;
      this->launch();
    }

    void SceneManager::launch(void)
    {
      this->scenes[this->currentScene]->launch();
    }

    void SceneManager::update(void)
    {
      this->scenes[this->currentScene]->update();
    }

    void SceneManager::draw(void)
    {
      this->scenes[this->currentScene]->draw();
    }
  }
}
