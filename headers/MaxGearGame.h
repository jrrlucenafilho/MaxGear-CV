#ifndef MAXGEARGAME_H
#define MAXGEARGAME_H

#pragma once

#include <algorithm>
#include <fstream>

#include "Car.h"
#include "HUD.h"
#include "Menu.h"
#include "Tracks.h"
#include "olcPixelGameEngine.h"
#include "olcSoundWaveEngine.h"

class MaxGearGame : public olc::PixelGameEngine {
 public:
  MaxGearGame();
  virtual ~MaxGearGame();

  float getfDistance();
  float getfAccTrackCurvature();
  float getfTargetCurvature();
  float getfCurrentLapTime();
  std::list<float> getListLapTimes();
  Menu getMenu();

  void setTrackOption(int option);  // CV related

  std::string getRecordFromFile();  // Printing and getting record to file
  void writeRecordToFile();

 protected:
  virtual bool OnUserCreate();  // Called by the engine
  virtual bool OnUserUpdate(float fElapsedTime);
  virtual bool OnUserDestroy();

 private:
  void setTrackAudio();

  Menu menu;
  Tracks tracks;
  HUD hud;
  Car car;

  olc::sound::WaveEngine waveEngine;  // Sound stuff
  olc::sound::Wave trackAudio;

  int trackOption;           // Which track to build, for colors, sound, etc.
  float fDistance;           // Distance car has travelled around track
  float fAccTrackCurvature;  // Acc of track curvature
  float fTargetCurvature;    // Curvature that's being added/subtracted over
                             // ElapsedTime
  float fCurrentLapTime;     // Current lap time
  std::list<float> listLapTimes;  // 5 last lap times
  float timeRecord;
};

#endif