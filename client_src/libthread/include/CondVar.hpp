//
// CondVar.hh for Thread in /home/bianch_g//SVN/plazza-2014-quilgh_b
// 
// Made by ghjuvan-carlu bianchi
// Login   <bianch_g@epitech.net>
// 
// Started on  Tue Apr 12 17:40:03 2011 ghjuvan-carlu bianchi
// Last update Thu Jun  9 19:48:25 2011 ghjuvan-carlu bianchi
//

#ifndef				CONDVAR_HH_
# define			CONDVAR_HH_

#include <pthread.h>

#include "Mutex.hpp"

namespace			Thread
{
  class				CondVar
  {
  private:
    pthread_cond_t		cond;

  public:
    CondVar(void);
    ~CondVar(void);

    void			wait(Mutex& mutex);
    void			wait(Mutex& mutex, int timeout);
    void			signal(void);
    void			broadcast(void);

  private:
    CondVar(CondVar const&);
    CondVar&			operator=(CondVar const&);
  };
}

#endif
