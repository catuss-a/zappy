#include <iostream>

#include "Socket.hpp"

namespace			Network
{
  Socket::Socket(std::string const& protocol) :
    protocol(protocol), fd(-1), epollfd(epoll_create(1))
  {
    bzero(&this->event, sizeof(this->event));
  }

  Socket::~Socket(void)
  {
    this->disconnect();
  }

  bool Socket::connect(std::string const& hostname, int port)
  {
    struct sockaddr_in	client;

    if (this->isConnected())
      this->disconnect();
    if ((this->fd = getSocket(this->protocol)) == -1)
      {this->error.setError(strerror(errno)); return (false);}
    client.sin_addr.s_addr = inet_addr(hostname.c_str());
    client.sin_port = htons(port);
    client.sin_family = AF_INET;
    if (::connect(this->fd, reinterpret_cast<sockaddr*>(&client),
		  sizeof(sockaddr_in)) == -1)
      {
	close(this->fd); this->fd = -1;
	this->error.setError(strerror(errno));
	return (false);
      }
    this->event.events = EPOLLIN;
    epoll_ctl(this->epollfd, EPOLL_CTL_ADD, this->fd, &this->event);
    return (true);
  }

  bool Socket::send(std::string const& stream)
  {
    if (!*this)
      this->disconnect();
    if (!this->isConnected())
      return (false);
    this->ostream += stream;
    this->refresh();
    return (true);
  }

  bool Socket::receive(std::string& stream)
  {
    size_t		found;

    if (!*this)
      this->disconnect();
    if (!this->isConnected())
      return (false);
    this->refresh();
    if (this->istream.empty() ||
	(found = this->istream.find('\n')) == std::string::npos)
      return (false);
    stream = this->istream.substr(0, found);
    this->istream = this->istream.substr(found + 1);
    return (true);
  }

  void Socket::refresh(void)
  {
    int			nbEvent;

    if (!this->ostream.empty())
      {
	this->event.events = EPOLLOUT | EPOLLIN;
	(void)epoll_ctl(this->epollfd, EPOLL_CTL_MOD, this->fd, &this->event);
      }
    if ((nbEvent = epoll_wait(this->epollfd, &this->event, 1, 0)) == -1)
      this->disconnect();
    else if (nbEvent > 0)
      {
	if ((this->event.events & EPOLLIN))
	  this->read();
	if ((this->event.events & EPOLLOUT))
	  {
	    this->write();
	    if (this->ostream.empty())
	      {
		this->event.events = EPOLLIN;
		(void)epoll_ctl(this->epollfd, EPOLL_CTL_MOD, this->fd, &this->event);
	      }
	  }
      }
  }

  int Socket::getSocket(std::string const& protocol)
  {
    protoent		*proto;

    if (!(proto = getprotobyname(protocol.c_str())))
      return (-1);
    return (::socket(AF_INET, SOCK_STREAM, proto->p_proto));
  }

  Socket::operator bool(void) const
  {
    return (!this->isError());
  }

  bool Socket::isConnected(void) const
  {
    return (this->fd != -1);
  }

  void Socket::disconnect(void)
  {
    if (this->isConnected())
      {
	close(this->fd);
	this->fd = -1;
	this->error.setError("Connection closed");
      }
  }

  bool Socket::isError(void) const
  {
    return (this->error);
  }

  std::string const Socket::whatError(void) const
  {
    return (this->error.what());
  }

  void Socket::write(void)
  {
    int			len = this->ostream.size();

    if ((len = ::write(this->fd, this->ostream.c_str(), len)) <= 0)
      {this->error.setError("Connection closed"); return;}
    this->ostream = this->ostream.substr(len);
  }

  void Socket::read(void)
  {
    int			len = 4096;
    char		buffer[4096];

    if ((len = ::read(this->fd, buffer, len)) <= 0)
      {this->error.setError("Connection closed"); return;}
    buffer[len] = 0;
    this->istream += buffer;
  }

  Socket::Error::Error(void) {}

  Socket::Error::~Error(void) {}

  Socket::Error::operator bool(void) const
  {
    return (this->str != "");
  }

  std::string const& Socket::Error::what(void) const
  {
    return (this->str);
  }

  void Socket::Error::setError(std::string const& error)
  {
    this->str = error;
  }
}
