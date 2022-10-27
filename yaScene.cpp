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
			if (object == nullptr)
			{
				continue;
			}
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
		for (auto* object : mObjects)
		{
			object->Tick();
		}
	}
	void Scene::Render(HDC hdc)
	{
		for (auto* object : mObjects)
		{
			object->Render(hdc);
		}
	}
	void Scene::AddGameObject(GameObject* object)
	{
		assert(object != nullptr);
		mObjects.push_back(object);
	}

}