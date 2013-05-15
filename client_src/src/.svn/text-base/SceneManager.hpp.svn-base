#ifndef				SCENEMANAGER_HPP_
# define			SCENEMANAGER_HPP_

# include <map>

# include "eScene.hpp"
# include "IScene.hpp"

namespace			Game
{
  namespace			Scene
  {
    class			SceneManager : public IRefresh
    {
    public:
      typedef std::map<eScene, IScene*>		SceneMap;

    public:
      SceneManager(void);
      virtual ~SceneManager(void);

      virtual void launch(void);
      virtual void update(void);
      virtual void draw(void);

      void launch(eScene scene);

      template<typename T>
      void manage(void)
      {
	T*		obj =new T;

	this->scenes[obj->getId()] = obj;
      }

      template<typename T>
      T* get(eScene scene)
      {
	return (static_cast<T*>(this->scenes[scene]));
      }

      template<typename T>
      T* operator[](eScene scene)
      {
	return (static_cast<T*>(this->scenes[scene]));
      }

    private:
      SceneMap			scenes;
      eScene			currentScene;

    private:
      SceneManager(SceneManager const&);
      SceneManager& operator=(SceneManager const&);
    };
  }
}

#endif
