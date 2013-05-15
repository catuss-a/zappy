#ifndef				THREAD_HH_
# define			THREAD_HH_

# include <pthread.h>

namespace			Thread
{
  class				Thread
  {
    enum			eStatus
      {
	READY,
	RUNNING,
	DEAD
      };

  private:
    pthread_t			thread;
    eStatus			status;

  public:
    Thread(void);
    ~Thread(void);

    template<typename T>
    static void* function(void *arg)
    {
      (*reinterpret_cast<T*>(arg))();
      return (0);
    }

    template<typename T>
    void launch(T& func)
    {
      if (this->status != RUNNING)
	{
	  this->status = RUNNING;
	  pthread_create(&this->thread, NULL, &this->function<T>, &func);
	}
    }

    template<typename T>
    void launch(void (*func)(T*), T *arg)
    {
      if (this->status != RUNNING)
	{
	  this->status = RUNNING;
	  pthread_create(&this->thread, NULL,
       	  reinterpret_cast<void *(*)(void*)>(func), arg);
	}
    }

    void kill(void);
    void wait(void);
    eStatus getStatus(void) const;
  };
}

#endif
