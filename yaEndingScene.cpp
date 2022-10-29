#include "yaEndingScene.h"
#include "yaBgImageObject.h"
#include "yaSceneManager.h"
#include "yaImage.h"

namespace ya
{
	EndingScene::EndingScene()
	{
	}
	EndingScene::~EndingScene()
	{
	}
	void EndingScene::Initialize()
	{
		//BgImageObject* bg = new BgImageObject(L"");
		//AddGameObject(bg);
		//SceneManager::Initialze();
	}
	void EndingScene::Tick()
	{
		Scene::Tick();
	}
	void EndingScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t buffer[64];

		swprintf_s(buffer, 64, L"Ending Scene");
		size_t strLen = wcsnlen_s(buffer, 64);

		TextOut(hdc, 10, 30, buffer, strLen);
	}
	void EndingScene::Enter()
	{
	}
	void EndingScene::Exit()
	{
	}
}