#pragma once
#include "yaGameObject.h"
namespace ya
{
	class Missile : public GameObject
	{
	public:
		Missile();
		virtual ~Missile();

		void Tick() override;
		void Render(HDC hdc) override;
		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

	private:
		float mSpeed;

	};

}

