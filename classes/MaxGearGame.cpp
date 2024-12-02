#include "MaxGearGame.h"

using namespace std;
using namespace olc;

MaxGearGame::MaxGearGame() {
  sAppName = "MaxGear";

  fDistance = 0.0f;
  fAccTrackCurvature = 0.0f;
  fTargetCurvature = 0.0f;
}

MaxGearGame::~MaxGearGame() {}

float MaxGearGame::getfDistance() { return fDistance; }

float MaxGearGame::getfAccTrackCurvature() { return fAccTrackCurvature; }

float MaxGearGame::getfTargetCurvature() { return fTargetCurvature; }

float MaxGearGame::getfCurrentLapTime() { return fCurrentLapTime; }

std::list<float> MaxGearGame::getListLapTimes() { return listLapTimes; }

Menu MaxGearGame::getMenu() { return menu; }

void MaxGearGame::setTrackOption(int option) { trackOption = option; }

bool MaxGearGame::OnUserCreate() {
  waveEngine.InitialiseAudio();  // Start respective track's audio
  setTrackAudio();
  waveEngine.PlayWaveform(&trackAudio);

  tracks = Tracks(trackOption);  // Builds chosen track
  listLapTimes = {0, 0, 0, 0, 0};
  fCurrentLapTime = 0.0f;

  return true;
}

bool MaxGearGame::OnUserUpdate(float fElapsedTime) {
  // Force car to direction 0 if not going to sides
  car.setnCarDirection(CAR_STILL);

  // Main quitting logic
  if (GetKey(Key::Q).bPressed) {
    return false;
  }

  if ((GetKey(Key::UP).bHeld) || (GetKey(Key::SPACE).bHeld) ||
      (GetMouse(Mouse::LEFT).bHeld)) {
    car.addTofSpeed(2.0f * fElapsedTime);
  } else {
    car.deductFromfSpeed(1.0f * fElapsedTime);
  }

  // Car Curvature is accumulated left/right input (but inv proportional to
  // speed) To make it harder to turn at high speed
  if ((GetKey(Key::LEFT).bHeld)) {
    car.deductFromfCarCurvature(0.7f * fElapsedTime *
                                (1.0f - car.getfSpeed() / 2.0f));
    car.setnCarDirection(CAR_LEFT);
  }

  if ((GetKey(Key::RIGHT).bHeld)) {
    car.addTofCarCurvature(0.7f * fElapsedTime *
                           (1.0f - car.getfSpeed() / 2.0f));
    car.setnCarDirection(CAR_RIGHT);
  }

  // If car curvature is too different to track curvature, slow down because
  // player is off track
  if (fabs(car.getfCarCurvature() - fAccTrackCurvature) >= 0.8f) {
    car.deductFromfSpeed(5.0f * fElapsedTime);
  }

  // Clamp for max and min speed
  if (car.getfSpeed() < 0.0f) {
    car.setfSpeed(0.0f);
  }
  if (car.getfSpeed() > 1.0f) {
    car.setfSpeed(1.0f);
  }

  // Move car along track according to car speed
  fDistance += (70.0f * car.getfSpeed()) * fElapsedTime;

  // Get Point on track
  float fOffset = 0;
  int nTrackSection = 0;

  // Lap Timing and counting
  fCurrentLapTime += fElapsedTime;

  if (fDistance >= tracks.getTrackDistance()) {
    fDistance -= tracks.getTrackDistance();
    listLapTimes.push_front(fCurrentLapTime);
    listLapTimes.pop_back();
    fCurrentLapTime = 0.0f;
  }

  // Find position on track (could optimise maybe)
  while (nTrackSection < tracks.getTrackVec().size() && fOffset <= fDistance) {
    fOffset += tracks.getTrackVec()[nTrackSection].second;
    nTrackSection++;
  }

  // Interpolate towards target track curvature (GRADUALLY)
  fTargetCurvature = tracks.getTrackVec()[nTrackSection - 1].first;
  float fTrackCurveDiff = (fTargetCurvature - tracks.getfTrackCurvature()) *
                          fElapsedTime * car.getfSpeed();

  // Accumulate player curvature
  tracks.addTofTrackCurvature(fTrackCurveDiff);

  // Accumulate track curvature
  fAccTrackCurvature +=
      (tracks.getfTrackCurvature()) * fElapsedTime * car.getfSpeed();

  // Draw Sky
  for (int y = 0; y < ScreenHeight() / 2; y++) {
    for (int x = 0; x < ScreenWidth(); x++) {
      Draw(x, y, tracks.getSkyColor());
    }
  }

  // Draw hills w/ a sine wave
  for (int x = 0; x < ScreenWidth(); x++) {
    tracks.setnHillHeight(
        (int)(fabs(sinf(x * 0.01f + fAccTrackCurvature) * 16.0f)));

    for (int y = (ScreenHeight() / 2) - tracks.getnHillHeight();
         y < ScreenHeight() / 2; y++) {
      Draw(x, y, tracks.getHillsColor());
    }
  }

  // Draw Track, rows split into grass, groundClip and track
  for (int y = 0; y < ScreenHeight() / 2; y++) {
    for (int x = 0; x < ScreenWidth(); x++) {
      // Perspective illusion to modify the width of the track y segments
      float fPerspective = (float)y / (ScreenHeight() / 2.0f);
      float fRoadWidth = 0.1f + fPerspective * 0.8f;  // Min 10% Max 90%
      float fClipWidth = fRoadWidth * 0.15f;
      fRoadWidth *= 0.5f;  // Halve cuz track only goes to 'till middle of
                           // screen

      // Depending on where fMiddlePoint is
      float fMiddlePoint =
          0.5f + tracks.getfTrackCurvature() * powf((1.0f - fPerspective), 3);

      // Work out segment boundaries
      int nLeftGrass = (fMiddlePoint - fRoadWidth - fClipWidth) * ScreenWidth();
      int nLeftClip = (fMiddlePoint - fRoadWidth) * ScreenWidth();
      int nRightClip = (fMiddlePoint + fRoadWidth) * ScreenWidth();
      int nRightGrass =
          (fMiddlePoint + fRoadWidth + fClipWidth) * ScreenWidth();

      int nRow = ScreenHeight() / 2 + y;

      // Oscillatory functions to give illusion of perspective
      Pixel groundColor;
      if (sinf(20.0f * powf(1.0f - fPerspective, 3) + fDistance * 0.1f) >
          0.0f) {
        groundColor = tracks.getGroundColor1();
      } else {
        groundColor = tracks.getGroundColor2();
      }

      Pixel clipColor;
      if (sinf(80.0f * powf(1.0f - fPerspective, 2) + fDistance) > 0.0f) {
        clipColor = tracks.getClipColor1();
      } else {
        clipColor = tracks.getClipColor2();
      }

      // White flash on road for finish line
      Pixel roadColor;
      if ((nTrackSection - 1) == 0) {
        roadColor = WHITE;
      } else {
        roadColor = tracks.getRoadColor();
      }

      // Draw the row segments
      if (x >= 0 && x < nLeftGrass) {
        Draw(x, nRow, groundColor);
      }
      if (x >= nLeftGrass && x < nLeftClip) {
        Draw(x, nRow, clipColor);
      }
      if (x >= nLeftClip && x < nRightClip) {
        Draw(x, nRow, roadColor);
      }
      if (x >= nRightClip && x < nRightGrass) {
        Draw(x, nRow, clipColor);
      }
      if (x >= nRightGrass && x < ScreenWidth()) {
        Draw(x, nRow, groundColor);
      }
    }
  }

  // Draw car, car position on road is proportional to difference between
  // current accTrackCurvature and current accumulated player curvature
  //(if they're close enough, car will be in the middle of the track)
  car.setfCarPos(car.getfCarCurvature() - fAccTrackCurvature);
  car.setnCarPos(ScreenWidth() / 2 +
                 ((int)(ScreenWidth() * car.getfCarPos()) / 2.0) -
                 7);  // Offset for sprite

  // Draw the car representing player actions
  car.drawSprite(this);
  hud.drawHUD(this, fDistance, fTargetCurvature, car.getfCarCurvature(),
              fAccTrackCurvature, car.getfSpeed(), fCurrentLapTime,
              listLapTimes);

  return true;
}

