#pragma once
#include "Common.h"

namespace ya
{
	// 메인 프로그램이 될 녀석
	class Application
	{
	public:
		static Application& GetInstance()
		{
			static Application instance;
			return instance;
		}
		void Initialize(WindowData data);
		void Tick();
		Application() = default;
		~Application();

	private:
		WindowData mWindowData;
	};
}

