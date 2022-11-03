#include "yaMissile.h"
#include "yaTime.h"
#include "yaCollider.h"
#include "yaCamera.h"

namespace ya
{
	Missile::Missile()
		: GameObject()
		, mSpeed(200.0f)
		, mLifeTime(3.0f)
	{
		SetScale({20.0f, 20.0f});
		AddComponent(new Collider(GetScale()));
	}

	Missile::~Missile()
	{
	}
	void Missile::Tick()
	{
		GameObject::Tick();
		mPos.y -= mSpeed * Time::DeltaTime();
		mLifeTime -= Time::DeltaTime();
		if (mLifeTime <= 0.0f)
		{
			this->DisableObject();
		}
	}

	void Missile::Render(HDC hdc)
	{
		Vector2 pos = Camera::ToCameraPos(mPos);
		Ellipse(
			hdc, 
			static_cast<int>(pos.x - mScale.x),
			static_cast<int>(pos.y - mScale.y),
			static_cast<int>(pos.x + mScale.x),
			static_cast<int>(pos.y + mScale.y)
		);
		GameObject::Render(hdc);

	}
	void Missile::OnCollisionEnter(Collider* other)
	{
		GameObject* object = other->GetOwner();
		object->DisableObject();
		DisableObject();
	}
	void Missile::OnCollisionStay(Collider* other)
	{
	}
	void Missile::OnCollisionExit(Collider* other)
	{
	}
}
