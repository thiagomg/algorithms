#include <iostream>
#include <vector>
#include <map>

#include "sort.h"
#include "test_helper.h"

int sort_test() {

    auto reset = []() -> std::vector<int> { return { 6, 1, 2, 4, 8, 6, 4, 9, 11, 10 }; };
    auto ordered = []() -> std::vector<int> { return {1, 2, 4, 4, 6, 6, 8, 9, 10, 11}; };
    
    std::vector<int> a = reset();
    bubble_sort(a);
    assert_equal(a, ordered());

    a = reset();
    selection_sort(a);
    assert_equal(a, ordered());

    a = reset();
    merge_sort(a);
    assert_equal(a, ordered());

    // Please implement bucket sort and quick sort!!!
    
    //  0  1  2  3  4  5  6  7   8   9
    // [1, 2, 4, 4, 6, 6, 8, 9, 10, 11]
    a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
    for(int v : a) {
        size_t expected_idx = v - 1;
        size_t idx = binary_search(a, v);
        assert_equal(idx, expected_idx);
    }

    // Let's ensure if finds if duplicates are in here
    a = ordered();
    assert_equal(binary_search(a, 4), 2U);
    assert_equal(binary_search(a, 6), 4U);

    // Those are not in the array.
    assert_equal(binary_search(a, 3), std::numeric_limits<size_t>::max());
    assert_equal(binary_search(a, 7), std::numeric_limits<size_t>::max());
    assert_equal(binary_search(a, 0), std::numeric_limits<size_t>::max());
    assert_equal(binary_search(a, 12), std::numeric_limits<size_t>::max());

    std::cout << "If you see no errors, it means that all sort tests passed" << std::endl;
    
    return 0;
}

int main() {
    sort_test();
}
