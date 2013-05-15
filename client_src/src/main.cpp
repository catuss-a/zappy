#include <cstdlib>

#include "Zappy.hpp"

int			main(int, char **av)
{
  try
    {
      Zappy			zappy(av);

      if (!zappy.run())
	return (EXIT_FAILURE);
    }
  catch (std::exception& e)
    {
    std::cerr << e.what() << std::endl;
    }
  catch (...)
    {
      std::cerr << "Internal error" << std::endl;
    }
  return (EXIT_SUCCESS);
}

