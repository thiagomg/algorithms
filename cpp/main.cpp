#include <iostream>
#include <algorithm>

#include "sort.h"
#include "linked_list.h"
#include "ll_stack.h"
#include "ll_queue.h"
#include "queue.h"
#include "dbl_linked_list.h"
#include "unbal_btree.h"


int main()
{
    tmg_test::test_sort();

    // List-type structures - MISSING: VECTOR
    tmg_test::test_linked_list();
    tmg_test::test_d_linked_list();
    tmg_test::test_ll_stack();
    tmg_test::test_ll_queue();
    tmg_test::test_queue();

    // Tree type structures
    // tmg_test::test_u_btree();
    // tmg_test::test_d_linked_list();
    
    std::cout << "If you see no errors, it means that all sort tests passed" << std::endl;
    return 0;
}
