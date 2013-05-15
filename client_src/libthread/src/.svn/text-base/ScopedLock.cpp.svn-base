#include "ScopedLock.hpp"

namespace			Thread
{
  ScopedLock::ScopedLock(Mutex& mutex) :
    mutex(mutex)
  {
    this->mutex.lock();
  }

  ScopedLock::~ScopedLock(void)
  {
    this->mutex.unlock();
  }
}
