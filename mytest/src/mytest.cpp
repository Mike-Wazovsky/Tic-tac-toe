#include "mytest.h"
#include <iostream>

namespace mytest {
namespace {

}  // namespace
    void check(bool expr, const char* expr_str, const char* file, int line, bool &f) {
        if (!expr) {
            f = false;
            std::cerr << expr_str << " at " << file << ":" << line << " failed!\n";
        }
    }

    void check_message(bool expr, const char* expr_str, const char* file, int line, const char* msg, bool &f) {
        if (!expr) {
            f = false;
            std::cerr << expr_str << " at " << file << ":" << line << " failed!\n" << "message: " << msg << "\n";
        }
    }

    void check_end(int counter, int counter_of_passed) {
        std::cerr << "===== Tests passed: " << counter_of_passed << "/" << counter << " =====\n";
    }

    void Cnt::update_flag() {
        F = true;
    }

    void Cnt::count() {
        if (F == true)
            counter_of_passed++;
        counter++;
    }

    Cnt &getMainCnt(){
        static Cnt mainCnt1;
        return mainCnt1;
    }

    /*void final_string() {

    }*/

}  // namespace mytest

