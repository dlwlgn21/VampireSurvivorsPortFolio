#include <cassert>
#include "Common.h"
#include "yaPlayer.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaMissile.h"
#include "yaSceneManager.h"
#include "yaScene.h"
#include "yaMeteo.h"
#include "yaImage.h"
#include "yaResources.h"
#include "yaAnimator.h"
#include "yaCollider.h"

namespace ya
{
	Player::Player()
		: GameObject()
		, mSpeed(500.0f)
		, mPen(CreatePen(PS_DASHDOTDOT, 3, RGB(0, 255, 255)))
		, mBrush(CreateSolidBrush(RGB(153, 204, 255)))
		, mImage(nullptr)
	{
		mPos = Vector2::ZERO;
		mScale = { 3.0f, 3.0f };
		mImage = Resources::Load<Image>(L"Player", L"Resources\\Image\\Player.bmp");
		assert(mImage != nullptr);

		AddComponent(new Animator());
		AddComponent(new Collider());
	}
	Player::~Player()
	{
	}

	void Player::Tick()
	{
		GameObject::Tick();
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
			currScene->AddGameObject(missile, eColliderLayer::PLAYER_PROJECTTILE);
			missile->SetPos((GetPos() + (mScale / 2.0f)) - (missile->GetScale() / 2.0f));
		}

		if (IS_KEY_DOWN(eKeyCode::Z))
		{
			Meteo* meteo = new Meteo();
			Scene* currScene = SceneManager::GetCurrentScene();
			currScene->AddGameObject(meteo, eColliderLayer::PLAYER_PROJECTTILE);
		}
	}

	void Player::Render(HDC hdc)
	{
		Pen	pen(hdc, mPen);
		Brush brush(hdc, mBrush);

		//Rectangle(hdc,
		//	static_cast<int>(mPos.x),
		//	static_cast<int>(mPos.y),
		//	static_cast<int>(mPos.x + mScale.x),
		//	static_cast<int>(mPos.y + mScale.y)
		//);

		assert(mImage != nullptr);
		//BitBlt(
		//	hdc,
		//	static_cast<int>(mPos.x),
		//	static_cast<int>(mPos.y),
		//	mImage->GetWidth(),
		//	mImage->GetHeight(),
		//	
		//	mImage->GetDC(),
		//	0,
		//	0,
		//	SRCCOPY
		//);

		TransparentBlt(
			hdc,
			static_cast<int>(mPos.x - mImage->GetWidth() * (mScale.x / 2)),
			static_cast<int>(mPos.y - mImage->GetHeight() * (mScale.y / 2)),
			static_cast<int>(mImage->GetWidth() * mScale.x),
			static_cast<int>(mImage->GetHeight() * mScale.y),

			mImage->GetDC(),
			0, 0,
			mImage->GetWidth(),
			mImage->GetHeight(),
			RGB(255, 0, 255)
		);

		GameObject::Render(hdc);
	}
}