#pragma once
#include "Common.h"


namespace ya
{
	class GameObject;
	class Camera
	{
	public:
		static void Initialize();
		static void Tick();
		static __forceinline Vector2 ToCameraPos(Vector2 pos) { return pos - mDistance; }
		static inline void SetTarget(GameObject* target) { mTarget = target; }


	private:
		Camera() = default;
		~Camera() = default;

	private:
		static Vector2 mResolution;
		static Vector2 mLookPosition;
		static Vector2 mDistance;					// 해상도 중심좌표와 현재 카메라의 간격차이.
		static GameObject* mTarget;
		static float mSpeed;
	};
}

