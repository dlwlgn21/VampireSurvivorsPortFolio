#pragma once
#include "Common.h"
#include "yaEntity.h"

namespace ya
{
	class GameObject : public Entity
	{
	public:
		GameObject();
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		inline void SetPos(Vector2 pos) { mPos = pos; }
		inline Vector2 GetPos() { return mPos; }
		inline void SetScale(Vector2 scale) { mScale = scale; }
		inline Vector2 GetScale() { return mScale; }

	protected:
		Vector2 mPos;
		Vector2 mScale;

	};

}

