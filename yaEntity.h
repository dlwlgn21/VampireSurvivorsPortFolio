#pragma once
#include "Common.h"

namespace ya
{
	class Entity
	{
	public:
		Entity();
		virtual ~Entity();

		void SetNAme(const std::wstring name) { mName = name; };
		std::wstring GetName() { return mName; }

	private:
		std::wstring mName;
		UINT mId;
	};
}

