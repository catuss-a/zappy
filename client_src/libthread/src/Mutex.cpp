#include "Mutex.hpp"

namespace			Thread
{
  Mutex::Mutex(void)
  {
    pthread_mutex_init(&mutex, NULL);
  }

  Mutex::~Mutex(void)
  {
    pthread_mutex_destroy(&mutex);
  }

  void Mutex::lock(void)
  {
    pthread_mutex_lock(&mutex);
  }

  void Mutex::unlock(void)
  {
    pthread_mutex_unlock(&mutex);
  }

  bool Mutex::trylock(void)
  {
    return (!pthread_mutex_trylock(&mutex));
  }
}
