#include "Zappy.hpp"
#include "Launcher.hpp"
#include "GlobalView.hpp"
#include "Core.hpp"

using namespace Game;

Zappy::Zappy(char **av)
{
  Core::scenes.manage<Game::Launcher>();
  Game::Core::scenes.manage<Game::GlobalView>();
  Game::Core::assets.manage(Game::Image::TOOLTIP, "asset/tooltip.png");
  Game::Core::assets.manage(Game::Image::FOOD, "asset/food.png");
  Game::Core::assets.manage(Game::Image::DOFUS1, "asset/dofus1.png");
  Game::Core::assets.manage(Game::Image::DOFUS2, "asset/dofus2.png");
  Game::Core::assets.manage(Game::Image::DOFUS3, "asset/dofus3.png");
  Game::Core::assets.manage(Game::Image::DOFUS4, "asset/dofus4.png");
  Game::Core::assets.manage(Game::Image::DOFUS5, "asset/dofus5.png");
  Game::Core::assets.manage(Game::Image::DOFUS6, "asset/dofus6.png");
  Game::Core::assets.manage(Game::Image::GROUND, "asset/sol.png");
  Game::Core::assets.manage(Game::Image::MULTCASE, "asset/multcase.png");
  Game::Core::assets.manage(Game::Image::CASE, "asset/case.png");
  Game::Core::assets.manage(Game::Image::PLAYERVIEW, "asset/player_view.png");
  Game::Core::assets.manage(Game::Image::SELECTION, "asset/selection.png");
  Game::Core::assets.manage(Game::Image::INVENTORYVIEW, "asset/inventory.png");
  if (av[1])
    Game::Core::socket.connect(av[1], av[2] ? atoi(av[2]) : 4221);
  else
    Game::Core::socket.connect("127.0.0.1", 4221);
}

bool Zappy::run(void)
{
  if (!Game::Core::socket.isConnected())
    {
      std::cerr << Core::socket.whatError() << std::endl;
      return (false);
    }
  return (this->core.run(Game::Scene::GLOBALVIEW));
}

Zappy::~Zappy(void) {}
