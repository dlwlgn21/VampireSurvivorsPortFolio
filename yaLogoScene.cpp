#include "yaLogoScene.h"
#include "yaPlayer.h"
#include "yaMeteoManager.h"

namespace ya
{
	LogoScene::LogoScene()
	{
	}
	LogoScene::~LogoScene()
	{
	}
	void LogoScene::Initialize()
	{
		AddGameObject(new Player());
		MeteoManager::GetInstance().Initialzie();
	}
	void LogoScene::Tick()
	{
		MeteoManager::GetInstance().Tick();
		// 오브젝트 Tick을 호출한다. 즉 나중에 호출되어야 함.
		Scene::Tick();
	}
	void LogoScene::Render(HDC hdc)
	{
		MeteoManager::GetInstance().Render(hdc);
		// 마찬가지
		Scene::Render(hdc);
	}
}