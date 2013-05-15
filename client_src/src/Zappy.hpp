#ifndef				ZAPPY_HPP_
# define			ZAPPY_HPP_

# include "Core.hpp"

class				Zappy
{
public:
  Zappy(char **av);
  virtual ~Zappy(void);

  bool run(void);

private:
  Game::Core			core;

private:
  Zappy(Zappy const&);
  Zappy& operator=(Zappy const&);

  void parse(char **av);
};

#endif
