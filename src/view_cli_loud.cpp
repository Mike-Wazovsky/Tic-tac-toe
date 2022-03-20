#include "view.h"
#include <iostream>

namespace tictactoe {

    void View::view_cli() {
        Game game;
        game.make_a_field();
        std::string st;
        while (game.give_result() == 0) {
            Display_the_necessary_to_player(game);
            std::getline(std::cin, st);
            Work_with_string_and_make_a_move(st, game);
        }
        In_the_end(game);
    }

    void View::Right_move(Game game) {
        for (int i = 0; i < game.give_HEIGHT(); i++) {
            for (int j = 0; j < game.give_WIDTH(); j++) {
                std::cout << game.give_cell(i, j);
            }
            std::cout << '\n';
        }
        std::cout << "\n" << game.give_next_move() << " move: ";
    }
}  // namespace tictactoe
