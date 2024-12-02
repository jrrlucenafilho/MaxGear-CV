#ifndef TRACKS_H
#define TRACKS_H

#pragma once

#include <vector>

#include "olcPixelGameEngine.h"

enum trackOptions { PLAINS = 1, DESERT = 2 };

class Tracks {
 public:
  Tracks();
  Tracks(int option);
  virtual ~Tracks();

  olc::Pixel getGroundColor1();
  olc::Pixel getGroundColor2();
  olc::Pixel getClipColor1();
  olc::Pixel getClipColor2();
  olc::Pixel getRoadColor();
  olc::Pixel getHillsColor();
  olc::Pixel getSkyColor();
  float getTrackDistance();
  std::vector<std::pair<float, float>> getTrackVec();
  float getfTrackCurvature();
  int getnHillHeight();
  int getTrackOption();

  void setTrack(int option);
  void setGroundColor1();
  void setGroundColor2();
  void setClipColor1();
  void setClipColor2();
  void setRoadColor();
  void setHillsColor();
  void setSkyColor();
  void setfTrackCurvature(float extraCurvature);
  void setnHillHeight(int newHillHeight);

  void calcTrackDistance();
  void buildChosenTrack();
  void addTofTrackCurvature(float extraCurvature);

 private:
  void buildTrack1();
  void buildTrack2();

  int trackOption;
  int nHillHeight;
  float fTrackDistance;   // Total distance of track
  float fTrackCurvature;  // Current track curvature, changed between track
                          // sections

  olc::Pixel groundColor1, groundColor2;
  olc::Pixel clipColor1, clipColor2;
  olc::Pixel roadColor;
  olc::Pixel hillsColor;
  olc::Pixel skyColor;

  std::vector<std::pair<float, float>>
      trackVec;  // Track sections, pairs: sharpness of bend, length of section
};

#endif