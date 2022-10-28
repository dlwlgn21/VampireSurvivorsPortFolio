#include "yaPlayer.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaMissile.h"
#include "yaSceneManager.h"
#include "yaScene.h"
#include "yaMeteo.h"

namespace ya
{
	Player::Player()
		: GameObject()
		, mSpeed(500.0f)
	{
		mPos = { 100.0f, 100.0f };
		mScale = { 100.0f, 100.0f };
	}
	Player::~Player()
	{
	}

	void Player::Tick()
	{
		if (IS_KEY_PRESSED(eKeyCode::W))
		{
			mPos.y -= mSpeed * Time::DeltaTime();
		}
		if (IS_KEY_PRESSED(eKeyCode::S))
		{
			mPos.y += mSpeed * Time::DeltaTime();
		}
		if (IS_KEY_PRESSED(eKeyCode::A))
		{
			mPos.x -= mSpeed * Time::DeltaTime();
		}
		if (IS_KEY_PRESSED(eKeyCode::D))
		{
			mPos.x += mSpeed * Time::DeltaTime();
		}
		if (IS_KEY_DOWN(eKeyCode::SPACE))
		{
			Missile* missile = new Missile();
			Scene* currScene = SceneManager::GetCurrentScene();
			currScene->AddGameObject(missile);
			missile->SetPos((GetPos() + (mScale / 2.0f)) - (missile->GetScale() / 2.0f));
		}

		if (IS_KEY_DOWN(eKeyCode::Z))
		{
			Meteo* meteo = new Meteo();
			Scene* currScene = SceneManager::GetCurrentScene();
			currScene->AddGameObject(meteo);
		}
	}

	void Player::Render(HDC hdc)
	{
		Rectangle(hdc,
			static_cast<int>(mPos.x),
			static_cast<int>(mPos.y),
			static_cast<int>(mPos.x + mScale.x),
			static_cast<int>(mPos.y + mScale.y)

		);
	}
}