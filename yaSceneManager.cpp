#include "yaSceneManager.h"
#include "yaLogoScene.h"

namespace ya
{

	Scene* SceneManager::mScenes[static_cast<UINT>(eSceneType::COUNT)] = {};
	Scene* SceneManager::mCurrentScenes = nullptr;

	void SceneManager::Initialze()
	{
		// ��� ������ �ʱ�ȭ
		mScenes[static_cast<UINT>(eSceneType::LOGO_SCENE)] = new LogoScene();
		mScenes[static_cast<UINT>(eSceneType::LOGO_SCENE)]->Initialize();
		mCurrentScenes = mScenes[static_cast<UINT>(eSceneType::LOGO_SCENE)];
	}

	void SceneManager::Tick()
	{
		// ���� ���� update Tick
		mCurrentScenes->Tick();
	}
	void SceneManager::Render(HDC hdc)
	{
		// ���� �� ������
		mCurrentScenes->Render(hdc);
	}
	void SceneManager::Release()
	{
		// ���α׷��� ������ �� �ѹ��� ȣ��
		for (auto* scene : mScenes)
		{
			if (scene == nullptr) { continue; }
			delete scene;
			scene = nullptr;
		}


	}
}