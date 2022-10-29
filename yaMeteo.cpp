#include "yaMeteo.h"
#include "yaTime.h"
#include "Utility.h"

namespace ya
{

	Meteo::Meteo()
		: GameObject()
		, mFallSpeed(static_cast<float>(yaClamp(rand() % MAX_FALL_SPEED, MIN_FALL_SPEED, MAX_FALL_SPEED)))
		, mRandomPosX(0)
		, mRandomPosY(0)
		, mBrush(CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256)))
		, mPen(CreatePen(PS_DASHDOTDOT, 3, RGB(rand() % 256, rand() % 256, rand() % 256)))
	{
		SetPos({0.0f, 0.0f});
		SetScale({static_cast<float>(WIDTH), static_cast<float>(HEIGHT)});
	}
	Meteo::Meteo(int randomX, int randomY)
		: GameObject()
		, mFallSpeed(static_cast<float>(yaClamp(rand() % MAX_FALL_SPEED, MIN_FALL_SPEED, MAX_FALL_SPEED)))
		, mRandomPosX(randomX)
		, mRandomPosY(randomY)
		, mBrush(CreateSolidBrush(RGB(rand() % 256, rand() % 256, rand() % 256)))
		, mPen(CreatePen(PS_DASHDOTDOT, 3, RGB(rand() % 256, rand() % 256, rand() % 256)))
	{
		SetPos({ static_cast<float>(randomX), static_cast<float>(randomY) });
		SetScale({ static_cast<float>(WIDTH), static_cast<float>(HEIGHT)});
	}
	void Meteo::Tick()
	{
		mPos.y += mFallSpeed * Time::DeltaTime();
	}
	void Meteo::Render(HDC hdc)
	{
		Pen pen(hdc, mPen);
		Brush brush(hdc, mBrush);
		Ellipse(
			hdc,
			static_cast<int>(mPos.x),
			static_cast<int>(mPos.y),
			static_cast<int>(mPos.x + mScale.x),
			static_cast<int>(mPos.y + mScale.y)
		);
	}
}