#pragma once
#include "yaGameObject.h"

namespace ya
{
	class Image;
	class Monster : public GameObject
	{
	public:
		Monster();
		virtual ~Monster();

		void Tick() override;
		void Render(HDC hdc) override;

	private:
		HPEN mPen;
		HBRUSH mBrush;
		Image* mpImage;
	};

}

