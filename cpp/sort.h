#pragma once

#include <limits>
#include <vector>

template <typename T>
void bubble_sort(std::vector<T> &v) {
    bool swap;
    size_t max = v.size();
    do {
        swap = false;
        for(size_t i=1; i < max; ++i) {
            if(v[i-1] > v[i]) {
                std::swap(v[i-1], v[i]);
                swap = true;
            }
        }
        --max; //Optimization
    } while(swap);
}

template <typename T>
void selection_sort(std::vector<T> &v) {
    for(size_t i=0; i < v.size(); ++i) {
        size_t min = i;
        for(size_t j=i+1; j < v.size(); ++j) {
            if(v[j] < v[min]) {
                min = j;
            }
        }
        std::swap(v[i], v[min]);
    }

}

/* Merge sort ==================================================
   size_t start, size_t mid, size_t end
   This describes the ranges [start, end[ and [mid, end[
   
   copies might not be suitable for complex types. We should move instead
 */
template <typename T>
void merge(std::vector<T> &v, std::vector<T> &aux, size_t start, size_t mid, size_t end) {

    std::copy(v.begin()+start, v.begin()+end, aux.begin()+start);

    size_t i=start;
    size_t j=mid;

    // start     mid       end
    // 0         5         10
    // s   m     e/s m     e
    // 0   2     5   7     10
    // 0 1 2 3 4 5 6 7 8 9 (positions)
    
    for(size_t dest=start; dest < end; ++dest) {
        if(i >= mid) {
            // If i reached the end of its partition
            v[dest] = aux[j];
            ++j;
        } else if(j >= end) {
            // If j reached the end of its partition
            v[dest] = aux[i];
            ++i;
        } else if(aux[i] <= aux[j]) {
            // If first half index <=
            v[dest] = aux[i];
            ++i;
        } else {
            // If second half index <
            v[dest] = aux[j];
            ++j;
        }
    }
}

template <typename T>
void merge_sort(std::vector<T> &v, std::vector<T> &aux, size_t start, size_t end, int count, char side) {
    size_t distance = end-start;
    if(distance <= 1) return; // If we only have one element or less, we have nothing to sort

    // We are working with position, hence we need to start 
    size_t mid = start + (distance / 2);
    merge_sort(v, aux, start, mid, count+1, 'L');
    merge_sort(v, aux, mid, end, count+1, 'R');
    merge(v, aux, start, mid, end);
}

template <typename T>
void merge_sort(std::vector<T> &v) {
    std::vector<T> aux;
    aux.resize(v.size());
    merge_sort(v, aux, 0, v.size(), 0, 'L');
}
// Merge sort end ==============================================

// Quick sort start ============================================
// Quicksort is missing! Please help implementing
// Quick sort end ==============================================

// Bucket sort start ===========================================
// Bucket sort is missing! Please help implementing
// Bucket sort end =============================================

// Binary search ===============================================
// The array has to be sorted
template <typename T>
size_t binary_search(std::vector<T> &v, int value) {

    //index boundaries
    size_t l = 0;
    size_t r = v.size()-1;
    
    // let's go to the middle and check if the value is greater than or less than
    while(l <= r) {
        
        // size_t mid = l + ((r-l) / 2);
        size_t mid = (l + r) / 2;
        if( value == v[mid] ) {
            return mid;
        }

        if( r == 0 ) {
            // Right will overflow. This is a common bug found everywhere
            break;
        }

        if( value < v[mid] ) {
            r = mid-1;
        } else { // >
            l = mid+1;
        }
    
    }
    
    return std::numeric_limits<size_t>::max();
}

#include "test_helper.h"

namespace tmg_test {

    void test_sort() {

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
    }

}
