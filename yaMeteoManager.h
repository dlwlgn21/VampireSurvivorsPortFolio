#pragma once
#include "yaMeteo.h"

namespace ya
{
	class MeteoManager
	{
	public:
		
		static MeteoManager& GetInstance() 
		{
			static MeteoManager instance;
			return instance;
		}
		MeteoManager()
			: mTimer(1.0f)
			, mGenerateTime(1.0f)
			, mCurrMeteoIdx(0)
		{
			mMeteos.reserve(MAX_METEO);
		}

		~MeteoManager();
	
		void Initialzie();
		void Tick();
		void Render(HDC hdc);

		const int MAX_METEO = 128;
		const int MAX_WIDTH_SIZE = 1920;
		const int MAX_HEIGHT_SIZE = 20;
	
	private:
		float mTimer;
		float mGenerateTime;
		size_t mCurrMeteoIdx;
		std::vector<Meteo*> mMeteos;
	};
}

