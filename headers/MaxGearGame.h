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
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"

enum cvDirections { CV_STILL = 0, CV_LEFT = -1, CV_RIGHT = 1 };

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
  void faceDetectionBegin();

  std::string getRecordFromFile();  // Printing and getting record to file
  void writeRecordToFile();

 protected:
  virtual bool OnUserCreate();  // Called by the engine
  virtual bool OnUserUpdate(float fElapsedTime);
  virtual bool OnUserDestroy();

 private:
  void setTrackAudio();
  void detectAndDraw();
  void drawTransparency(cv::Mat frame, cv::Mat transp, int xPos, int yPos);
  void drawTransRect(cv::Mat frame, cv::Scalar color, double alpha,
                     cv::Rect region);

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
  float fCurrentLapTime;          // Current lap time
  std::list<float> listLapTimes;  // 5 last lap times
  float timeRecord;

  std::string cascadeName;  // OpenCV related
  cv::VideoCapture capture;
  cv::Mat frame;
  bool tryflip;
  cv::CascadeClassifier cascade;
  double scale;
  int ncvDirection;
};

#endif