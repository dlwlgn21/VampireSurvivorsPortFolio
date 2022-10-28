#include "yaSceneManager.h"
#include "yaLogoScene.h"

namespace ya
{

	Scene* SceneManager::mScenes[static_cast<UINT>(eSceneType::COUNT)] = {};
	Scene* SceneManager::mCurrentScenes = nullptr;

	void SceneManager::Initialze()
	{
		// 모든 씬들을 초기화
		mScenes[static_cast<UINT>(eSceneType::LOGO_SCENE)] = new LogoScene();
		mScenes[static_cast<UINT>(eSceneType::LOGO_SCENE)]->Initialize();
		mCurrentScenes = mScenes[static_cast<UINT>(eSceneType::LOGO_SCENE)];
	}

	void SceneManager::Tick()
	{
		// 현재 씬을 update Tick
		mCurrentScenes->Tick();
	}
	void SceneManager::Render(HDC hdc)
	{
		// 현재 씬 렌더링
		mCurrentScenes->Render(hdc);
	}
	void SceneManager::Release()
	{
		// 프로그램을 종료할 떄 한번만 호출
		for (auto* scene : mScenes)
		{
			if (scene == nullptr) { continue; }
			delete scene;
			scene = nullptr;
		}


	}
}