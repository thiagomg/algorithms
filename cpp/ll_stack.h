#pragma once

#include "linked_list.h"

namespace tmg
{

// Stack implementation using linked list
template <typename T>
struct ll_stack
{

    linked_list<T> _list;

    void push(T &&value)
    {
        _list.push_front(std::move(value));
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

void test_ll_stack()
{
    tmg::ll_stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    assert_equal(s.peek(), 3);
    s.push(4);

    assert_equal(s.peek(), 4);
    for (int i = 4; i > 0; --i)
    {
        assert_equal(s.pop(), i);
    }
}

} // namespace tmg_test
