#include "game.h"
#include <cassert>
#include <cstddef>
#include <iterator>
#include <string>

namespace tictactoe {
    void Game::Make_a_move(int x, int y) {
        field[x][y] = next_move;
        Change_turn();
    }

    void Game::make_a_field() {
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                field[i][j] = '.';
            }
        }
    }

    void Game::Change_turn() {
        if (next_move == 'O')
            next_move = 'X';
        else if (next_move == 'X')
            next_move = 'O';
    }

    void Game::Check_on_draw() {
        bool f = true;
        for (int i = 0; i < HEIGHT; i++) {
            for (int j = 0; j < WIDTH; j++) {
                if (field[i][j] == '.') {
                    f = false;
                }
            }
        }
        if (f)
            result = 3;
    }

    int Game::Check_in_the_certain_direction(int x, int y, int x_direction, int y_direction) {
        int counter = 0, a = x, b = y;
        while (x >= 0 && x <= HEIGHT && y >= 0 && y <= WIDTH && field[a][b] == field[x][y]) {
            counter++;
            a += x_direction;
            b += y_direction;
        }
        return counter;
    }

    void Game::Give_a_direction_for_check(int x, int y, int x_direction, int y_direction) {
        int count = -1;
        count += Check_in_the_certain_direction(x, y, x_direction, y_direction);
        count += Check_in_the_certain_direction(x, y, -x_direction, -y_direction);
        if (count >= ROW_TO_WIN) {
            if (next_move == 'O')
                result = 2;
            if (next_move == 'X')
                result = 1;
        }
    }

    void Game::Check_on_win(int x, int y) {
        if (x == -1 || y == -1) {
            result = -1;
        }
        else {
            Give_a_direction_for_check(x, y, 1, 0);
            Give_a_direction_for_check(x, y, 0, 1);
            Give_a_direction_for_check(x, y, 1, 1);
            Give_a_direction_for_check(x, y, 1, -1);
        }
    }

    bool Game::Check_possibility_of_given_pair(int x, int y) {
        if (x == -1 && y == -1)
            return true;
        if (x >= 0 && x <= HEIGHT && y >= 0 && y <= WIDTH && field[x][y] == '.')
            return true;
        return false;
    }

    char Game::give_next_move() {
        return next_move;
    }

    int Game::give_result() {
        return result;
    }

    int Game::give_HEIGHT() {
        return HEIGHT;
    }

    int Game::give_WIDTH() {
        return WIDTH;
    }

    char Game::give_cell(int x, int y) {
        return field[x][y];
    }
}  // namespace tictactoe 3