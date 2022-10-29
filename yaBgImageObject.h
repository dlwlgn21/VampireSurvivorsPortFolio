#pragma once
#include "yaGameObject.h"
namespace ya
{
	class Image;
	class BgImageObject : public GameObject
	{
	public:
		BgImageObject(const std::wstring key);
		virtual ~BgImageObject();

		void Initialize() override;
		void Tick() override;
		void Render(HDC hdc) override;
	private:
		Image* mpImage;
		std::wstring mKey;
	};
}

