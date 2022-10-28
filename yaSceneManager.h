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
		static Scene* GetCurrentScene() { return mCurrentScenes; }

	private:
		static Scene* mScenes[static_cast<UINT>(eSceneType::COUNT)];
		static Scene* mCurrentScenes;
	};
}


