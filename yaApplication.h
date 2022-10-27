#pragma once
#include "Common.h"

namespace ya
{
	// ���� ���α׷��� �� �༮
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

