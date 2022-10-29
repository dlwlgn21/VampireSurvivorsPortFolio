#pragma once
#include "Common.h"
#include "yaGameObject.h"
namespace ya
{
	class Meteo : public GameObject
	{
	public:
		Meteo();
		Meteo(int radomX, int randomY);
		~Meteo() = default;

		virtual void Tick();
		virtual void Render(HDC hdc);

		const int MAX_FALL_SPEED = 1000;
		const int MIN_FALL_SPEED = 400;
		const int WIDTH = 100;
		const int HEIGHT = 100;

	private:
		float mFallSpeed;
		int mRandomPosX;
		int mRandomPosY;
		HBRUSH mBrush;
		HPEN mPen;
	};
}

