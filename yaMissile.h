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

	private:
		float mSpeed;
	};

}

