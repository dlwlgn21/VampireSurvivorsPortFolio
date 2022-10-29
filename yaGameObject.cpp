#include "yaGameObject.h"

namespace ya
{
	GameObject::GameObject()
		: mPos(Vector2::ZERO)
		, mScale(Vector2::ONE)
	{
	}

	GameObject::~GameObject()
	{
		for (Component* component : mComponents)
		{
			if (component == nullptr) { continue; }
			delete component;
			component = nullptr;
		}
	}
	void GameObject::Initialize()
	{
	}

	void GameObject::Tick()
	{
		// 모든 컴포넌트의 Tick 호출
		for (Component* component : mComponents)
		{
			if (component == nullptr) { continue; }
			component->Tick();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		// 모든 컴포넌트의 Render 호출
		for (Component* component : mComponents)
		{
			if (component == nullptr) { continue; }
			component->Render(hdc);
		}
	}
	void GameObject::AddComponent(Component* component)
	{
		assert(component != nullptr); 
		mComponents.push_back(component);
		component->mOwner = this;
	}
}