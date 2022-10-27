#pragma once
#include "yaScene.h"

namespace ya
{
	class LogoScene : public Scene
	{

	public:
		LogoScene();
		virtual ~LogoScene();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;
	};

}


