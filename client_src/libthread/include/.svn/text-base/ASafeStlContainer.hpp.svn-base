//
// ASafeStlContainer.hh for Thread in /home/bianch_g//workspace/SVN/bomberman-2014-quilgh_b/libthread
// 
// Made by ghjuvan-carlu bianchi
// Login   <bianch_g@epitech.net>
// 
// Started on  Sat Jun  4 18:42:02 2011 ghjuvan-carlu bianchi
// Last update Thu Jun  9 19:48:30 2011 ghjuvan-carlu bianchi
//

#ifndef				ASAFESTLCONTAINER_HH_
# define			ASAFESTLCONTAINER_HH_

# include "ASafeContainer.hpp"
# include "ScopedLock.hpp"

namespace			Thread
{
  template<typename StlContainer>
  class	ASafeStlContainer : public ASafeContainer<typename
				 StlContainer::value_type>,
			    private StlContainer
  {
  public:
    typedef typename StlContainer::value_type T;

  public:
    ASafeStlContainer(void) {}
    virtual ~ASafeStlContainer(void) {}

    virtual void push(T value)
    {
      ScopedLock		lock(this->mutex);

      StlContainer::push_back(value);
      this->cond.signal();
    }

    virtual T pop(void)
    {
      ScopedLock		lock(this->mutex);
      T				value;

      if (StlContainer::empty())
	this->cond.wait(this->mutex);
      value = StlContainer::front();
      StlContainer::pop_front();
      return (value);
    }

    virtual bool tryPop(T* value)
    {
      ScopedLock		lock(this->mutex);

      if (StlContainer::empty())
	return (false);
      *value = StlContainer::front();
      StlContainer::pop_front();
      return (true);
    }

    virtual int size(void) const
    {
      return (StlContainer::size());
    }

    virtual bool empty(void) const
    {
      return (StlContainer::empty());
    }
  };
}

#endif
