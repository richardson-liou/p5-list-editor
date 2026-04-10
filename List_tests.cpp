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

TEST(test_equals_op_to_smaller_list) {
    List<int> a;
    a.push_back(3);

    List<int> b;
    b.push_back(2);
    b.push_back(7);

    b = a;

    ASSERT_EQUAL(b.size(), 1);
    ASSERT_EQUAL(b.front(), 3);
    ASSERT_EQUAL(b.back(), 3);
}

TEST(test_assign_empty) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);

    List<int> b;

    a = b;

    ASSERT_TRUE(a.empty());
    ASSERT_EQUAL(a.size(), 0);
}

TEST(test_assign_to_empty_target) {
    List<int> a;

    List<int> b;
    b.push_back(1);
    b.push_back(2);

    a = b;

    ASSERT_EQUAL(a.size(), 2);
    ASSERT_EQUAL(a.front(), 1);
    ASSERT_EQUAL(a.back(), 2);
}


TEST(test_assign_to_empty) {
    List<int> a;

    List<int> b;
    b.push_back(1);
    b.push_back(2);

    a = b;

    ASSERT_EQUAL(a.size(), 2);
    ASSERT_EQUAL(a.front(), 1);
    ASSERT_EQUAL(a.back(), 2);
}

TEST(test_copies) {
    List<int> a;
    a.push_back(1);

    List<int> b = a;
    b.push_back(2);

    ASSERT_EQUAL(a.size(), 1);
    ASSERT_EQUAL(b.size(), 2);
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
    ASSERT_EQUAL(a.back(), 5);
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
    ASSERT_TRUE(it == a.end());
    --it;
    ASSERT_EQUAL(*it, 3);
    --it;
    ASSERT_EQUAL(*it, 2);
    --it;
    ASSERT_EQUAL(*it, 1);
}

TEST(test_iterator_empty_list) {
    List<int> a;
    ASSERT_TRUE(a.begin() == a.end());
}

//Test insert
TEST(test_insert_front) {
    List<int> a;
    a.push_back(2);

    auto it = a.insert(a.begin(), 1);

    ASSERT_EQUAL(a.front(), 1);
    ASSERT_EQUAL(a.size(), 2);
    ASSERT_EQUAL(*it, 1);
}

TEST(test_insert_back) {
    List<int> a;
    a.push_back(2);

    a.insert(a.end(), 1);

    ASSERT_EQUAL(a.back(), 1);
    ASSERT_EQUAL(a.size(), 2);
}

TEST(test_insert_middle) {
    List<int> a;
    a.push_back(1);
    a.push_back(3);

    auto it = a.begin();
    ++it;

    a.insert(it, 2);

    auto itt = a.begin();
    ASSERT_EQUAL(*itt, 1);
    ++itt;
    ASSERT_EQUAL(*itt, 2);
    ++itt;
    ASSERT_EQUAL(*itt, 3);
}

//Test erase
TEST(test_erase_to_empty) {
    List<int> a;
    a.push_back(1);
    
    auto it = a.erase(a.begin());

    ASSERT_TRUE(a.empty());
    ASSERT_TRUE(it == a.end());
}

TEST(test_erase_front) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);

    auto erased = a.erase(a.begin());

    ASSERT_EQUAL(a.front(), 2);
    ASSERT_EQUAL(a.size(), 1);
    ASSERT_EQUAL(*erased, 2);
}

TEST(test_erase_back) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);

    auto it = a.end();
    it--;

    auto erased = a.erase(it);

    ASSERT_EQUAL(a.front(), 1);
    ASSERT_EQUAL(a.size(), 1);
    ASSERT_TRUE(erased == a.end());

}

TEST(test_erase_middle){
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    auto it = a.begin();
    ++it;

    a.erase(it);

    ASSERT_EQUAL(a.size(), 2);

    auto check = a.begin();
    ASSERT_EQUAL(*check, 1);
    ++check;
    ASSERT_EQUAL(*check, 3);
}

TEST(test_iterator_equality) {
    List<int> a;
    a.push_back(1);

    auto it1 = a.begin();
    auto it2 = a.begin();

    ASSERT_TRUE(it1 == it2);
}

TEST(test_erase_all) {
    List<int> a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    while (!a.empty()) {
        a.erase(a.begin());
    }

    ASSERT_TRUE(a.empty());
}


TEST_MAIN()
