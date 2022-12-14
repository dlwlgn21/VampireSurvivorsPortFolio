#pragma once
#include "Common.h"
#include "yaEntity.h"
#include "yaComponent.h"

namespace ya
{
	class Component;
	class Collider;
	class GameObject : public Entity
	{
	public:
		GameObject();
		GameObject(Vector2 pos);
		virtual ~GameObject();

		virtual void Initialize();
		virtual void Tick();
		virtual void Render(HDC hdc);

		virtual void OnCollisionEnter(Collider* other);
		virtual void OnCollisionStay(Collider* other);
		virtual void OnCollisionExit(Collider* other);

		inline void SetPos(Vector2 pos) { mPos = pos; }
		inline Vector2 GetPos() { return mPos; }
		inline void SetScale(Vector2 scale) { mScale = scale; }
		inline Vector2 GetScale() { return mScale; }
		//inline void SetHdc(HDC hdc) { mHdc = hdc; }
		//inline HDC GetHdc() { return mHdc; }
		inline void DisableObject() { mIsAlive = false; }
		inline bool IsAlive() { return mIsAlive; }
		inline void SetDisableTime(float time);
		void AddComponent(Component* component);

		template<typename T>
		__forceinline T* GetComponentOrNull(eComponentType type)
		{
			for (Component* component : mComponents)
			{
				if (component->mType == type)
				{
					return static_cast<T*>(component);
				}
			}
			return nullptr;
		}

	protected:
		std::vector<Component*> mComponents;
		Vector2 mPos;
		Vector2 mScale;
		bool mIsAlive;
		float mDeathTime;
		bool mbDeathTriggerFlag;
		//HDC mHdc;
	};

}

