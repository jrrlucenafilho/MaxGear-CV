#include <iostream>

#include "MaxGearGame.h"

using namespace std;

enum menuOptions { BEGIN_GAME = 1, SEE_RECORD = 2, QUIT_GAME = 3 };

int main(void) {
  MaxGearGame game;
  olc::sound::WaveEngine mainWaveEngine;
  olc::sound::Wave recordWave;
  olc::sound::Wave menuWave;
  int menuOption, trackOption, fullscreenOption;
  bool chosenScreenOption;

  cin.exceptions(ifstream::failbit);

  menuWave.LoadAudioWaveform("assets/sounds/title_ost.wav");
  recordWave.LoadAudioWaveform("assets/sounds/qualified_record_ost.wav");
  mainWaveEngine.InitialiseAudio();
  mainWaveEngine.PlayWaveform(&menuWave);

  while (true) {
    system("cls || clear");
    game.getMenu().ApresentarMenu();
    game.getMenu().ConferirOpcaoMenu(menuOption);

    switch (menuOption) {
      case BEGIN_GAME:
        system("cls || clear");
        chosenScreenOption =
            game.getMenu().ConferirOpcaoFullscreen(fullscreenOption);

        game.getMenu().ConferirOpcaoPista(trackOption);
        game.setTrackOption(trackOption);

        mainWaveEngine.StopAll();
        mainWaveEngine.DestroyAudio();

        if (game.Construct(160, 100, 2, 2, chosenScreenOption)) {
          game.Start();
        }

        mainWaveEngine.DestroyAudio();
        return 0;

      case SEE_RECORD:
        mainWaveEngine.StopAll();
        mainWaveEngine.PlayWaveform(&recordWave);

        cout << "Recorde da última partida: " << game.getRecordFromFile()
             << '\n';
        cout << "Pressione enter para continuar.\n";
        cin.get();

        mainWaveEngine.StopAll();
        mainWaveEngine.PlayWaveform(&menuWave);
        break;

      case QUIT_GAME:
        mainWaveEngine.DestroyAudio();
        return 0;

      default:
        game.getMenu().AvisoDefaultOpcaoInvalida();
        system("cls || clear");
        break;
    }
  }

  return 0;
}