#include "yaMonster.h"
#include "yaResources.h"
#include "yaCollider.h"
#include "yaAnimator.h"
#include "yaImage.h"

namespace ya
{
	Monster::Monster()
		: GameObject()
		, mPen(CreatePen(PS_DASHDOTDOT, 3, RGB(0, 255, 255)))
		, mBrush(CreateSolidBrush(RGB(153, 204, 255)))
		, mpImage(nullptr)
	{
		mPos = {500.0f, 500.0f};
		mScale = { 3.0f, 3.0f };
		mpImage = Resources::Load<Image>(L"Monster", L"Resources\\Image\\Monster.bmp");
		assert(mpImage != nullptr);

		AddComponent(new Animator());
		AddComponent(new Collider());
	}
	Monster::~Monster()
	{
	}
	void Monster::Tick()
	{
		GameObject::Tick();
	}
	void Monster::Render(HDC hdc)
	{
		TransparentBlt(
			hdc,
			static_cast<int>(mPos.x - mpImage->GetWidth() * (mScale.x / 2)),
			static_cast<int>(mPos.y - mpImage->GetHeight() * (mScale.y / 2)),
			static_cast<int>(mpImage->GetWidth() * mScale.x),
			static_cast<int>(mpImage->GetHeight() * mScale.y),

			mpImage->GetDC(),
			0, 0,
			mpImage->GetWidth(),
			mpImage->GetHeight(),
			RGB(255, 0, 255)
		);

		GameObject::Render(hdc);
	}
}