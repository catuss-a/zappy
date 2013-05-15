#ifndef				SCOPEDLOCK_HH_
# define			SCOPEDLOCK_HH_

# include <list>
# include <pthread.h>

# include "Mutex.hpp"

namespace			Thread
{
  class				ScopedLock
  {
  private:
    Mutex&			mutex;

  public:
    ScopedLock(Mutex&);
    ~ScopedLock(void);
  };
}

#endif
