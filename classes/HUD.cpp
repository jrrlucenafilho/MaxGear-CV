#include "HUD.h"

using namespace olc;

HUD::HUD() {
  // Sets all decals' positions on screen
  distDecal = {2, 2};
  targetCurvatureDecal = {2, 5};
  playerCurvatureDecal = {2, 8};
  trackCurvatureDecal = {2, 11};
  speedDecal = {2, 14};
  currentLaptimeDecal = {2, 19};
  listLapTimesTitleDecal = {2, 22};
}

HUD::~HUD() {}

void HUD::drawHUD(olc::PixelGameEngine* game, float fDistance,
                  float fTargetCurvature, float fPlayerCurvature,
                  float fTrackCurvature, float fSpeed, float fCurrentLapTime,
                  std::list<float> listLapTimes) {
  // Draw HUD Content
  game->DrawRect(0, 0, 51, 16, WHITE);
  game->FillRect(1, 1, 50, 15, BLACK);
  game->DrawStringDecal(distDecal, "Distancia:" + std::to_string(fDistance),
                        WHITE, {0.2f, 0.2f});
  game->DrawStringDecal(targetCurvatureDecal,
                        "Curvatura(Alvo):" + std::to_string(fTargetCurvature),
                        WHITE, {0.2f, 0.2f});
  game->DrawStringDecal(
      playerCurvatureDecal,
      "Curvatura(Jogador):" + std::to_string(fPlayerCurvature), WHITE,
      {0.2f, 0.2f});
  game->DrawStringDecal(trackCurvatureDecal,
                        "Curvatura(Pista):" + std::to_string(fTrackCurvature),
                        WHITE, {0.2f, 0.2f});
  game->DrawStringDecal(speedDecal, "Velocidade:" + std::to_string(fSpeed),
                        WHITE, {0.2f, 0.2f});

  // Display current lap's time
  game->FillRect(1, 17, 50, 3, BLACK);
  game->DrawStringDecal(currentLaptimeDecal,
                        "Tempo(Volta Atual): " + displayTime(fCurrentLapTime),
                        WHITE, {0.2f, 0.2f});

  // Display last 5 laps' times
  int j = 25;

  game->DrawRect(0, 17, 51, 20, WHITE);
  game->FillRect(1, 18, 50, 19, BLACK);
  game->DrawStringDecal(listLapTimesTitleDecal, "Ultimas 5 voltas: ", WHITE,
                        {0.2f, 0.2f});

  for (float lapTime : listLapTimes) {
    listLapTimesDecal = {2, (float)j};
    {
      game->DrawStringDecal(listLapTimesDecal, displayTime(lapTime), WHITE,
                            {0.2f, 0.2f});
      j += 2;
    }
  }
}

std::string HUD::displayTime(float fTime) {
  int nMinutes = fTime / 60.0f;
  int nSeconds = fTime - (nMinutes * 60.0f);
  int nMilliSeconds = (fTime - (float)nSeconds) * 1000.0f;

  return std::to_string(nMinutes) + ":" + std::to_string(nSeconds) + ":" +
         std::to_string(nMilliSeconds);
}
