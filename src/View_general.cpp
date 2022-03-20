#include <iostream>
#include "view.h"

namespace tictactoe {
    View::View(Game &game) : game_(game) {}

    void View::Display_the_necessary_to_player(Game game) {
        if (is_the_previous_move_right) {
            Right_move(game);
        }
        else {
            Bad_move(game);
        }
    }

    void View::Bad_move(Game game) {
        std::cout << "Bad move!\n";
        std::cout << game.give_next_move() << " move: ";
    }

    void View::In_the_end(Game game) {
        if (game.give_result() == -1) {
            return;
        }
        std::cout << '\n';
        for (int i = 0; i < game.give_HEIGHT(); i++) {
            for (int j = 0; j < game.give_WIDTH(); j++) {
                std::cout << game.give_cell(i, j);
            }
            std::cout << '\n';
        }
        if (game.give_result() == 1) {
            std::cout << "O wins!";
        } else if (game.give_result() == 2) {
            std::cout << "X wins!";
        } else if (game.give_result() == 3) {
            std::cout << "Draw1";
        }
    }

    void View::Delete_extra_spaces(std::string &st) {
        while (st[0] == ' ')
            st.erase(0, 1);
    }

    int View::Read_a_number(std::string &st) {
        int sign = 1;
        if (st[0] == '-') {
            sign = -1;
            st.erase(0, 1);
        }
        int number = 0;
        while (st[0] >= '0' && st[0] <= '9') {
            number *= 10;
            number += (st[0] - '0');
            st.erase(0, 1);
        }
        number *= sign;
        return number;
    }

    std::pair<int, int> View::Make_a_possible_string_to_pair(std::string st) {
        Delete_extra_spaces(st);
        int number1 = Read_a_number(st);
        Delete_extra_spaces(st);
        int number2 = Read_a_number(st);
        return std::make_pair(number1, number2);
    }

    bool View::Check_on_the_correct_input(const std::string st) {
        auto x = st.size();
        int number_of_numbers = 0; // there are suppose to be 2 numbers
        bool is_prev_a_digit = false /*to count quantity of numbers*/, is_everything_ok = true/*check on extra symbols(not spaces,'-' or digits)*/;
        for (unsigned int i = 0; i < x; i++) {
            if (st[i] == ' ')
                is_prev_a_digit = false;
            if (st[i] != ' ') {
                if (st[i] >= '0' && st[i] <= '9') {
                    if (is_prev_a_digit == false) {
                        is_prev_a_digit = true;
                        number_of_numbers++;
                    }
                } else if (st[i] == '-' && i < x - 1) {
                    if (st[i + 1] < '0' || st[i + 1] > '9')
                        is_everything_ok = false;
                } else {
                    is_everything_ok = false;
                }
            }
        }
        if (is_everything_ok == false) {
            return false;
        }
        if (number_of_numbers != 2) {
            return false;
        }
        return true;
    }

    void View::Work_with_string_and_make_a_move(std::string st, Game &game) {
        std::pair<int, int> coordinates;
        if (Check_on_the_correct_input(st)) {
            coordinates = Make_a_possible_string_to_pair(st);
            if (game.Check_possibility_of_given_pair(coordinates.first, coordinates.second) == 1) {
                game.Make_a_move(coordinates.first, coordinates.second);
                game.Check_on_draw();
                game.Check_on_win(coordinates.first, coordinates.second);
                is_the_previous_move_right = true;
            } else {
                is_the_previous_move_right = false;
            }
        }
        else {
            is_the_previous_move_right = false;
        }
    }
}  // namespace tictactoe