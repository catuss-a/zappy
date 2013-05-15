#ifndef				MUTEX_HH_
# define			MUTEX_HH_

# include <pthread.h>

namespace			Thread
{
  class				CondVar;

  class				Mutex
  {
    friend class CondVar;

  private:
    pthread_mutex_t		mutex;

  public:
    Mutex(void);
    ~Mutex(void);

    void lock(void);
    void unlock(void);
    bool trylock(void);
  };
}

#endif
