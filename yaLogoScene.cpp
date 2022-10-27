#include "yaLogoScene.h"
#include "yaPlayer.h"


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
	}
	void LogoScene::Tick()
	{

		// 오브젝트 Tick을 호출한다. 즉 나중에 호출되어야 함.
		Scene::Tick();
	}
	void LogoScene::Render(HDC hdc)
	{

		// 
		Scene::Render(hdc);
	}
}