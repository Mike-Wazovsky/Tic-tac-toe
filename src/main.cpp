#include "view.h"
#include <iostream>
int main() {
    tictactoe::Game game;
    tictactoe::View view(game);
    view.view_cli();
}
