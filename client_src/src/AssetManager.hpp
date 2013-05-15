#ifndef				ASSETMANAGER_HPP_
# define			ASSETMANAGER_HPP_

# include <map>
# include <SFML/Graphics.hpp>

# include "eImage.hpp"

namespace			Game
{
  namespace			Image
  {
    class			AssetManager
    {
    public:
      AssetManager(void);
      ~AssetManager(void);

      void manage(eImage image, std::string const& location);
      sf::Image& operator[](eImage image);
      sf::Image& get(eImage image);

    private:
      std::map<eImage, sf::Image>		imageMap;

    private:
      AssetManager(AssetManager const&);
      AssetManager& operator=(AssetManager const&);
    };
  }
}

#endif
