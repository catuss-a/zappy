#ifndef				LAUNCHER_HPP_
# define			LAUNCHER_HPP_

# include "AScene.hpp"

namespace			Game
{
  class	Launcher : public Scene::AScene<Launcher>
  {
  public:
    Launcher(void);
    virtual ~Launcher(void);

    virtual void launch(void);
    virtual void update(void);
    virtual void draw(void);

  private:
    Launcher(Launcher const&);
    Launcher& operator=(Launcher const&);
  };
}

#endif
