#include <iostream>
#include "GlobalView.hpp"
#include "ProtocolManager.hpp"

namespace			Game
{
  ProtocolManager::ProtocolManager(GlobalView* obj) : obj(obj) {}

  void ProtocolManager::update(std::string& data)
  {
    ProtoMap::iterator		end = this->protoMap.end();
    ProtoMap::iterator		it;
    std::stringstream		ss;

    do { ss.str(data);
      ss.clear();
      ss >> data;
      if ((it = this->protoMap.find(data)) != end)
	(this->obj->*it->second)(ss);
      data = "";
    } while (Core::socket.receive(data));
  }

  void ProtocolManager::update(bool blq)
  {
    std::string			data;

    if (blq)
      while (!Core::socket.receive(data))
	usleep(1);
    else if (!Core::socket.receive(data))
      return ;
    this->update(data);
  }

  void ProtocolManager::manage(std::string const& name, protoFunc func)
  {
    this->protoMap[name] = func;
  }

  void ProtocolManager::unmanage(std::string const& name)
  {
    this->protoMap.erase(name);
  }

  ProtocolManager::~ProtocolManager(void) {}
}
