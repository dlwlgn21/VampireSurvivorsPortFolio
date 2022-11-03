#include "yaAnimator.h"
#include "yaGameObject.h"
#include "yaImage.h"
#include "yaCamera.h"
#include "yaResources.h"
#include "yaAnimation.h"

namespace ya
{
	Animator::Animator()
		: Component(eComponentType::ANIMATOR)
		, mpCurrAnimation(nullptr)
		, mbIsLooping(false)
	{
		//mpImage = Resources::Load<Image>(L"Player", L"Resources\\Image\\Player.bmp");
	}
	Animator::~Animator()
	{

	}
	
	void Animator::Tick()
	{
	}
	void Animator::Render(HDC hdc)
	{
		if (mpCurrAnimation != nullptr) { mpCurrAnimation->Render(hdc); }
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

		//GameObject::Render(hdc);
	}
	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		auto iter = mAnimations.find(name);
		if (iter == mAnimations.end()) { return nullptr; }
		return iter->second;
	}
	void Animator::CreateAnimation(const std::wstring& name, Image* image, Vector2 leftTop, Vector2 size, Vector2 offset, float colLength, UINT spriteLength, float duration, bool bIsAffectedCamera)
	{
		Animation* animation = FindAnimation(name);
		if (animation != nullptr)
		{
			assert(false, L"중복키 애니메이션 생성, 애니메이션 생성 실패");
			return;
		}
		animation = new Animation();
		animation->Create(image, leftTop, size, offset, colLength, spriteLength, duration, bIsAffectedCamera);
		animation->SetName(name);
		animation->SetAnimator(this);
		
		mAnimations.insert(std::make_pair(name, animation));
	
	}
	void Animator::Play(const std::wstring& name, bool bIsLooping)
	{
	}
}