//
// GraphicSFML.cpp for nibbler in /home/bianch_g//bubu/AL/nibbler
// 
// Made by ghjuvan-carlu bianchi
// Login   <bianch_g@epitech.net>
// 
// Started on  Wed Mar  9 21:39:21 2011 ghjuvan-carlu bianchi
// Last update Sun Mar 20 22:37:43 2011 ghjuvan-carlu bianchi
//

#include <iostream>

#include "IGraphic.hh"
#include "Event.hh"
#include "Snake.hh"
#include "FoodBucket.hh"
#include "State.hh"
#include "GraphicSFML.hh"

extern "C" Nibbler::IGraphic	*getInstance(void)
{
  return (new Nibbler::GraphicSFML());
}

Nibbler::GraphicSFML::GraphicSFML() :
  winX(800), winY(600),
  width(width), height(height)
{
}

Nibbler::GraphicSFML::~GraphicSFML()
{
  delete this->i_snake;
  delete this->i_normalFood;
  delete this->i_goldenFood;
  delete this->i_crappyFood;
  delete this->snake;
  delete this->event;
  delete this->score;
}

void	Nibbler::GraphicSFML::initMaps()
{
  this->snake->SetImage(*this->i_snake);
  this->mapFood[FoodBucket::NORMAL_FOOD] = sf::Sprite(*this->i_normalFood);
  this->mapFood[FoodBucket::GOLDEN_FOOD] = sf::Sprite(*this->i_goldenFood);
  this->mapFood[FoodBucket::CRAPPY_FOOD] = sf::Sprite(*this->i_crappyFood);
  this->mapEvent[sf::Key::Up] = Nibbler::IGraphic::G_KEY_UP;
  this->mapEvent[sf::Key::Down] = Nibbler::IGraphic::G_KEY_DOWN;
  this->mapEvent[sf::Key::Left] = Nibbler::IGraphic::G_KEY_LEFT;
  this->mapEvent[sf::Key::Right] = Nibbler::IGraphic::G_KEY_RIGHT;
  this->mapEvent[sf::Key::Escape] = Nibbler::IGraphic::G_ESCAPE;
  this->mapEvent[sf::Key::Space] = Nibbler::IGraphic::G_ACCEL;
  this->mapEvent[sf::Key::Return] = Nibbler::IGraphic::G_PAUSE;
  this->snake->Resize(this->width - 4, this->height - 4);
  this->mapFood[FoodBucket::NORMAL_FOOD].Resize(this->width, this->height);
  this->mapFood[FoodBucket::GOLDEN_FOOD].Resize(this->width, this->height);
  this->mapFood[FoodBucket::CRAPPY_FOOD].Resize(this->width, this->height);
  this->score->SetPosition(20, 10);
}

bool	Nibbler::GraphicSFML::createWindow(double width, double height)
{
  if (width < 8 || width > 100 || height < 8 || height > 100)
    {
      std::cerr << "Cannot open the window" << std::endl;
      return (false);
    }
  if (!getenv("XAUTHORITY"))
    return (false);
  this->width = this->winX / width;
  this->height = this->winY / height;
  this->window.Create(sf::VideoMode(this->winX, this->winY, 32), "Nibbler");
  if (!this->window.IsOpened())
    return (false);
  this->i_snake = new sf::Image();
  this->i_normalFood = new sf::Image();
  this->i_goldenFood = new sf::Image();
  this->i_crappyFood = new sf::Image();
  this->snake = new sf::Sprite();
  this->event = new sf::Event();
  this->score = new sf::String();
  if (!this->i_snake->LoadFromFile("./sprites/snake.jpg")
      || !this->i_normalFood->LoadFromFile("./sprites/red_apple.png")
      || !this->i_goldenFood->LoadFromFile("./sprites/gold_apple.png")
      || !this->i_crappyFood->LoadFromFile("./sprites/apple.png"))
    return (false);
  initMaps();
  return (true);
}

bool	Nibbler::GraphicSFML::getEvent(Nibbler::IGraphic::Event& event)
{
  std::map<sf::Key::Code, Nibbler::IGraphic::Event>::iterator	it;

  if (!this->window.GetEvent(*this->event))
    return (false);
  if (this->event->Type == sf::Event::Closed)
    return (event = Nibbler::IGraphic::G_ESCAPE);
  else if (this->event->Type == sf::Event::GainedFocus)
    return (event = Nibbler::IGraphic::G_EXPOSE);
  else if (this->event->Type == sf::Event::LostFocus)
    return (event = Nibbler::IGraphic::G_PAUSE);
  else if (this->event->Type == sf::Event::KeyReleased
	   && this->event->Key.Code == sf::Key::Space)
    return (event = Nibbler::IGraphic::G_DECEL);
  else if (this->event->Type == sf::Event::KeyPressed &&
	   (it = this->mapEvent.find(this->event->Key.Code))
	   != this->mapEvent.end())
    return (event = it->second);
  return (event = Nibbler::IGraphic::G_UNDEF);
}

void	Nibbler::GraphicSFML::drawFood(sf::Sprite& food, State const& state)
{
  food.SetPosition(state.food.getFoodPosition().first * this->width,
		   state.food.getFoodPosition().second * this->height);
  this->window.Draw(food);
}

void	Nibbler::GraphicSFML::display(State const& state)
{
  snakeList::const_iterator	it;

  this->score->SetText(state.snake.getScore().str());
  this->window.Clear(sf::Color(0, 0x80, 0));
  for (it = state.snake.getPosition().begin();
       it != state.snake.getPosition().end(); ++it)
    {
      this->snake->SetPosition(it->first * this->width,
  			      it->second * this->height);
      this->window.Draw(*this->snake);
    }
  drawFood(this->mapFood[state.food.getCurrentFood()], state);
  this->window.Draw(*this->score);
  this->window.Display();
}
