#include <iostream>
#include <algorithm>

#include "test_helper.h"

#include "sort.h"
#include "linked_list.h"
#include "d_linked_list.h"
#include "u_btree.h"


int main()
{
    tmg_test::test_sort();

    // I am going to enable those as soon as I adapt it to test instead of just cout
    // tmg_test::test_linked_list();
    // tmg_test::test_stack();
    // tmg_test::test_queue();
    // tmg_test::test_a_queue();
    // tmg_test::test_u_btree();
    // tmg_test::test_d_linked_list();

    std::cout << "If you see no errors, it means that all sort tests passed" << std::endl;
    return 0;
}