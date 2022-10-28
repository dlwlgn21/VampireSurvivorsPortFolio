#pragma once

#include <cassert>

#define IS_KEY_PRESSED(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::PRESSED
#define IS_KEY_DOWN(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::DOWN
#define IS_KEY_UP(KEY) ya::Input::GetKeyState(KEY) == ya::eKeyState::UP

enum class eSceneType
{
	LOGO_SCENE,
	TITLE_SCENE,
	PLAY_SCENE,
	ENDING_SCENE,
	COUNT
};