#include "mytest.h"
#include <iostream>

namespace other_namespace {
namespace {
void foo() {
    CHECK(2 * 2 == 7);
}
}  // namespace
}  // namespace other_namespace

namespace mytest_demo3 {
namespace {
TEST_CASE("Demo3.cpp test case with complex calls") {
    if (true)  // NOLINT(readability-simplify-boolean-expr,readability-braces-around-statements)
        CHECK(2 * 2 == 5);
    else  // NOLINT(readability-braces-around-statements)
        CHECK(2 * 2 == 6);
    other_namespace::foo();
}
/*TEST_CASE("Demo3.cpp end of test cases") {
    CHECK_END();
}*/
}  // namespace
}  // namespace mytest_demo3
