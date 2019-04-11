#pragma once

namespace tmg
{

// Queue based in array. It would be better to have a template parameter defining the storage
template <typename T>
struct queue
{
    // TODO: Implement my own vector in the future
    std::vector<T> _list;
    size_t ini = 0;
    size_t end = 0;
    size_t count = 0;

    queue(size_t max_size)
    {
        _list.resize(max_size);
    }

    size_t get_pos(size_t pos)
    {
        // I know remainder is not optimal - likely 7x slower
        return pos % _list.size();
    }

    bool push(T &&value)
    {
        if (count == _list.size())
        {
            // Queue full
            return false;
        }

        ++count;
        _list[end] = value;
        end = get_pos(++end);

        return true;
    }

    bool empty()
    {
        return (count == 0);
    }

    //TODO: We should return something like Either/Result
    //      Another possibility is to peek to get and pop to remove without return (return bool)
    T pop()
    {
        size_t pos = ini;
        ini = get_pos(++ini);
        --count;
        return _list[pos];
    }

    T peek()
    {
        return _list[ini];
    }

};

} // namespace tmg

#include "test_helper.h"

namespace tmg_test
{

void test_queue()
{
    tmg::queue<int> s(4);

    assert_equal(s.push(1), true);
    assert_equal(s.push(2), true);
    assert_equal(s.push(3), true);
    assert_equal(s.push(4), true);

    assert_equal(s.peek(), 1);
    assert_equal(s.pop(), 1);
    assert_equal(s.pop(), 2);
    assert_equal(s.push(5), true);
    assert_equal(s.pop(), 3);
    assert_equal(s.pop(), 4);
    assert_equal(s.pop(), 5);

    assert_equal(s.push(1), true);
    assert_equal(s.push(2), true);
    assert_equal(s.push(3), true);
    assert_equal(s.push(4), true);
    assert_equal(s.push(5), false);
    assert_equal(s.pop(), 1);
    assert_equal(s.push(5), true);
}

} // namespace tmg_test
