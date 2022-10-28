#include "yaMissile.h"
#include "yaTime.h"
namespace ya
{

	Missile::Missile()
		: GameObject()
		, mSpeed(200.0f)
	{
		SetPos({100.0f, 100.0f});
		SetScale({50.0f, 50.0f});
	}

	Missile::~Missile()
	{
	}

	void Missile::Tick()
	{
		mPos.y -= mSpeed * Time::DeltaTime();
	}

	void Missile::Render(HDC hdc)
	{
		Ellipse(
			hdc, 
			static_cast<int>(mPos.x),
			static_cast<int>(mPos.y),
			static_cast<int>(mPos.x + mScale.x),
			static_cast<int>(mPos.y + mScale.y)
		);
	}
}
