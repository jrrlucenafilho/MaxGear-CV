#ifndef MENU_H
#define MENU_H

#pragma once

#include <iostream>
#include <limits>

class Menu {
 public:
  Menu();
  virtual ~Menu();

  void ApresentarMenu();
  void ConferirOpcaoMenu(int& op);
  void ConferirOpcaoPista(int& op);
  bool ConferirOpcaoFullscreen(int op);
  void AvisoDefaultOpcaoInvalida();

 private:
  void MenuPista();
  void MenuFullscreen();
};

#endif