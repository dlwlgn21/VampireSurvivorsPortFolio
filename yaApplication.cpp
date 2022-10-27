#include <assert.h>
#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaTime.h"
#include "yaInput.h"

namespace ya
{
	Application::~Application()
	{
		SceneManager::Release();
		ReleaseDC(mWindowData.hwnd, mWindowData.hdc);
	}

	void Application::Initialize(WindowData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(data.hwnd);

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialze();
	}

	void Application::Tick()
	{
		Time::Tick();
		Input::Tick();

		SceneManager::Tick();
		SceneManager::Render(mWindowData.hdc);

		Input::Render(mWindowData.hdc);
		Time::Render(mWindowData.hdc);
	}
}
