#ifndef				GLOBALVIEW_HPP_
# define			GLOBALVIEW_HPP_

# include <sstream>
# include <list>

# include "AScene.hpp"
# include "Grid.hpp"
# include "GridObject.hpp"
# include "ProtocolManager.hpp"
# include "Tooltip.hpp"
# include "Player.hpp"
# include "InventoryView.hpp"
# include "Broadcast.hpp"

namespace			Game
{
  enum				eDirection
    {
      Up, Down, Left, Right, None
    };

  class				PlayerView;

  typedef std::map<int, Player*>		PlayerMap;

  class			GlobalView : public Scene::AScene<GlobalView>
  {
  public:
    typedef void (GlobalView::*protoFunc)(std::string& data);
    typedef std::map<std::string, protoFunc>	ProtoMap;
    typedef std::list<Broadcast*>		BroadcastList;

  public:
    GlobalView(void);
    virtual ~GlobalView(void);

    virtual void launch(void);
    virtual void update(void);
    virtual void draw(void);

    void keyUpP(void);
    void keyDownP(void);
    void keyLeftP(void);
    void keyRightP(void);

    void keyUpR(void);
    void keyDownR(void);
    void keyLeftR(void);
    void keyRightR(void);

    void moveUp(void);
    void moveDown(void);
    void moveLeft(void);
    void moveight(void);

    void keyEscape(void);
    void mouse(int x, int y);
    void mouseLeft(int x, int y);
    void mouseRight(int x, int y);

    void setFocusOnPlayer(Player* player);

  private:
    Grid			grid;
    ProtocolManager		proto;
    float			zoom;
    eDirection			horizon;
    eDirection			vertical;
    Tooltip*			tooltip;
    PlayerMap			players;
    PlayerView*			playerView;
    InventoryView*		inventoryView;
    Player*			focusedPlayer;
    BroadcastList		broadcasts;
    bool			focus;

  private:
    GlobalView(GlobalView const&);
    GlobalView& operator=(GlobalView const&);

    static void fillGrid(Case& ocase, int x, int y, GlobalView* play);
    void setNumber(std::stringstream& data, GridObject* obj);

    void updateView(void);
    void setVertical(eDirection direction);
    void setHorizontal(eDirection direction);
    void getCaseFromPoint(Coord& caseCoord, int x, int y);
    void putTooltip(int x, int y);
    void drawPlayers(void);
    void drawBroadcast(void);
    void focusPlayer(void);

    void msz(std::stringstream& data);
    void sgt(std::stringstream& data);
    void bct(std::stringstream& data);
    void pnw(std::stringstream& data);
    void pdi(std::stringstream& data);
    void seg(std::stringstream& data);
    void ppo(std::stringstream& data);
    void tna(std::stringstream& data);
    void pin(std::stringstream& data);
    void pbc(std::stringstream& data);
    void plv(std::stringstream& data);
    void ko(std::stringstream& data);
  };
}

#endif
