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

		// ������Ʈ Tick�� ȣ���Ѵ�. �� ���߿� ȣ��Ǿ�� ��.
		Scene::Tick();
	}
	void LogoScene::Render(HDC hdc)
	{

		// 
		Scene::Render(hdc);
	}
}