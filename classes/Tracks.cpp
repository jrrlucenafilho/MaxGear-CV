#include "Tracks.h"

using namespace olc;

Tracks::Tracks()
{   //Assuming trackOption has been set before, else sets standart track
    fTrackDistance = 0.0f;
    fTrackCurvature = 0.0f;
    nHillHeight = 0;
    setGroundColor1();
    setGroundColor2();
    setClipColor1();
    setClipColor2();
    setRoadColor();
    setHillsColor();
    setSkyColor();

    buildChosenTrack();
    calcTrackDistance();
}

Tracks::Tracks(int option)
{
    fTrackDistance = 0.0f;
    fTrackCurvature = 0.0f;
    nHillHeight = 0;
    setTrack(option);
    setGroundColor1();
    setGroundColor2();
    setClipColor1();
    setClipColor2();
    setRoadColor();
    setHillsColor();
    setSkyColor();

    buildChosenTrack();
    calcTrackDistance();
}

Tracks::~Tracks()
{

}

Pixel Tracks::getGroundColor1()
{
    return groundColor1;
}

Pixel Tracks::getGroundColor2()
{
    return groundColor2;
}

Pixel Tracks::getClipColor1()
{
    return clipColor1;
}

Pixel Tracks::getClipColor2()
{
    return clipColor2;
}

Pixel Tracks::getRoadColor()
{
    return roadColor;
}

Pixel Tracks::getHillsColor()
{
    return hillsColor;
}

Pixel Tracks::getSkyColor()
{
    return skyColor;
}

float Tracks::getTrackDistance()
{
    return fTrackDistance;
}

float Tracks::getfTrackCurvature()
{
    return fTrackCurvature;
}

std::vector<std::pair<float, float>> Tracks::getTrackVec()
{
    return trackVec;
}

int Tracks::getnHillHeight()
{
    return nHillHeight;
}

int Tracks::getTrackOption()
{
    return trackOption;
}

void Tracks::setTrack(int option)
{
    trackOption = option;
}

void Tracks::setGroundColor1()
{
    switch (trackOption)
    {
    case PLAINS:
        groundColor1 = GREEN;
        break;
    
    case DESERT:
        groundColor1 = ORANGE;
        break;
    
    default:
        groundColor1 = RED;
        break;
    }
}

void Tracks::setGroundColor2()
{
    switch (trackOption)
    {
    case PLAINS:
        groundColor2 = DARK_GREEN;
        break;
    
    case DESERT:
        groundColor2 = DARK_ORANGE;
        break;
    
    default:
        groundColor2 = DARK_RED;
        break;
    }
}

void Tracks::setClipColor1()
{
    switch (trackOption)
    {
    case PLAINS:
        clipColor1 = RED;
        break;
    
    case DESERT:
        clipColor1 = GREEN;
        break;
    
    default:
        clipColor1 = VERY_DARK_RED;
        break;
    }
}

void Tracks::setClipColor2()
{
    switch (trackOption)
    {
    case PLAINS:
        clipColor2 = WHITE;
        break;
    
    case DESERT:
        clipColor2 = WHITE;
        break;
    
    default:
        clipColor2 = DARK_YELLOW;
        break;
    }
}

void Tracks::setRoadColor()
{
    switch (trackOption)
    {
    case PLAINS:
        roadColor = GREY;
        break;
    
    case DESERT:
        roadColor = GREY;
        break;
    
    default:
        roadColor = VERY_DARK_YELLOW;
        break;
    }
}

void Tracks::setHillsColor()
{
    switch (trackOption)
    {
    case PLAINS:
        hillsColor = DARK_YELLOW;
        break;
    
    case DESERT:
        hillsColor = VERY_DARK_ORANGE;
        break;
    
    default:
        hillsColor = VERY_DARK_RED;
        break;
    }
}

void Tracks::setSkyColor()
{
    switch (trackOption)
    {
    case PLAINS:
        skyColor = DARK_BLUE;
        break;
    
    case DESERT:
        skyColor = BLUE;
        break;
    
    default:
        skyColor = YELLOW;
        break;
    }
}

void Tracks::setfTrackCurvature(float extraCurvature)
{
    fTrackCurvature = extraCurvature;
}

void Tracks::setnHillHeight(int newnHillHeight)
{
    nHillHeight = newnHillHeight;
}

void Tracks::buildChosenTrack()
{
    switch (trackOption)
    {
    case PLAINS:
        buildTrack1();
        break;

    case DESERT:
        buildTrack2();
        break;
    
    default:
        buildTrack1();
        break;
    }
}

void Tracks::calcTrackDistance()
{   //Calculate total track distance, so as to set lap times
    for(std::pair<float, float> trackSegment : trackVec){
        fTrackDistance += trackSegment.second;
    }
}

