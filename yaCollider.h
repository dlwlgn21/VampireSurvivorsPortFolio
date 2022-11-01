#pragma once
#include "yaComponent.h"

namespace ya
{
	class Component;
	class Collider : public Component
	{
	public:
		Collider();
		Collider(Vector2 scale);
		~Collider();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		inline void SetOffset(Vector2 offset) { mOffset = offset; }
		inline void SetPos(Vector2 pos) { mPos = pos; }
		inline void SetScale(Vector2 scale) { mScale = scale; }

		inline Vector2 GetOffset() { return mOffset; }
		inline Vector2 GetPos() { return mPos; }
		inline Vector2 GetScale() { return mScale; }

	private:
		Vector2 mOffset;
		Vector2 mPos;
		Vector2 mScale;

		char mCollisionCount;
	};
}