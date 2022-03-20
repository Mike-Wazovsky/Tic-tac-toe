#include "game.h"
#include "mytest.h"

namespace tictactoe {
    TEST_CASE("Rigth test case 1") {
        CHECK(2 * 2 == 4);
    }

    TEST_CASE("Wrong test case 2") {
        CHECK(2 * 2 == 5);
    }

}  // namespace tictactoe
