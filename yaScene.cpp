#include <cassert>
#include "yaGameObject.h"
#include "yaScene.h"


namespace ya
{
	Scene::Scene()
	{
		mObjects.resize(MAX_COLLIDER_LAYER);
		for (int i = 0; i < MAX_COLLIDER_LAYER; ++i)
		{
			mObjects[i].reserve(64);
		}
	}
	Scene::~Scene()
	{
		for (int i = 0; i < MAX_COLLIDER_LAYER; ++i)
		{
			for (int j = 0; j < mObjects[i].size(); ++j)
			{
				if (mObjects[i][j] == nullptr) { continue; }
				delete mObjects[i][j];
				mObjects[i][j] = nullptr;
			}
		}
	}

	void Scene::Initialize()
	{
		for (int i = 0; i < MAX_COLLIDER_LAYER; ++i)
		{
			for (int j = 0; j < mObjects[i].size(); ++j)
			{
				if (mObjects[i][j] == nullptr) { continue; }
				mObjects[i][j]->Initialize();
			}
		}
	}

	void Scene::Tick()
	{
		for (int i = 0; i < MAX_COLLIDER_LAYER; ++i)
		{
			for (int j = 0; j < mObjects[i].size(); ++j)
			{
				if (mObjects[i][j] == nullptr) { continue; }
				mObjects[i][j]->Tick();
			}
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (int i = 0; i < MAX_COLLIDER_LAYER; ++i)
		{
			for (int j = 0; j < mObjects[i].size(); ++j)
			{
				if (mObjects[i][j] == nullptr) { continue; }
				mObjects[i][j]->Render(hdc);
			}
		}
	}
	void Scene::Enter()
	{
	}
	void Scene::Exit()
	{
	}
	void Scene::AddGameObject(GameObject* object, eColliderLayer layer)
	{
		assert(object != nullptr);
		mObjects[static_cast<UINT>(layer)].push_back(object);
	}

}