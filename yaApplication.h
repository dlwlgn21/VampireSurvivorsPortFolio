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

		WindowData GetWindowData() { return mWindowData; }

		inline HPEN GetPen(ePenColor color) { return mPens[static_cast<UINT>(color)]; }
		inline HBRUSH GetBrush(eBrushColor color) { return mBrushes[static_cast<UINT>(color)]; }

	private:
		void initailizeWindow();
	private:
		WindowData mWindowData;
		HPEN mPens[static_cast<UINT>(ePenColor::COUNT)];
		HBRUSH mBrushes[static_cast<UINT>(eBrushColor::COUNT)];
	};
}

