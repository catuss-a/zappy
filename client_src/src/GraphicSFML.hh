//
// GraphicSFML.hh for nibbler in /home/bianch_g//bubu/AL/nibbler
// 
// Made by ghjuvan-carlu bianchi
// Login   <bianch_g@epitech.net>
// 
// Started on  Wed Mar  9 21:41:02 2011 ghjuvan-carlu bianchi
// Last update Sun Jun 12 17:32:26 2011 ghjuvan-carlu bianchi
//

#ifndef GRAPHICSFML_HH_
# define GRAPHICSFML_HH_

#include <SFML/Graphics.hpp>

#include "IGraphic.hh"
#include "State.hh"

namespace			Nibbler
{
  class				 GraphicSFML : public IGraphic
  {
  private:
    sf::RenderWindow		window;
    sf::Image			*i_snake;
    sf::Image			*i_normalFood;
    sf::Image			*i_goldenFood;
    sf::Image			*i_crappyFood;
    sf::Sprite			*snake;
    sf::Event			*event;
    sf::String			*score;
    const double		winX;
    const double		winY;
    double			width;
    double			height;

    std::map<sf::Key::Code, Nibbler::IGraphic::Event>	mapEvent;
    std::map<FoodBucket::foodType, sf::Sprite>		mapFood;

  private:
    GraphicSFML(GraphicSFML const&);
    GraphicSFML&		operator=(GraphicSFML const&);

    void		drawFood(sf::Sprite& food, State const& state);
    void		initMaps(void);

  public:
    GraphicSFML();
    virtual ~GraphicSFML();

    virtual bool		createWindow(double, double);
    virtual bool		getEvent(Event&);
    virtual void		display(State const&);
  };
}

#endif
