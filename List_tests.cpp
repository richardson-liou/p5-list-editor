#include "List.hpp"
#include "unit_test_framework.hpp"

using namespace std;

// Add your test cases here

//Test default constructor and copy constructor
TEST(test_dflt_const) {
    List<int> a;
    ASSERT_TRUE(a.empty());
    ASSERT_EQUAL(a.size(), 0);
}

TEST(test_copy_const) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);

    List<int> b = a;

    ASSERT_EQUAL(b.size(), 2);
    ASSERT_EQUAL(b.front(), 1);
    ASSERT_EQUAL(b.back(), 2);
}

//Test empty, size, front back
TEST(test_getters) {
    List<int> a;
    a.push_back(3);
    a.push_back(7);

    ASSERT_FALSE(a.empty());
    ASSERT_EQUAL(a.size(), 2);
    ASSERT_EQUAL(a.front(), 3);
    ASSERT_EQUAL(a.back(), 7);
}

//Test = operator
TEST(test_equals_op) {
    List<int> a;
    a.push_back(3);
    a.push_back(7);

    List<int> b;
    b.push_back(2);

    b = a;

    ASSERT_EQUAL(b.size(), 2);
    ASSERT_EQUAL(b.front(), 3);
    ASSERT_EQUAL(b.back(), 7);
}

//Test push_front on empty and non-empty list
TEST(test_push_front_mult) {
    List<int> a;
    a.push_front(2);
    a.push_front(3);
    a.push_front(4);

    ASSERT_EQUAL(a.size(),3);
    ASSERT_EQUAL(a.front(), 4);
    ASSERT_EQUAL(a.back(), 2);
}

//Test push_back on empty and non-empty list

TEST(test_push_back_mult) {
    List<int> a;
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);

    ASSERT_EQUAL(a.size(),3);
    ASSERT_EQUAL(a.front(), 2);
    ASSERT_EQUAL(a.back(), 4);
}

//Test pop_front and pop_back on empty and non-empty list
TEST(test_pop_front_single_elt) {
    List<int> a;
    a.push_back(1);
    a.pop_front();

    ASSERT_TRUE(a.empty());
}

TEST(test_pop_front_not_empty){
    List<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.pop_front();

    ASSERT_EQUAL(a.size(), 2);
    ASSERT_EQUAL(a.front(), 3);
    ASSERT_EQUAL(a.back(), 1);
}

TEST(test_pop_back_single_elt) {
    List<int> a;
    a.push_back(1);
    a.pop_back();

    ASSERT_TRUE(a.empty());
}

TEST(test_pop_back_not_empty){
    List<int> a;
    a.push_back(1);
    a.push_back(3);
    a.push_back(5);
    a.pop_back();

    ASSERT_EQUAL(a.size(), 2);
    ASSERT_EQUAL(a.front(), 1);
    ASSERT_EQUAL(a.back(), 3);
}

//Test iterator iteration
TEST(test_iterator_plus_minus) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    auto it = a.begin();

    ASSERT_EQUAL(*it, 1);
    ++it;
    ASSERT_EQUAL(*it, 2);
    ++it;
    ASSERT_EQUAL(*it, 3);
    ++it;
    ASSERT_EQUAL(*it, nullptr);
    --it;
    ASSERT_EQUAL(*it, 3);
    --it;
    ASSERT_EQUAL(*it, 2);
    --it;
    ASSERT_EQUAL(*it, 1);
}

TEST(test_stub) {
    // Add test code here
    ASSERT_TRUE(true);
}

TEST_MAIN()
