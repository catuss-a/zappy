#ifndef				PLAYERVIEW_HPP__
# define			PLAYERVIEW_HPP_

# include <vector>

# include "GObject.hpp"
# include "GlobalView.hpp"

namespace			Game
{
  class				PlayerView : public GObject
  {
  public:
    typedef std::pair<Player*, sf::String>	PlayerPair;
    typedef std::vector<PlayerPair>		PlayerVector;

  public:
    PlayerView(PlayerMap& players);
    virtual ~PlayerView(void);

    virtual void launch(void);
    virtual void update(void);
    virtual void draw(void);

    void setCase(Coord const& gCase);
    Player* getSelectedPlayer(void);
    void selectPlayer(int i);

  private:
    PlayerMap&			players;
    PlayerVector		playerVector;
    GObject*			select;
    Coord			gCase;
    int				idPlayer;

  private:
    PlayerView(PlayerView const&);
    PlayerView& operator=(PlayerView const&);
  };
}

#endif
