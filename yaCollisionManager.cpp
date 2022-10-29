#include "yaCollisionManager.h"
#include "yaScene.h"
#include "yaSceneManager.h"
#include "yaGameObject.h"
#include "yaCollider.h"

namespace ya
{
	WORD CollisionManager::mMatrix[MAX_COLLIDER_LAYER] = {0,};
	std::bitset<MAX_COLLIDER_LAYER> CollisionManager::mBitMatrix = {0,};

	void CollisionManager::Tick()
	{
		Scene* currScene = SceneManager::GetCurrentScene();
		for (int i = 0; i < MAX_COLLIDER_LAYER; ++i)
		{
			for (int j = 0; j < MAX_COLLIDER_LAYER; ++j)
			{
				if (mMatrix[i] & (1 << j))
				{
					// 충돌이 되었는지 안되었는지를 검사해줘야 한다.
					LayerCollision(currScene, 
						static_cast<eColliderLayer>(i), 
						static_cast<eColliderLayer>(j)
					);
				}
			}
		}
	}
	void CollisionManager::SetLayer(eColliderLayer left, eColliderLayer right, bool value)
	{
		// 무조건 한 쪽만 쓰기 위해서. 즉 반절만 쓰기 위해서
		// 더 작은 숫자를 행으로, 더 큰 숫자를 열로
		UINT row = 0;
		UINT col = 0;

		UINT iLeft = static_cast<UINT>(left);
		UINT iRight = static_cast<UINT>(right);

		row = iLeft;
		col = iRight;
		
		if (iRight <= iLeft)
		{
			row = iRight;
			col = iLeft;
		}

		if (value == true)	{ mMatrix[row] |= (1 << col); }
		else				{ mMatrix[row] &= ~(1 << col); }

		/*if (value == true)	{ mBitMatrix[row] |= (0x1 << col); }
		else				{ mBitMatrix[row] &= ~(0x1 << col); }*/
	}

	void CollisionManager::LayerCollision(Scene* scene, eColliderLayer left, eColliderLayer right)
	{
		// 모든 left 오브젝트들과 right 오브젝트들을 가져와 비교해주어야 함.
		std::vector<GameObject*>& lefts = scene->GetSpecifiedLayerGameObjects(left);
		std::vector<GameObject*>& rights = scene->GetSpecifiedLayerGameObjects(right);
		Collider* chcheLeft;
		Collider* cacheRight;

		for (auto* leftObject : lefts)
		{
			chcheLeft = leftObject->GetComponent<Collider>(eComponentType::COLLIDER);
			if (chcheLeft == nullptr)		{ continue; }
			
			for (auto* rightObject : rights)
			{
				cacheRight = rightObject->GetComponent<Collider>(eComponentType::COLLIDER);
				if (cacheRight == nullptr)	{ continue; }
				if (leftObject == rightObject || chcheLeft == cacheRight) { continue; }

				if (Intersect(chcheLeft, cacheRight))
				{
					MessageBox(nullptr, L"Collision!", L"Collision!", MB_OK);
				}
				else
				{
					// NO collision
				}
			}
		}

		
	}
	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Vector2 leftPos = left->GetPos();
		Vector2 leftScale = left->GetScale();
		Vector2 rightPos = right->GetPos();
		Vector2 rightScale = right->GetScale();

		if (fabs(leftPos.x - rightPos.x) < fabs(leftScale.x / 2 + rightScale.x / 2) &&
			fabs(leftPos.y - rightPos.y) < fabs(leftScale.y / 2 + rightScale.y / 2))
		{
			return true;
		}
		return false;
	}
}