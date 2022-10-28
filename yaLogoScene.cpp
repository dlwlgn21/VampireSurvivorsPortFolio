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
		// ������Ʈ Tick�� ȣ���Ѵ�. �� ���߿� ȣ��Ǿ�� ��.
		Scene::Tick();
	}
	void LogoScene::Render(HDC hdc)
	{
		MeteoManager::GetInstance().Render(hdc);
		// ��������
		Scene::Render(hdc);
	}
}