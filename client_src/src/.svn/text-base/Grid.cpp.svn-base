#include <algorithm>

#include "Grid.hpp"

namespace			Game
{
  Grid::Grid(int width, int height) :
    Vector2D<Case>(width, height) {}

  void Grid::launch(void) {}

  void Grid::update(void)
  {
    this->for_each(&fupdate);
  }

  void Grid::draw(void)
  {
    this->for_each(&fdraw);
  }

  void Grid::fdraw(Case& ocase)
  {
    ResourceVector::iterator it = ocase.resources.begin();
    ResourceVector::iterator end = ocase.resources.end();

    if (ocase.ground)
      ocase.ground->draw();
    for (; it != end; ++it)
      (*it)->draw();
  }

  void Grid::fupdate(Case& ocase)
  {
    ResourceVector::iterator it = ocase.resources.begin();
    ResourceVector::iterator end = ocase.resources.end();

    if (ocase.ground)
      ocase.ground->update();
    for (; it != end; ++it)
      (*it)->update();
  }

  Grid::~Grid(void) {}
}
