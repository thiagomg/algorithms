#pragma once

#include "linked_list.h"

namespace tmg
{

// Queue using linked list as storage mechanism
template <typename T>
struct ll_queue
{

    linked_list<T> _list;

    void push(T &&value)
    {
        _list.push_back(std::move(value));
    }

    T pop()
    {
        T val = _list.first()->value();
        _list.erase(0);
        return val;
    }

    T peek()
    {
        return _list.first()->value();
    }
};

} // namespace tmg

#include "test_helper.h"

namespace tmg_test
{

void test_ll_queue()
{
    tmg::ll_queue<int> s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    assert_equal(s.peek(), 1);
    assert_equal(s.pop(), 1);
    assert_equal(s.pop(), 2);
    s.push(5);
    assert_equal(s.pop(), 3);
    assert_equal(s.pop(), 4);
    assert_equal(s.pop(), 5);
}

} // namespace tmg_test
