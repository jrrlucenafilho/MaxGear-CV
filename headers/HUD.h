#ifndef HUD_H
#define HUD_H

#pragma once

#include "olcPixelGameEngine.h"

class HUD
{
    public:
        HUD();
        virtual ~HUD();

        void drawHUD(olc::PixelGameEngine* game, float fDistance, float fTargetCurvature, float fPlayerCurvature,
                    float fTrackCurvature, float fSpeed, float fCurrentLapTime, std::list<float> listLapTimes);
        std::string displayTime(float fTime);

    private:

        //Decals for displaying HUD stats
        olc::vf2d distDecal; 
        olc::vf2d targetCurvatureDecal;
        olc::vf2d playerCurvatureDecal;
        olc::vf2d speedDecal;
        olc::vf2d trackCurvatureDecal;
        olc::vf2d currentLaptimeDecal;
        olc::vf2d listLapTimesTitleDecal;
        olc::vf2d listLapTimesDecal;
};

#endif