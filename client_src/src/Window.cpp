#include "Window.hpp"
#include "Core.hpp"

namespace			Game
{
  namespace			Graphics
  {
    Window::Window(int width, int height, std::string const& title) :
      width(width), height(height), title(title) {}

    Window::~Window(void) {}

    void Window::launch(void)
    {
      sf::RenderWindow::Create(sf::VideoMode(this->width,
			     this->height), this->title);
    }

    void Window::update(void)
    {
    }

    void Window::draw(void)
    {
      this->Display();
      this->Clear(sf::Color(0, 0, 0));
    }

    int Window::getWidth(void) const
    {
      return (this->width);
    }

    int Window::getHeight(void) const
    {
      return (this->height);
    }
  }
}
