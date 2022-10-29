#pragma once
#include "Common.h"
#include "def.h"
namespace ya
{
	class Collider;
	class Scene;
	class CollisionManager
	{
	public:
		static void Tick();
		static void SetLayer(eColliderLayer left, eColliderLayer right, bool value);
		static void LayerCollision(Scene* scene, eColliderLayer left, eColliderLayer right);
		static bool Intersect(Collider* left, Collider* right);
	private:
		static WORD mMatrix[MAX_COLLIDER_LAYER];
		static std::bitset<MAX_COLLIDER_LAYER> mBitMatrix;
	};
}

