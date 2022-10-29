#include <cassert>
#include "yaImage.h"
#include "yaApplication.h"

namespace ya
{
	Image::Image()
		: mBitmap(NULL)
		, mHdc(NULL)
		, mWidth(0)
		, mHeight(0)
	{
	}
	Image::~Image()
	{
		ReleaseDC(Application::GetInstance().GetWindowData().hwnd, mHdc);
	}
	HRESULT Image::Load(const std::wstring& path)
	{
		mBitmap = static_cast<HBITMAP>(LoadImageW(
			nullptr, 
			path.c_str(), 
			IMAGE_BITMAP, 
			0, 0, 
			LR_LOADFROMFILE | LR_CREATEDIBSECTION
		));

		if (mBitmap == nullptr){ assert(false); return E_FAIL; }

		BITMAP bitInfo = {};
		int res = GetObject(mBitmap, sizeof(BITMAP), &bitInfo);
		if (res == FALSE) { assert(false); return E_FAIL; };

		mWidth = bitInfo.bmWidth;
		mHeight = bitInfo.bmHeight;
		
		HDC mainDC = Application::GetInstance().GetWindowData().hdc;
		mHdc = CreateCompatibleDC(mainDC);

		HBITMAP prevBitmap = static_cast<HBITMAP>(SelectObject(mHdc, mBitmap));
		DeleteObject(prevBitmap);

		return S_OK;
	}
}