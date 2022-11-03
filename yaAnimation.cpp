#include "yaAnimation.h"
#include "yaImage.h"
#include "yaAnimator.h"
#include "yaCamera.h"
#include "yaGameObject.h"

namespace ya
{
	Animation::Animation()
		: Component(eComponentType::ANIMATION)
	{
		mSpriteSheet.reserve(120);
	}

	void Animation::Tick()
	{

	}
	void Animation::Render(HDC hdc)
	{
		//Vector2 fPos;
		//fPos.x = GetOwner()->GetPos().x - mpImage->GetWidth() * (GetOwner()->GetScale().x / 2);
		//fPos.y = GetOwner()->GetPos().y - mpImage->GetWidth() * (GetOwner()->GetScale().y / 2);
		//fPos = Camera::ToCameraPos(fPos);
		//TransparentBlt(
		//	hdc,
		//	static_cast<int>(fPos.x),
		//	static_cast<int>(fPos.y),
		//	static_cast<int>(mpImage->GetWidth() * GetOwner()->GetScale().x),
		//	static_cast<int>(mpImage->GetHeight() * GetOwner()->GetScale().y),

		//	mpImage->GetDC(),
		//	0, 0,
		//	mpImage->GetWidth(),
		//	mpImage->GetHeight(),
		//	RGB(255, 0, 255)
		//);
		GameObject* gameObject = mpAnimator->GetOwner();
		Vector2 pos = gameObject->GetPos();
		if (!mbIsAffectedCamera)
		{

		}
		BLENDFUNCTION Func;
		Func.BlendOp = AC_SRC_OVER;
		Func.BlendFlags = 0;
		Func.AlphaFormat = AC_SRC_ALPHA;
		Func.SourceConstantAlpha = 255;

		AlphaBlend(
			hdc,
			static_cast<int>(pos.x - mSpriteSheet[mSpriteIdx].Size.x / 2.0f),
			static_cast<int>(pos.y - mSpriteSheet[mSpriteIdx].Size.y / 2.0f),
			static_cast<int>(mSpriteSheet[mSpriteIdx].Size.x),
			static_cast<int>(mSpriteSheet[mSpriteIdx].Size.y),

			mpImage->GetDC(),
			static_cast<int>(mSpriteSheet[mSpriteIdx].LeftTop.x),
			static_cast<int>(mSpriteSheet[mSpriteIdx].LeftTop.y),
			static_cast<int>(mSpriteSheet[mSpriteIdx].Size.x),
			static_cast<int>(mSpriteSheet[mSpriteIdx].Size.y),
			Func
		);

	}
	void Animation::Create(Image* pImage, Vector2 leftTop, Vector2 size, Vector2 offset, float colLength, UINT spriteLength, float duration, bool bIsAffectedCamera)
	{
		mpImage = pImage;
		mbIsAffectedCamera = bIsAffectedCamera;
		for (int i = 0; i < spriteLength; ++i)
		{
			Sprite sprite;
			sprite.LeftTop.x = leftTop.x + (colLength * i);
			sprite.LeftTop.y = leftTop.y;
			sprite.Size = size;
			sprite.Offset = offset;
			sprite.Durtation = duration;
			mSpriteSheet.push_back(sprite);
		}
	}
	void Animation::Reset()
	{
	}
}