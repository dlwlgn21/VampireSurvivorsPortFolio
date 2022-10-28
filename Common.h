#pragma once

#include "framework.h"
#include "Maths.h"
#include "def.h"

#include <string>
#include <vector>
#include <list>
#include <map>


struct WindowData
{
	HWND hwnd;
	HDC hdc;
	UINT height;
	UINT width;
	void Clear()
	{
		HWND hwnd = nullptr;
		HDC hdc = nullptr;
		height = 0;
		width = 0;
	}

};
