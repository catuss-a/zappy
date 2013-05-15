#ifndef				INVENTORYVIEW_HPP__
# define			INVENTORYVIEW_HPP_

# include <vector>

# include "GObject.hpp"
# include "Player.hpp"

namespace			Game
{
  class				InventoryView : public GObject
  {
  public:
    typedef std::vector<sf::String>	LabelVector;
    typedef std::vector<std::string>	StoneVector;
    typedef std::vector<GObject*>	GObjectVector;

  public:
    InventoryView(void);
    virtual ~InventoryView(void);

    virtual void launch(void);
    virtual void update(void);
    virtual void draw(void);

    void setPlayer(Player* player);

  private:
    Player*			player;
    StoneVector			stones;
    LabelVector			labels;
    GObjectVector		resources;
    int				timer;

  private:
    InventoryView(InventoryView const&);
    InventoryView& operator=(InventoryView const&);
  };
}

#endif
