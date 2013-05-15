#ifndef				PLAYER_HPP_
# define			PLAYER_HPP_

# include "GridObject.hpp"
# include "Resource.hpp"

namespace			Game
{
  enum				eOrientation
    {
      North = 1, East, South, West
    };

  typedef std::vector<Resource*>	ResourceVector;
  typedef std::vector<int>		InventoryVector;

  class				Player : public GridObject
  {
  public:
    Player(Grid& grid, int num);
    ~Player(void);

    virtual void launch(void);
    virtual void update(void);
    virtual void draw(void);

    static void setNewTeamColor(std::string const& team);
    static void initColors(void);

    void setLvl(int lvl);
    void setStatus(std::stringstream& data);
    void setOrientation(eOrientation orientation);
    void setInventaire(std::stringstream& data);
    InventoryVector const& getInventory(void) const;

    int getNum(void) const;
    int getLvl(void) const;
    std::string const& getTeam(void) const;

  protected:
    int			num;
    eOrientation	orientation;
    int			lvl;
    std::string		team;
    InventoryVector	inventory;

  private:
    Player(Player const&);
    Player& operator=(Player const&);

    static std::map<std::string, sf::Color>		teamColors;
    static std::vector<sf::Color>			colors;
    static size_t					idColor;
  };
}

#endif
