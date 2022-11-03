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
#include "yaCamera.h"
#include "yaBackpack.h"
#include "yaObject.h"

namespace ya
{
	Player::Player()
		: GameObject()
		, mSpeed(500.0f)
		, mPen(CreatePen(PS_DASHDOTDOT, 3, RGB(0, 255, 255)))
		, mBrush(CreateSolidBrush(RGB(153, 204, 255)))
		, mImage(nullptr)
	{
		SetName(L"Player");
		mPos = {500.0f, 500.0f};
		mScale = { 3.0f, 3.0f };
		mImage = Resources::Load<Image>(L"Player", L"Resources\\Image\\Player.bmp");
		assert(mImage != nullptr);

		AddComponent(new Animator());
		AddComponent(new Collider());
		Camera::SetTarget(this);
	}
	Player::Player(Vector2 pos)
		: GameObject()
		, mSpeed(500.0f)
		, mPen(CreatePen(PS_DASHDOTDOT, 3, RGB(0, 255, 255)))
		, mBrush(CreateSolidBrush(RGB(153, 204, 255)))
		, mImage(nullptr)
	{
		SetName(L"Player");
		mPos = pos;
		mScale = { 3.0f, 3.0f };
		mImage = Resources::Load<Image>(L"Player", L"Resources\\Image\\Player.bmp");
		assert(mImage != nullptr);

		AddComponent(new Animator());
		AddComponent(new Collider());
		Camera::SetTarget(this);
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
			Missile* missile = ya::object::Instantiate<Missile>(eColliderLayer::PLAYER_PROJECTTILE);
			missile->SetPos((GetPos() + (mScale / 2.0f)) - (missile->GetScale() / 2.0f));
		}
		if (IS_KEY_DOWN(eKeyCode::I))
		{
			Scene* currScene = SceneManager::GetCurrentScene();
			currScene->AddGameObject(new Backpack(), eColliderLayer::BACKPACK);
		}

	}

	void Player::Render(HDC hdc)
	{
		//Pen	pen(hdc, mPen);
		//Brush brush(hdc, mBrush);

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

	/*	Vector2 fPos; 
		fPos.x = mPos.x - mImage->GetWidth() * (mScale.x / 2);
		fPos.y = mPos.y - mImage->GetWidth() * (mScale.x / 2);
		fPos = Camera::ToCameraPos(fPos);
		TransparentBlt(
			hdc,
			static_cast<int>(fPos.x),
			static_cast<int>(fPos.y),
			static_cast<int>(mImage->GetWidth() * mScale.x),
			static_cast<int>(mImage->GetHeight() * mScale.y),

			mImage->GetDC(),
			0, 0,
			mImage->GetWidth(),
			mImage->GetHeight(),
			RGB(255, 0, 255)
		);*/
		
		GameObject::Render(hdc);
	} 


	void Player::OnCollisionEnter(Collider* other)
	{

	}
	void Player::OnCollisionStay(Collider* other)
	{

	}
	void Player::OnCollisionExit(Collider* other)
	{

	}
}