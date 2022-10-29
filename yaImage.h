#pragma once
#include "yaResource.h"

namespace ya
{
	class Image : public Resource
	{
	public:
		Image();
		~Image();
		HRESULT Load(const std::wstring& path) override;

		inline HDC GetDC() { return mHdc; }
		inline UINT GetWidth() { return mWidth; }
		inline UINT GetHeight() { return mHeight; }
	private:
		HBITMAP mBitmap;
		HDC mHdc;
		UINT mWidth;
		UINT mHeight;
	};
}

