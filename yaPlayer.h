#pragma once
#include "yaGameObject.h"
namespace ya
{
	class Player : public GameObject
	{
	public:
		Player();
		virtual ~Player();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;

	private:
		float mSpeed;
	};

}