bool MaxGearGame::OnUserDestroy() {
  // Sort and save record to file
  listLapTimes.sort();
  for (float lapTime : listLapTimes) {
    if (lapTime != 0.0f) {
      timeRecord = lapTime;
      break;
    }
  }
  writeRecordToFile();
  waveEngine.StopAll();
  waveEngine.DestroyAudio();

  return true;
}

void MaxGearGame::setTrackAudio() {
  switch (trackOption) {
    case PLAINS:
      trackAudio.LoadAudioWaveform("assets/sounds/las_vegas_track01_ost.wav");
      break;

    case DESERT:
      trackAudio.LoadAudioWaveform("assets/sounds/frankfurt_track02_ost.wav");
      break;

    default:
      trackAudio.LoadAudioWaveform("assets/sounds/easterEgg_ost.wav");
      break;
  }
}

string MaxGearGame::getRecordFromFile() {
  ifstream fp;
  string strTimeRecord;

  fp.open("Recorde.txt");
  if (!fp.is_open()) {
    return "Falha ao abrir o arquivo.";
  }

  fp.ignore(9, ' ');
  getline(fp, strTimeRecord);

  fp.close();

  return strTimeRecord;
}

void MaxGearGame::writeRecordToFile() {
  ofstream fp;

  fp.open("Recorde.txt");
  if (!fp.is_open()) {
    return;
  }

  //"Quit before finishing a single lap" case
  if ((hud.displayTime(timeRecord) == "-2147483648:-2147483648:-2147483648") ||
      (hud.displayTime(timeRecord) == "0:0:-1")) {
    fp << "Recorde: 0:0:0\n";
    fp.close();
    return;
  }

  fp << "Recorde: " << hud.displayTime(timeRecord) << '\n';
  fp.close();
}
