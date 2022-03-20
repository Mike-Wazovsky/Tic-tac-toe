#ifndef GAME_H_
#define GAME_H_

#include "game_fwd.h"
#include <string>

namespace tictactoe {
        struct Game {
        private:
            static const int HEIGHT = 10;
            static const int WIDTH = 10;
            static const int ROW_TO_WIN = 5;
            char field[HEIGHT][WIDTH] = {};
            char next_move = 'O';
            int result = 0;
        public:
            void Make_a_move(int x, int y); // change field with a given move
            void Change_turn(); // change the turn of next move
            void make_a_field(); // generate a field in the begin
            int Check_in_the_certain_direction(int x, int y, int x_direction, int y_direction); // Look on the sequence of the same cells
            void Give_a_direction_for_check(int x, int y, int x_direction, int y_direction); // delete the copypaste and helps Check_on_win call Check_in_the_certain_direction
            void Check_on_win(int x, int y); // using previous function to understand, is the game over
            bool Check_possibility_of_given_pair(int x, int y); // look on the field and return is the cell occupied
            void Check_on_draw(); // if the field filled end game with the draw

            char give_next_move();
            int give_result();
            int give_HEIGHT();
            int give_WIDTH();
            char give_cell(int x, int y);
        };

}  // namespace tictactoe

#endif  // GAME_H_
