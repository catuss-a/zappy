#ifndef				TOOLTIP_HPP_
# define			TOOLTIP_HPP_

# include <vector>

# include "GObject.hpp"

namespace			Game
{
  class				Tooltip : public GObject
  {
  public:
    typedef std::vector<sf::String>	LabelVector;
    typedef std::vector<std::string>	StoneVector;

  public:
    Tooltip(void);
    ~Tooltip(void);

    virtual void launch(void);
    virtual void update(void);
    virtual void draw(void);

    void setStoneQuantity(int i, int val);
    void setCaseCoord(Coord const& caseCoord);
    Coord getCaseCoord(void) const;
    void setPosition(int x, int y);
    void setRange(int x, int y);

  private:
    StoneVector			stones;
    LabelVector			labels;
    int				x;
    int				y;
    int				rx;
    int				ry;
    int				timer;

  private:
    Tooltip(Tooltip const&);
    Tooltip& operator=(Tooltip const&);
  };
}

#endif
