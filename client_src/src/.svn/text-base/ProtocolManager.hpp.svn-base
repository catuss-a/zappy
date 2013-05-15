#ifndef				PROTOCOLMANAGER_HPP_
# define			PROTOCOLMANAGER_HPP_

# include <sstream>
# include <map>

namespace			Game
{
  class				GlobalView;

  class				ProtocolManager
  {
  public:
    typedef void (GlobalView::*protoFunc)(std::stringstream& data);
    typedef std::map<std::string, protoFunc>	ProtoMap;

  public:
    ProtocolManager(GlobalView *obj);
    ~ProtocolManager(void);

    void update(bool blq = false);
    void manage(std::string const& name, protoFunc func);
    void unmanage(std::string const& name);

  private:
    ProtoMap			protoMap;
    GlobalView*			obj;

  private:
    ProtocolManager(ProtocolManager const&);
    ProtocolManager& operator=(ProtocolManager const&);

    void update(std::string& data);
  };
}

#endif
