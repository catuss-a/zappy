#include "Socket.hpp"
#include "SocketManager.hpp"

#include <algorithm>
#include <iostream>

namespace		Network
{
  SocketManager::SocketManager(void) : epollfd(epoll_create(1)) {}

  void SocketManager::setEvent(Socket* socket)
  {
    epoll_event		event;

    if (socket->ostream.size())
      {
	bzero(&event, sizeof(event));
	event.events = EPOLLOUT | EPOLLIN;
	event.data.ptr = socket;
	epoll_ctl(this->epollfd, EPOLL_CTL_MOD, socket->fd, &event);
      }
  }

  void SocketManager::unsetEvent(Socket* socket)
  {
    epoll_event		event;

    if (!socket->ostream.size())
      {
	bzero(&event, sizeof(event));
	event.events = EPOLLIN;
	event.data.ptr = socket;
	epoll_ctl(this->epollfd, EPOLL_CTL_MOD, socket->fd, &event);
      }
  }

  void SocketManager::checkEvent(epoll_event const& event)
  {
    iterator		it = this->begin();
    iterator		end = this->end();

    if ((it = find(it, end, event.data.ptr)) != end)
      {
	if ((event.events & EPOLLOUT))
	  {
	    (*it)->write();
	    this->unsetEvent(*it);
	  }
	if ((event.events & EPOLLIN))
	  (*it)->read();
      }
  }

  bool SocketManager::update(void)
  {
    iterator		it = this->begin();
    iterator		end = this->end();
    epoll_event*	events = new epoll_event[this->size()];
    int			nbEvent;

    for (; it != end; ++it)
      this->setEvent(*it);
    if ((nbEvent = epoll_wait(epollfd, events, this->size(), 1)) == -1)
      return (false);
    for (int i = 0; i < nbEvent; ++i)
      this->checkEvent(events[i]);
    delete [] events;
    return (true);
  }

  bool SocketManager::manage(Socket* socket)
  {
    epoll_event		event;

    bzero(&event, sizeof(event));
    event.events = EPOLLIN;
    event.data.ptr = socket;
    if (epoll_ctl(this->epollfd, EPOLL_CTL_ADD,
		  socket->fd, &event) == -1)
      return (false);
    this->push_back(socket);
    return (true);
  }

  void SocketManager::unmanage(Socket* socket)
  {
    epoll_ctl(this->epollfd, EPOLL_CTL_DEL, socket->fd, NULL);
    this->remove(socket);
  }

  SocketManager::operator bool(void)
  {
    return (this->epollfd != -1);
  }

  SocketManager::~SocketManager(void) {}
}
