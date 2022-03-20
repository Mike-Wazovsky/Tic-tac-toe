#ifndef VIEW_H_
#define VIEW_H_

#include <string>
#include "game.h"

namespace tictactoe {
    struct View {
    public:
        Game &game_;
        explicit View(Game &game);
        bool is_the_previous_move_right = true;

        void Right_move(Game game); // starts if move correct
        void Bad_move(Game game); // starts if move incorrect
        void In_the_end(Game game); // out the field and result then the game ends
        bool Check_on_the_correct_input(std::string st); // Check that player introduced 2 numbers in string
        std::pair<int, int> Make_a_possible_string_to_pair(std::string st); // If string is correct transforms string to coordinates
        int Read_a_number(std::string &st); // helps Make_a_possible_string_to_pair
        void Delete_extra_spaces(std::string &st); // helps Make_a_possible_string_to_pair
        void Work_with_string_and_make_a_move(std::string st, Game &game); // The only function that changes a game
        void Display_the_necessary_to_player(Game game); //run Right_move or Bad_move
        //void Display_the_necessary_to_player_silent(Game game); //run Bad_move if move is really bad
        void view_cli(); // on of the form of games
        //void view_cli_loud(); // on of the form of games
    };
}  // namespace tictactoe

#endif  // VIEW_H_
