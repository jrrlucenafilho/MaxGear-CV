#include "Menu.h"

using namespace std;

Menu::Menu() {}

Menu::~Menu() {}

void Menu::ApresentarMenu() {
  cout << "|----------------------------------------------------------|\n"
          "| \t    __  ___           ______                   \t   |\n"
          "| \t   /  |/  /___ __  __/ ____/__  ____ ______    \t   |\n"
          "| \t  / /|_/ / __ `/ |/_/ / __/ _ \\/ __ `/ ___/    \t   |\n"
          "| \t / /  / / /_/ />  </ /_/ /  __/ /_/ / /        \t   |\n"
          "| \t/_/  /_/\\__,_/_/|_|\\____/\\___/\\__,_/_/         \t   |\n"
          "| \t                                               \t   |\n";

  cout << "|----------------------------------------------------------|\n"
          "|\t\t\t\t\t\t\t   |\n"
          "|\t[1] - Iniciar Jogo\t[2] - Ver Recorde\t   |\n"
          "|\t\t\t\t\t\t\t   |\n"
          "|\t\t\t[3] - Sair\t\t\t   |\n"
          "|\t\t\t\t\t\t\t   |\n"
          "|----------------------------------------------------------|\n\n";
  cout << ">> ";
}

void Menu::ConferirOpcaoMenu(int& op) {
  while (true) {
    bool enteredCatch = false;

    try {
      cin >> op;
      cin.ignore();
    } catch (ios_base::failure& failbit) {
      cout << "Você digitou algo inválido.\n";
      cout << "Pressione enter para continuar.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin.get();
      enteredCatch = true;
    }

    if (!enteredCatch) {
      break;
    }

    system("cls || clear");
    ApresentarMenu();
  }
}

void Menu::AvisoDefaultOpcaoInvalida() {
  cout << "Opção inválida\n";
  cout << "Pressione enter para continuar.\n";
  cin.get();
}

void Menu::ConferirOpcaoPista(int& op) {
  while (true) {
    bool enteredCatch = false;
    MenuPista();

    try {
      cin >> op;
      cin.ignore();
    } catch (ios_base::failure& failbit) {
      cout << "Você digitou algo inválido.\n";
      cout << "Pressione enter para continuar.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin.get();

      op = 0;
      enteredCatch = true;
    }

    if ((op == 1) || (op == 2) || (op == 13)) {
      break;
    }

    if (!enteredCatch) {
      cout << "Opção inválida, tente novamente\n";
      cout << "Pressione enter para continuar.\n";
      cin.get();
    }
    system("cls || clear");
  }
}

bool Menu::ConferirOpcaoFullscreen(int op) {
  while (true) {
    bool enteredCatch = false;
    MenuFullscreen();

    try {
      cin >> op;
      cin.ignore();
    } catch (ios_base::failure& failbit) {
      cout << "Você digitou algo inválido.\n";
      cout << "Pressione enter para continuar.\n";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n');
      cin.get();

      op = 0;
      enteredCatch = true;
    }

    if (op == 1) {
      system("cls || clear");
      return true;
    }

    if (op == 2) {
      system("cls || clear");
      return false;
    }

    if (!enteredCatch) {
      cout << "Opção inválida, tente novamente\n";
      cout << "Pressione enter para continuar.\n";
      cin.get();
    }
    system("cls || clear");
  }
}

void Menu::MenuPista() {
  cout << "|----------------------------------------------------------|\n"
          "|\t\t  Escolha sua pista, jogador\t\t   |\n"
          "|----------------------------------------------------------|\n"
          "|\t\t\t\t\t\t\t   |\n"
          "|\t\t[1] - Planície\t[2] - Deserto\t\t   |\n"
          "|\t\t\t\t\t\t\t   |\n"
          "|----------------------------------------------------------|\n\n"
          "\n\n----! Dicas de jogo !----\n"
          "-> Controles:\n"
          " Acelerar: Seta para cima, Botão esquerdo do mouse/mousepad ou "
          "barra de espaço.\n"
          " Direções: Setas para a esquerda e direita\n";
}

void Menu::MenuFullscreen() {
  cout << "|----------------------------------------------------------|\n"
          "|\t\t          Tela cheia?\t\t           |\n"
          "|----------------------------------------------------------|\n"
          "|\t\t\t\t\t\t\t   |\n"
          "|\t\t[1] - Sim\t[2] - Não\t\t   |\n"
          "|\t\t\t\t\t\t\t   |\n"
          "|----------------------------------------------------------|\n\n";
}
