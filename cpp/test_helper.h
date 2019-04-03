#pragma once

#include <limits>
#include <algorithm>

#include "prettyprint.hpp"

#define assert_equal(x, y) _assert_equal(__FILE__, __LINE__, x, y)

template<typename T>
void _print_error(const std::string &s, int line, const T& v, const T& expected) {
    std::cout << s << " - " << line << std::endl;
    std::cout << "Ouch! Something happened. The values should be the same" << std::endl;
    std::cout << "- Expected: " << expected << std::endl;
    std::cout << "- Found:    " << v << std::endl;
    std::cout << "------------------------------" << std::endl;
}

template<typename T>
void _assert_equal(const std::string &s, int line, const std::vector<T>& v, const std::vector<T>& expected) {
    bool ret = std::equal(std::begin(v), std::end(v), std::begin(expected), std::end(expected));
    if(!ret) {
        _print_error(s, line, v, expected);
    }    
}

void _assert_equal(const std::string &s, int line, int v, int expected) {
    bool ret = (v == expected);
    if(!ret) {
        _print_error(s, line, v, expected);
    }    
}

void _assert_equal(const std::string &s, int line, size_t v, size_t expected) {
    bool ret = (v == expected);
    if(!ret) {
        _print_error(s, line, v, expected);
    }    
}