void Tracks::buildTrack1()
{
    //Define track (pairs: Track slice curvature / Distance of track slice)
    trackVec.push_back(std::make_pair(0.0f, 10.0f));
    trackVec.push_back(std::make_pair(1.0f, 400.0f));
    trackVec.push_back(std::make_pair(-1.0f, 320.0f));
    trackVec.push_back(std::make_pair(0.45f, 20.0f));
    trackVec.push_back(std::make_pair(-1.0f, 40.0f));
    trackVec.push_back(std::make_pair(0.0f, 10.0f));
    trackVec.push_back(std::make_pair(-0.5f, 89.0f));
    trackVec.push_back(std::make_pair(1.0f, 20.0f));
    trackVec.push_back(std::make_pair(-0.3f, 80.0f));
    trackVec.push_back(std::make_pair(0.2f, 45.0f));
    trackVec.push_back(std::make_pair(0.0f, 200.0f));
    trackVec.push_back(std::make_pair(-1.0f, 50.0f));
    trackVec.push_back(std::make_pair(1.0f, 100.0f));
    trackVec.push_back(std::make_pair(-0.4f, 80.0f));
    trackVec.push_back(std::make_pair(0.25f, 150.0f));
    trackVec.push_back(std::make_pair(1.0f, 20.0f));
    trackVec.push_back(std::make_pair(-0.9f, 80.0f));
    trackVec.push_back(std::make_pair(0.89f, 50.0f));
    trackVec.push_back(std::make_pair(-0.88f, 55.0f));
    trackVec.push_back(std::make_pair(-0.90f, 50.0f));
    trackVec.push_back(std::make_pair(0.5f, 80.0f));
    trackVec.push_back(std::make_pair(-1.0f, 700.0f));
    trackVec.push_back(std::make_pair(1.0f, 100.0f));
    trackVec.push_back(std::make_pair(-0.44f, 80.0f));
    trackVec.push_back(std::make_pair(0.84f, 50.0f));
    trackVec.push_back(std::make_pair(-0.55f, 80.0f));
    trackVec.push_back(std::make_pair(0.65f, 57.0f));
    trackVec.push_back(std::make_pair(-1.0f, 80.0f));
    trackVec.push_back(std::make_pair(-1.0f, 100.0f));
    trackVec.push_back(std::make_pair(0.20f, 60.0f));
    trackVec.push_back(std::make_pair(-0.30f, 90.0f));
    trackVec.push_back(std::make_pair(0.80f, 50.0f));
    trackVec.push_back(std::make_pair(-1.0f, 700.0f));
    trackVec.push_back(std::make_pair(0.8f, 50.0f));
    trackVec.push_back(std::make_pair(0.0f, 200.0f));
}

void Tracks::buildTrack2()
{
    trackVec.push_back(std::make_pair(0.0f, 10.0f));
    trackVec.push_back(std::make_pair(0.0f, 200.0f));
    trackVec.push_back(std::make_pair(-1.0f, 200.0f));
    trackVec.push_back(std::make_pair(0.5f, 400.0f));
    trackVec.push_back(std::make_pair(-1.0f, 100.0f));
    trackVec.push_back(std::make_pair(0.0f, 200.0f));
    trackVec.push_back(std::make_pair(-1.0f, 200.0f));
    trackVec.push_back(std::make_pair(1.0f, 200.0f));
    trackVec.push_back(std::make_pair(0.0f, 200.0f));
    trackVec.push_back(std::make_pair(0.2f, 500.0f));
    trackVec.push_back(std::make_pair(0.0f, 200.0f));
    trackVec.push_back(std::make_pair(0.0f, 50.0f));
    trackVec.push_back(std::make_pair(1.0f, 100.0f));
    trackVec.push_back(std::make_pair(-1.0f, 100.0f));
    trackVec.push_back(std::make_pair(0.25f, 150.0f));
    trackVec.push_back(std::make_pair(0.89f, 150.0f));
    trackVec.push_back(std::make_pair(-0.9f, 80.0f));
    trackVec.push_back(std::make_pair(-0.77f, 50.0f));
    trackVec.push_back(std::make_pair(-0.88f, 55.0f));
    trackVec.push_back(std::make_pair(-0.90f, 50.0f));
    trackVec.push_back(std::make_pair(-0.99f, 100.0f));
    trackVec.push_back(std::make_pair(-1.0f, 89.0f));
    trackVec.push_back(std::make_pair(1.0f, 100.0f));
    trackVec.push_back(std::make_pair(-0.44f, 120.0f));
    trackVec.push_back(std::make_pair(0.84f, 100.0f));
    trackVec.push_back(std::make_pair(0.55f, 80.0f));
    trackVec.push_back(std::make_pair(0.0f, 200.0f));
}

void Tracks::addTofTrackCurvature(float extraCurvature)
{
    fTrackCurvature += extraCurvature;
}
