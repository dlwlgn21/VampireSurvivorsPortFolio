#include "yaTime.h"


namespace ya
{

	LARGE_INTEGER Time::mCPUFrequency;
	LARGE_INTEGER Time::mPrevFrequency;
	LARGE_INTEGER Time::mCurFrequency;
	float Time::mDeltaTime = 0.0f;

	void Time::Initialize()
	{
		QueryPerformanceFrequency(&mCPUFrequency);			// CPU 초당 반복 되는 진동수를 얻어오는 함수 처음엔 0임.
		QueryPerformanceCounter(&mPrevFrequency);			// 프로그램 시작 했을 때에 CPU의 클럭수 
	}

	void Time::Tick()
	{
		QueryPerformanceCounter(&mCurFrequency);

		float differntFrequency
			= static_cast<float>(mCurFrequency.QuadPart - mPrevFrequency.QuadPart);

		mDeltaTime = differntFrequency / mCPUFrequency.QuadPart;


		mPrevFrequency.QuadPart = mCurFrequency.QuadPart;	// 갱신
	}

	void Time::Render(HDC hdc)
	{
		wchar_t buffer[64];

		// DeltaTime == 한 프레임 도는데 걸린 시간.
		float fps = 1.0f / mDeltaTime;
		swprintf_s(buffer, 64, L"FramePerSecond : %.0f", fps);
		int strLen = wcsnlen_s(buffer, 64);

		TextOut(hdc, 10, 10, buffer, strLen);
	}

}