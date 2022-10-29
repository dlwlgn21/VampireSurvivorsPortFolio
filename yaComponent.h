#pragma once
#include "Common.h"
#include "yaEntity.h"
#include "yaGameObject.h"

namespace ya
{
	class GameObject;
	class Component : public Entity
	{
	public:
		friend class GameObject;
		Component(eComponentType type);
		Component() = delete;
		virtual ~Component();

		virtual void Tick() = 0;
		virtual void Render(HDC hdc);
		inline GameObject* GetOwner() { return mOwner; }

	protected:
		const eComponentType mType;
		GameObject* mOwner;
	};
}