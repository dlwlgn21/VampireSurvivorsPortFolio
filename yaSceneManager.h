#pragma once
#include "Common.h"

namespace ya
{
	class Scene;
	class SceneManager
	{
	public:
		static void Initialze();
		static void Tick();
		static void Render(HDC hdc);
		static void Release();
		static void ChangeSecne(eSceneType scene);
		static void DestroyGameobject();
		static Scene* GetCurrentScene() { return mCurrentScenes; }
		static Scene* GetSpecifiedScene(eSceneType sceneType) { return mScenes[static_cast<UINT>(sceneType)];}

	private:
		static Scene* mScenes[static_cast<UINT>(eSceneType::COUNT)];
		static Scene* mCurrentScenes;
	};
}


