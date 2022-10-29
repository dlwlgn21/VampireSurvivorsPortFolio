#pragma once
#include "Common.h"
#include "yaResource.h"
 
namespace ya
{
	class Resources
	{
	public:
		template<typename T>
		static T* Find(const std::wstring& key)
		{
			auto iter = mResources.find(key);
			
			if (iter != mResources.end()) { return static_cast<T*>(iter->second); }

			return nullptr;
		}

		template<typename T>

		static T* Load(const std::wstring& key, const std::wstring& path)
		{
			T* pResource = Find<T>(path);
			if (pResource != nullptr) { return pResource; }

			pResource = new T();
			if (FAILED(pResource->Load(path)))
			{
				assert(false);
				return nullptr;
			}
			pResource->SetKey(key);
			pResource->SetPath(path);
			mResources.insert(std::make_pair(key, pResource));

			return static_cast<T*>(pResource);
		}

		static void Release()
		{
			//for (auto iter = mResources.begin(); iter != mResources.end(); ++iter)
			//{
			//	if (iter->second == nullptr) 
			//	{
			//		continue;
			//	}
			//	delete iter->second;
			//	iter->second = nullptr;
			//}
		}

	private:
		static std::unordered_map<std::wstring, Resource*> mResources;
	};

}

