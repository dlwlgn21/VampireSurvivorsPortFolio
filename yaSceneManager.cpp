#include "yaSceneManager.h"
#include "yaLogoScene.h"
#include "yaPlayScene.h"
#include "yaTitleScene.h"
#include "yaEndingScene.h"


namespace ya
{

	Scene* SceneManager::mScenes[static_cast<UINT>(eSceneType::COUNT)] = {};
	Scene* SceneManager::mCurrentScenes = nullptr;

	void SceneManager::Initialze()
	{
		// 모든 씬들을 초기화
		mScenes[static_cast<UINT>(eSceneType::LOGO_SCENE)] = new LogoScene();
		mScenes[static_cast<UINT>(eSceneType::LOGO_SCENE)]->Initialize();
		mScenes[static_cast<UINT>(eSceneType::TITLE_SCENE)] = new TitleScene();
		mScenes[static_cast<UINT>(eSceneType::TITLE_SCENE)]->Initialize();
		mScenes[static_cast<UINT>(eSceneType::PLAY_SCENE)] = new PlayScene();
		mScenes[static_cast<UINT>(eSceneType::PLAY_SCENE)]->Initialize();
		mScenes[static_cast<UINT>(eSceneType::ENDING_SCENE)] = new EndingScene();
		mScenes[static_cast<UINT>(eSceneType::ENDING_SCENE)]->Initialize();
		ChangeSecne(eSceneType::LOGO_SCENE);
	}

	void SceneManager::Tick()
	{
		// 현재 씬을 update Tick
		mCurrentScenes->Tick();
	}
	void SceneManager::Render(HDC hdc)
	{
		mCurrentScenes->Render(hdc);
	}
	void SceneManager::Release()
	{
		for (auto* scene : mScenes)
		{
			if (scene == nullptr) { continue; }
			delete scene;
			scene = nullptr;
		}
	}
	void SceneManager::ChangeSecne(eSceneType scene)
	{
		if (mCurrentScenes == nullptr) { mCurrentScenes = mScenes[static_cast<UINT>(eSceneType::LOGO_SCENE)]; }
		else
		{
			mCurrentScenes->Exit();
			mCurrentScenes = mScenes[static_cast<UINT>(scene)];
		}
		mCurrentScenes->Enter();
	}
}