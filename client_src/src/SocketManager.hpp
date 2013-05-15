#ifndef			SOCKETMANAGER_HPP_
# define		SOCKETMANAGER_HPP_

# include <list>

namespace		Network
{
  class			Socket;

  class			SocketManager : private std::list<Socket*>
  {
  public:
    SocketManager(void);
    ~SocketManager(void);

    bool update(void);
    bool manage(Socket* socket);
    void unmanage(Socket* socket);

    virtual operator bool(void);

  private:
    int			epollfd;

  private:
    void setEvent(Socket* socket);
    void unsetEvent(Socket* socket);
    void checkEvent(epoll_event const& event);
  };
}

#endif
