#ifndef MYTEST_H_
#define MYTEST_H_
#include <string>
#include <iostream>
namespace mytest {
    struct Cnt {
    public:
        bool F;
        int counter_of_passed, counter;


        void update_flag();
        void count();
         //void run_tests();
    };

    mytest::Cnt& getMainCnt();

        // NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define MYTEST_INTERNAL_TEST_CASE(class_name, name) \
    void class_name();                              \
    namespace { \
    struct MagicInit_##class_name { \
    MagicInit_##class_name() { mytest::getMainCnt().update_flag(); std::cerr <<  "Running " << '"' << name << '"' << "...\n"; class_name(); mytest::getMainCnt().count(); } \
    } magic_init_##class_name; \
    }; \
    void class_name()

// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define MYTEST_INTERNAL_TEST_CASE2(line, name) \
    MYTEST_INTERNAL_TEST_CASE(mytest_test_class_##line, name)
// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define MYTEST_INTERNAL_TEST_CASE1(line, name) \
    MYTEST_INTERNAL_TEST_CASE2(line, name)
// NOLINTNEXTLINE(cppcoreguidelines-macro-usage)
#define TEST_CASE(name) MYTEST_INTERNAL_TEST_CASE1(__LINE__, name)

void check(bool expr, const char* expr_str, const char* file, int line, bool &f);
void check_message(bool expr, const char* expr_str, const char* file, int line, const char* msg, bool &f);
void check_end(int counter, int counter_of_passed);
//void update_flag();
//void count(int &counter_of_passed, int &counter);

#define CHECK(expr) \
    mytest::check(expr, #expr, __FILE__, __LINE__, mytest::getMainCnt().F)

#define CHECK_MESSAGE(expr, msg) \
    mytest::check_message(expr, #expr, __FILE__, __LINE__, msg, mytest::getMainCnt().F)
//#define CHECK(statement) TEST.add_statement(statement);

//#define CHECK_END() \
  //  mytest::check_end(getMainCnt().counter, getMainCnt().counter_of_passed)


}  // namespace mytest

#endif  // MYTEST_H_
