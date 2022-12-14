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

enum class ePenColor
{
	RED,
	BLUE,
	GREEN,
	COUNT
};

enum class eBrushColor
{
	TRANS_PARENT,
	BLACK,
	GRAY,	// 160, 0, 67
	WHITE,
	COUNT
};

enum class eComponentType
{
	ANIMATOR,
	ANIMATION,
	COLLIDER,
	SOUND,
	COUNT
};

#define MAX_COLLIDER_LAYER (16)
enum class eColliderLayer
{
	DEFAULT,
	BACKGROUND,
	TILE,
	PLAYER,
	PLAYER_PROJECTTILE,
	MONSTER,
	MONSTER_PROJECTTILE,
	BACKPACK,

	UI = MAX_COLLIDER_LAYER -1,
	COUNT = MAX_COLLIDER_LAYER,
};

union UnionColliderID
{
	struct
	{
		UINT32 left;
		UINT32 right;
	};

	UINT64 ID;
};

enum class eCameraEffect
{
	FADE_IN,
	FADE_OUT,
	COUNT
};