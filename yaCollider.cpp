#include "yaCollider.h"
#include "yaGameObject.h"
#include "yaApplication.h"

namespace ya
{
	Collider::Collider()
		: Component(eComponentType::COLLIDER)
		, mPos(Vector2::ZERO)
		, mScale(Vector2::ONE)
		, mOffset(Vector2::ZERO)
	{
		mScale = Vector2(100.0f, 100.0f);
	}
	Collider::~Collider()
	{
	}

	void Collider::Tick()
	{
		GameObject* owner = GetOwner();
		mPos = owner->GetPos() + mOffset;

	}
	void Collider::Render(HDC hdc)
	{
		HPEN greenPen = Application::GetInstance().GetPen(ePenColor::GREEN);
		Pen pen(hdc, greenPen);

		HBRUSH transBrush = Application::GetInstance().GetBrush(eBrushColor::TRANS_PARENT);
		Brush brush(hdc, transBrush);

		Rectangle(
			hdc, 
			static_cast<int>(mPos.x - mScale.x / 2), 
			static_cast<int>(mPos.y - mScale.y / 2),
			static_cast<int>(mPos.x + mScale.x / 2),
			static_cast<int>(mPos.y + mScale.y / 2)
		);

	}
}