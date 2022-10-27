#include "yaPlayer.h"
#include "yaTime.h"

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
	void Player::Initialize()
	{
	}
	void Player::Tick()
	{
		if (GetAsyncKeyState('W') & 0x8000)
		{
			mPos.y -= mSpeed * Time::DeltaTime();
		}
		if (GetAsyncKeyState('S') & 0x8000)
		{
			mPos.y += mSpeed * Time::DeltaTime();
		}
		if (GetAsyncKeyState('A') & 0x8000)
		{
			mPos.x -= mSpeed * Time::DeltaTime();
		}
		if (GetAsyncKeyState('D') & 0x8000)
		{
			mPos.x += mSpeed * Time::DeltaTime();
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