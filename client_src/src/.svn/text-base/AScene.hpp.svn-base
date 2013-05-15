#ifndef				ASCENE_HPP_
# define			ASCENE_HPP_

# include "IScene.hpp"
# include "eScene.hpp"
# include "EventManager.hpp"

namespace			Game
{
  namespace			Scene
  {
    template<typename T>
    class			AScene : public IScene
    {
    public:
      AScene(T* obj, eScene id);
      virtual ~AScene(void);

      virtual void launch(void) = 0;
      virtual void update(void) = 0;
      virtual void draw(void) = 0;

      eScene getId(void) const;

      void close(void);

    protected:
      Event::EventManager<T>	events;
      eScene			id;
    };

#include "AScene.cpp"

  }
}

#endif
