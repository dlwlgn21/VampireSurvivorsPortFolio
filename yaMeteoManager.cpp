#include "yaMeteoManager.h"
#include "yaTime.h"
namespace ya
{
    void MeteoManager::Initialzie()
    {
        for (int i = 0; i < MAX_METEO; ++i)
        {
            mMeteos.push_back(new Meteo(rand() % MAX_WIDTH_SIZE, rand() % MAX_HEIGHT_SIZE));
        }
    }
    void MeteoManager::Tick()
    {
        mTimer -= Time::DeltaTime();
        if (mTimer <= 0.f)
        {
            mTimer = mGenerateTime;
            ++mCurrMeteoIdx;
        }
        for (int i = 0; i < mCurrMeteoIdx; ++i)
        {
            if (mCurrMeteoIdx >= MAX_METEO)
            {
                break;
            }
            mMeteos[i]->Tick();
        }
    }
    void MeteoManager::Render(HDC hdc)
    {
        for (int i = 0; i < mCurrMeteoIdx; ++i)
        {
            if (mCurrMeteoIdx >= MAX_METEO)
            {
                break;
            }
            mMeteos[i]->Render(hdc);
        }
    }

    MeteoManager::~MeteoManager()
    {
        for (int i = 0; i < MAX_METEO; ++i)
        {
            if (mMeteos[i] == nullptr) { continue; }
            delete mMeteos[i];
        }
    }
}