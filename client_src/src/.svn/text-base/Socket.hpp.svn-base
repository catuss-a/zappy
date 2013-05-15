#ifndef				SOCKET_H_
# define			SOCKET_H_

# include <vector>

# include <string>
# include <unistd.h>
# include <arpa/inet.h>
# include <netdb.h>
# include <errno.h>
# include <string.h>
# include <sys/epoll.h>

namespace			Network
{
  class				Socket
  {
  public:
    class			Error
    {
    public:
      Error(void);
      ~Error(void);

      operator bool(void) const;
      void setError(std::string const& error);
      std::string const& what(void) const;

    private:
      std::string		str;
    };

  public:
    Socket(std::string const& protocol = "TCP");
    ~Socket(void);

    void disconnect(void);
    bool connect(std::string const& hostname, int port = 1234);
    bool send(std::string const& stream);
    bool receive(std::string& stream);
    void refresh(void);

    bool isConnected(void) const;
    bool isError(void) const;
    operator bool(void) const;
    std::string const whatError(void) const;

    static int getSocket(std::string const& protocol = "TCP");

  private:
    Error			error;
    std::string			ostream;
    std::string			istream;
    std::string			protocol;
    int				fd;
    epoll_event			event;
    int				epollfd;
    
  private:
    Socket(Socket const&);
    Socket& operator=(Socket const&);

    void write(void);
    void read(void);
  };
}

#endif
