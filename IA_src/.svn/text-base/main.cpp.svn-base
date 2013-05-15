#include <iostream>
#include <sstream>

#include "IAManager.hpp"

int main(int ac, char **av)
{
  std::string		teamName;

  if (ac == 2)
    {
      teamName = av[1];
      try
	{
	  Zappy::IAManager		manager(teamName);
	  manager.run();
	}
      catch (std::exception& e)
	{
	  std::cerr << e.what() <<std::endl;
	}
      catch (...)
	{
	  std::cerr << "AI has been crushed randomly." << std::endl;
	}
    }
  else
    std::cout << "./IA TeamName" << std::endl;
  return (0);
}
