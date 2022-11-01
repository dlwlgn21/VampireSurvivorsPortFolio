#include "yaGameObject.h"

namespace ya
{
	GameObject::GameObject()
		: mPos(Vector2::ZERO)
		, mScale(Vector2::ONE)
		, mIsAlive(true)
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
		// ��� ������Ʈ�� Tick ȣ��
		for (Component* component : mComponents)
		{
			if (component == nullptr) { continue; }
			component->Tick();
		}
	}
	void GameObject::Render(HDC hdc)
	{
		// ��� ������Ʈ�� Render ȣ��
		for (Component* component : mComponents)
		{
			if (component == nullptr) { continue; }
			component->Render(hdc);
		}
	}
	void GameObject::OnCollisionEnter(Collider* other)
	{
	}

	void GameObject::OnCollisionStay(Collider* other)
	{
	}

	void GameObject::OnCollisionExit(Collider* other)
	{
	}

	void GameObject::AddComponent(Component* component)
	{
		assert(component != nullptr); 
		mComponents.push_back(component);
		component->mOwner = this;
	}

}