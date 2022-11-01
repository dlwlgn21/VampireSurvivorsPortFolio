#include "yaCamera.h"
#include "yaApplication.h"
#include "yaGameObject.h"
#include "yaInput.h"
#include "yaTime.h"

namespace ya
{

	Vector2 Camera::mResolution = Vector2::ZERO;
	Vector2 Camera::mLookPosition = Vector2::ZERO;
	Vector2 Camera::mDistance = Vector2::ZERO;			// �ػ� �߽���ǥ�� ���� ī�޶��� ��������.
	GameObject* Camera::mTarget = nullptr;
	float Camera::mSpeed = 500.0f;

	void Camera::Initialize()
	{
		WindowData windowData = Application::GetInstance().GetWindowData();
		mResolution = Vector2(windowData.width, windowData.height);
		mLookPosition = mResolution / 2.0f;				// ����� �Ұž�

	}
	void Camera::Tick()
	{
		if (IS_KEY_PRESSED(eKeyCode::UP))
		{
			mLookPosition.y -= mSpeed * Time::DeltaTime();
		}
		if (IS_KEY_PRESSED(eKeyCode::DOWN))
		{
			mLookPosition.y += mSpeed * Time::DeltaTime();
		}
		if (IS_KEY_PRESSED(eKeyCode::LEFT))
		{
			mLookPosition.x -= mSpeed * Time::DeltaTime();
		}
		if (IS_KEY_PRESSED(eKeyCode::RIGHT))
		{
			mLookPosition.x += mSpeed * Time::DeltaTime();
		}

		if (mTarget != nullptr) { mLookPosition = mTarget->GetPos(); }
		mDistance = mLookPosition - (mResolution / 2.0f);
	}
}