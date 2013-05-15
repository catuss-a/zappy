//
// CondVar.cpp for Thread in /home/bianch_g//SVN/plazza-2014-quilgh_b
// 
// Made by ghjuvan-carlu bianchi
// Login   <bianch_g@epitech.net>
// 
// Started on  Tue Apr 12 17:36:41 2011 ghjuvan-carlu bianchi
// Last update Thu Jun  9 19:48:00 2011 ghjuvan-carlu bianchi
//

#include "CondVar.hpp"

namespace			Thread
{
  CondVar::CondVar(void)
  {
    pthread_cond_init(&this->cond, NULL);
  }

  CondVar::~CondVar(void)
  {
    pthread_cond_destroy(&this->cond);
  }

  void			CondVar::wait(Mutex& mutex)
  {
    pthread_cond_wait(&this->cond, &mutex.mutex);
  }

  void			CondVar::wait(Mutex& mutex, int timeout)
  {
    struct timespec		timer;

    timer.tv_sec = timeout;
    pthread_cond_timedwait(&this->cond, &mutex.mutex, &timer);
  }

  void			CondVar::signal(void)
  {
    pthread_cond_signal(&this->cond);
  }

  void			CondVar::broadcast(void)
  {
    pthread_cond_broadcast(&this->cond);
  }
}
