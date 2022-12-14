#include <assert.h>
#include "yaApplication.h"
#include "yaSceneManager.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaResources.h"
#include "yaCollisionManager.h"
#include "yaCamera.h"

namespace ya
{
	Application::~Application()
	{
		SceneManager::Release();
		ReleaseDC(mWindowData.hwnd, mWindowData.hdc);
		ReleaseDC(mWindowData.hwnd, mWindowData.backBuffer);
	}

	void Application::Initialize(WindowData data)
	{
		mWindowData = data;
		mWindowData.hdc = GetDC(data.hwnd);
		initailizeWindow();

		Camera::Initialize();
		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialze();
	}

	void Application::initailizeWindow()
	{
		// 비트맵 해상도를 설정하기 위한 실제 위도우 크기 계산
		RECT rect = { 0,0, static_cast<LONG>(mWindowData.width), static_cast<LONG>(mWindowData.height) };
		AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, false);

		// 윈도우 크기 변경
		SetWindowPos(
			mWindowData.hwnd,
			nullptr, 0, 0,
			rect.right - rect.left,
			rect.bottom - rect.top,
			0
		);
		ShowWindow(mWindowData.hwnd, true);
		
		mWindowData.backTexture = CreateCompatibleBitmap(mWindowData.hdc, mWindowData.width, mWindowData.height);
		
		// BackBuffer 만들기
		mWindowData.backBuffer = CreateCompatibleDC(mWindowData.hdc);
		HBITMAP defaultBitmap = static_cast<HBITMAP>(SelectObject(mWindowData.backBuffer, mWindowData.backTexture));
		
		DeleteObject(defaultBitmap);

		// 메모리 해제 해주어야 함.
		mPens[static_cast<UINT>(ePenColor::RED)] = CreatePen(PS_SOLID, 1, RGB(255, 0, 0));
		mPens[static_cast<UINT>(ePenColor::GREEN)] = CreatePen(PS_SOLID, 1, RGB(0, 255, 0));
		mPens[static_cast<UINT>(ePenColor::BLUE)] = CreatePen(PS_SOLID, 1, RGB(0, 0, 255));
		mBrushes[static_cast<UINT>(eBrushColor::TRANS_PARENT)] = static_cast<HBRUSH>(GetStockObject(HOLLOW_BRUSH));
		mBrushes[static_cast<UINT>(eBrushColor::BLACK)] = static_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
		mBrushes[static_cast<UINT>(eBrushColor::GRAY)] = CreateSolidBrush(RGB(67, 67, 67));
		mBrushes[static_cast<UINT>(eBrushColor::WHITE)] = static_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
	}

	void Application::Tick()
	{
		Time::Tick();
		Input::Tick();
		Camera::Tick();

		SceneManager::Tick();
		CollisionManager::Tick();
		
		HBRUSH hPrevBrush = (HBRUSH)SelectObject(mWindowData.backBuffer, mBrushes[(UINT)eBrushColor::GRAY]);

		// Clear 겁나 느리게 만듦.
		Rectangle(
			mWindowData.backBuffer, -1, -1, 
			mWindowData.width + 1, mWindowData.height + 1);
		SelectObject(mWindowData.backBuffer, hPrevBrush);

		SceneManager::Render(mWindowData.backBuffer);
		Camera::Render(mWindowData.backBuffer);
		Input::Render(mWindowData.backBuffer);
		Time::Render(mWindowData.backBuffer);

		// BitBlt 함수는 DC간에 이미지를 복사해주는 함수
		// 백버퍼에 있는 내용을 스왑한다.
		BitBlt(
			mWindowData.hdc, 
			0, 0, mWindowData.width, mWindowData.height,
			mWindowData.backBuffer,						// 어디에다가 그릴거냐.
			0, 0,
			SRCCOPY										// 어떻게 그릴거냐
		);

		// 틱과 렌더 모두 끝내고 Gameobject 삭제 
		SceneManager::DestroyGameobject();
	}
}
