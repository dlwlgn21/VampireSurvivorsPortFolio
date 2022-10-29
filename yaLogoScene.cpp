#include "yaLogoScene.h"
#include "yaPlayer.h"
#include "yaMeteoManager.h"
#include "yaResources.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaBgImageObject.h"

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
		BgImageObject* bg = new BgImageObject(L"LogoBG.bmp");
		AddGameObject(bg, eColliderLayer::BACKGROUND);
		//Scene::Initialize();
		//MeteoManager::GetInstance().Initialzie();
	}
	void LogoScene::Tick()
	{
		//MeteoManager::GetInstance().Tick();
		// 오브젝트 Tick을 호출한다. 즉 나중에 호출되어야 함.
		if (IS_KEY_UP(eKeyCode::N))
		{
			SceneManager::ChangeSecne(eSceneType::TITLE_SCENE);
		}
		
		Scene::Tick();
	}
	void LogoScene::Render(HDC hdc)
	{
		//MeteoManager::GetInstance().Render(hdc);
		// 마찬가지
		//BitBlt(
		//	hdc,
		//	0,
		//	0,
		//	mpBGImage->GetWidth(),
		//	mpBGImage->GetHeight(),
		//	mpBGImage->GetDC(),
		//	0,
		//	0,
		//	SRCCOPY
		//);

		Scene::Render(hdc);

		wchar_t buffer[64];

		swprintf_s(buffer, 64, L"Logo Scene");
		size_t strLen = wcsnlen_s(buffer, 64);

		TextOut(hdc, 10, 30, buffer, strLen);
	}
	void LogoScene::Enter()
	{
	}
	void LogoScene::Exit()
	{
	}
}