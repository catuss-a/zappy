//
// ASafeContainer.hh for Thread in /home/bianch_g//workspace/SVN/bomberman-2014-quilgh_b/libthread
// 
// Made by ghjuvan-carlu bianchi
// Login   <bianch_g@epitech.net>
// 
// Started on  Sat Jun  4 18:42:02 2011 ghjuvan-carlu bianchi
// Last update Thu Jun  9 19:48:33 2011 ghjuvan-carlu bianchi
//

#ifndef				ASAFECONTAINER_HH_
# define			ASAFECONTAINER_HH_

# include "CondVar.hpp"

namespace			Thread
{
  template<typename T>
  class				ASafeContainer
  {
  public:
    ASafeContainer(void) {}
    virtual ~ASafeContainer(void) {}

    virtual void push(T value) = 0;
    virtual T pop(void) = 0;
    virtual bool tryPop(T* value) = 0;
    virtual int size(void) const = 0;
    virtual bool empty(void) const = 0;

  protected:
    Mutex			mutex;
    CondVar			cond;
  };
}

#endif
