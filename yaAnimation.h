#pragma once
#include "Common.h"
#include "yaComponent.h"

namespace ya
{
	class Image;
	class Animator;
	class Animation : public Component
	{
	public:
		struct Sprite
		{
			Vector2 LeftTop;
			Vector2 Size;				// ����������κ��� �߶� ���μ��� ����
			Vector2 Offset;
			float Durtation;

			Sprite()
				: LeftTop(Vector2::ZERO)
				, Size(Vector2::ZERO)
				, Offset(Vector2::ZERO)
				, Durtation(0.0f)
			{
			}

		};
		Animation();
		virtual ~Animation() = default;

		void Tick() override;
		void Render(HDC hdc) override;

		void Create(
			Image* pImage, Vector2 leftTop,
			Vector2 size, Vector2 offset,
			float colLength, UINT spriteLength, float duration,
			bool bIsAffectedCamera = true);

		void Reset();
		inline bool IsComplete() { return mbIsComplete; }
		inline void SetAnimator(Animator* animator) { mpAnimator = animator; };
	private:
		Image* mpImage;
		Animator* mpAnimator;
		std::vector<Sprite> mSpriteSheet;
		UINT mSpriteIdx;
		float mTime;

		bool mbIsStart;
		bool mbIsComplete;
		bool mbIsEnd;
		bool mbIsAffectedCamera;
	};
}

