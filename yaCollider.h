#pragma once
#include "yaComponent.h"

namespace ya
{
	class Collider : public Component
	{
	public:
		Collider();
		~Collider();

		virtual void Tick() override;
		virtual void Render(HDC hdc) override;

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

	};
}