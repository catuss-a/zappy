#include <signal.h>
#include "Thread.hpp"

namespace			Thread
{
  Thread::Thread(void) : status(READY) {}

  Thread::~Thread(void) {}

  void Thread::wait(void)
  {
    if (this->status == RUNNING)
      {
	pthread_join(this->thread, NULL);
	this->status = DEAD;
      }
  }

  Thread::eStatus Thread::getStatus(void) const
  {
    return (this->status);
  }

  void Thread::kill(void)
  {
    if (this->status == RUNNING)
      {
	pthread_exit(&this->thread);
	this->status = DEAD;
      }
  }
}
