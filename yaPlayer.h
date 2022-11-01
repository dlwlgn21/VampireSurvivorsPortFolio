#pragma once
#include "yaGameObject.h"
namespace ya
{
	class Image;
	class Player final : public GameObject
	{
	public:
		Player();
		virtual ~Player();

		void Tick() override;
		void Render(HDC hdc) override;
		void OnCollisionEnter(Collider* other) override;
		void OnCollisionStay(Collider* other) override;
		void OnCollisionExit(Collider* other) override;

	private:
		float mSpeed;
		HPEN mPen;
		HBRUSH mBrush;
		Image* mImage;
	};

}

