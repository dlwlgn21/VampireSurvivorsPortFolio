#include <cassert>
#include "yaGameObject.h"
#include "yaScene.h"


namespace ya
{
	Scene::Scene()
	{
	}
	Scene::~Scene()
	{
		for (auto* object : mObjects)
		{
			if (object == nullptr) { continue; }
			delete object;
		}
	}

	void Scene::Initialize()
	{
		for (auto* object : mObjects)
		{
			object->Initialize();
		}
	}

	void Scene::Tick()
	{
		for (size_t i = 0; i < mObjects.size(); i++)
		{
			mObjects[i]->Tick();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (size_t i = 0; i < mObjects.size(); i++)
		{
			mObjects[i]->Render(hdc);
		}
	}
	void Scene::AddGameObject(GameObject* object)
	{
		assert(object != nullptr);
		mObjects.push_back(object);
	}

}