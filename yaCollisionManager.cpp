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
					// �浹�� �Ǿ����� �ȵǾ������� �˻������ �Ѵ�.
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
		// ������ �� �ʸ� ���� ���ؼ�. �� ������ ���� ���ؼ�
		// �� ���� ���ڸ� ������, �� ū ���ڸ� ����
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
		// ��� left ������Ʈ��� right ������Ʈ���� ������ �����־�� ��.
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