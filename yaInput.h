#pragma once
#include "Common.h"

namespace ya
{
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,
		COUNT
	};

	enum class eKeyState
	{
		DOWN,
		PRESSED,
		UP,
		NONE
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bIsPressed;
		};

	public:
		static void Initialize();
		static void Tick();
		static void Render(HDC hdc);
	private:
	};
}

