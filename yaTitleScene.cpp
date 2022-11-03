#include "yaTitleScene.h"
#include "yaSceneManager.h"
#include "yaInput.h"
#include "yaBgImageObject.h"
#include "yaBGImageObjectAlpha.h"
#include "yaSceneManager.h"
#include "yaObject.h"
#include "yaButtonImageObject.h"

namespace ya
{
	TitleScene::TitleScene()
		: mSceneType(eSceneType::TITLE_SCENE)
	{
	}
	TitleScene::~TitleScene()
	{
	}
	void TitleScene::Initialize()
	{
		//AddGameObject(new BgImageObject(L"TitleBG.bmp"), eColliderLayer::BACKGROUND);
		//AddGameObject(new BGImageObjectAlpha(L"TitleCharacterBG.bmp"), eColliderLayer::BACKGROUND);
		ya::object::InstantiateAtAnotherScene<BgImageObject>(eColliderLayer::BACKGROUND, L"TitleBG.bmp", GetSceneTpye());
		//ya::object::InstantiateAtAnotherScene<BgImageObject>(eColliderLayer::BACKGROUND, L"TitleCharacterBG.bmp", GetSceneTpye());
		//SceneManager::Initialze() ;
		//ya::object::InstantiateAtAnotherScene<ButtonImageObject>(eColliderLayer::BACKGROUND, L"TitleButton.bmp", GetSceneTpye(), Vector2(600.0f, 200.0f));
		//ya::object::InstantiateAtAnotherScene<ButtonImageObject>(eColliderLayer::BACKGROUND, L"TitleButton.bmp", GetSceneTpye(), Vector2(600.0f, 400.0f));
		//ya::object::InstantiateAtAnotherScene<ButtonImageObject>(eColliderLayer::BACKGROUND, L"TitleButton.bmp", GetSceneTpye(), Vector2(600.0f, 600.0f));

	}
	void TitleScene::Tick()
	{
		Scene::Tick();
		if (IS_KEY_UP(eKeyCode::N))
		{
			SceneManager::ChangeSecne(eSceneType::PLAY_SCENE);
		}
	}
	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);

		wchar_t buffer[64];

		swprintf_s(buffer, 64, L"Title Scene");
		size_t strLen = wcsnlen_s(buffer, 64);

		TextOut(hdc, 10, 30, buffer, strLen);
	}
	void TitleScene::Enter()
	{
	}
	void TitleScene::Exit()
	{
	}
}