#pragma once

namespace tmg
{

template <typename T>
struct node_linked_list
{
    node_linked_list<T> *_next = nullptr;
    T _value;

    node_linked_list(T &value)
    {
        _value = std::move(value);
    }

    T &value()
    {
        return _value;
    }

    bool has_next()
    {
        return _next != nullptr;
    }

    node_linked_list<T> *next()
    {
        return _next;
    }
};

template <typename T>
struct linked_list
{
    node_linked_list<T> *_first = nullptr;
    node_linked_list<T> *_last = nullptr;

    ~linked_list()
    {
        while (_first != nullptr)
        {
            node_linked_list<T> *next = _first->next();
            delete _first;
            _first = next;
        }
    }

    node_linked_list<T> *first()
    {
        return _first;
    }

    node_linked_list<T> *last()
    {
        return _last;
    }

    void push_back(T &&value)
    {
        node_linked_list<T> *n = new node_linked_list<T>(value);
        if (_first == nullptr)
        {
            _first = n;
        }
        if (_last == nullptr)
        {
            _last = n;
        }
        else
        {
            _last->_next = n;
            _last = n;
        }
    }

    void push_front(T &&value)
    {
        node_linked_list<T> *n = new node_linked_list<T>(value);
        n->_next = _first;
        _first = n;
    }

    void erase(int pos)
    {
        node_linked_list<T> *cur = _first;
        node_linked_list<T> *prev = nullptr;
        for (int i = 0; i < pos && cur != nullptr; ++i)
        {
            prev = cur;
            cur = cur->next();
        }

        if (cur != nullptr)
        {
            if (prev != nullptr)
                prev->_next = cur->_next;

            if (_first == cur)
            {
                _first = cur->next();
            }
            if (_last == cur)
            {
                _last = prev;
            }

            delete cur;
        }
    }
};

} // namespace tmg

#include <vector>
#include "test_helper.h"

namespace tmg_test
{

template <typename T>
void print(tmg::linked_list<T> &l)
{
    auto first = l.first();
    while (first != nullptr)
    {
        std::cout << first->value() << std::endl;
        first = first->next();
    }
}

template <typename T>
std::vector<T> _v(tmg::linked_list<T> &l)
{
    std::vector<T> v;
    auto first = l.first();
    while (first != nullptr)
    {
        v.push_back(first->value());
        first = first->next();
    }
    return v;
}

void test_linked_list()
{

    tmg::linked_list<int> l;
    l.push_back(20);
    l.push_back(30);
    l.push_back(40);
    l.push_front(10);
    l.push_front(5);

    assert_equal(1, 1);
    assert_equal(_v(l), {5, 10, 20, 30, 40});

    l.erase(0);
    assert_equal(_v(l), {10, 20, 30, 40});
    l.erase(3);
    assert_equal(_v(l), {10, 20, 30});
    l.erase(0);
    l.erase(1);
    l.erase(0);
    assert_equal(_v(l), {});
}

} // namespace tmg_test
