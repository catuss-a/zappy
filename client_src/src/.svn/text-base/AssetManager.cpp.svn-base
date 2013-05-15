#include "AssetManager.hpp"

namespace			Game
{
  namespace			Image
  {
    AssetManager::AssetManager(void) {}

    AssetManager::~AssetManager(void) {}

    void AssetManager::manage(eImage image, std::string const& location)
    {
      this->imageMap[image].LoadFromFile(location);
    }

    sf::Image& AssetManager::get(eImage image)
    {
      return (this->imageMap[image]);
    }

    sf::Image& AssetManager::operator[](eImage image)
    {
      return (this->imageMap[image]);
    }
  }
}
