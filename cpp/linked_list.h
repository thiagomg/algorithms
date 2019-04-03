#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#pragma once

#include <utility>
#include <vector>

namespace tmg {

template <typename T>
struct node_linked_list {
    node_linked_list<T> *_next = nullptr;
    T _value;

    node_linked_list(T &value) {
        _value = std::move(value);
    }

    T& value() {
        return _value;
    }

    bool has_next() {
        return _next != nullptr;
    }

    node_linked_list<T> *next() {
        return _next;
    }

};

template <typename T>
struct linked_list {
    node_linked_list<T> *_first = nullptr;
    node_linked_list<T> *_last = nullptr;

    ~linked_list() {
        while(_first != nullptr) {
            node_linked_list<T> *next = _first->next();
            delete _first;
            _first = next;
        }
    }

    node_linked_list<T> *first() {
        return _first;
    }

    node_linked_list<T> *last() {
        return _last;
    }

    void push_back(T &&value) {
        node_linked_list<T> *n = new node_linked_list<T>(value);
        if(_first == nullptr) {
            _first = n;
        }
        if(_last == nullptr) {
            _last = n;
        } else {
            _last->_next = n;
            _last = n;
        }
    }

    void push_front(T &&value) {
        node_linked_list<T> *n = new node_linked_list<T>(value);
        n->_next = _first;
        _first = n;
    }

    void erase(int pos) {
	node_linked_list<T> *cur = _first;
	node_linked_list<T> *prev = nullptr;
	for(int i=0; i < pos && cur != nullptr; ++i) {
	    prev = cur;
	    cur = cur->next();
	}

	if(cur != nullptr) {
	    if(prev != nullptr) prev->_next = cur->_next;
	    
	    if(_first == cur) {
		_first = cur->next();
	    }
	    if(_last == cur) {
		_last = prev;
	    }
	    
	    delete cur;
	}

	std::cout << "ERASE[" << pos << "]" << std::endl;
    }

};

template <typename T>
struct stack {

    linked_list<T> _list;

    void push(T &&value) {
	_list.push_front(std::move(value));
    }

    T pop() {
	T val = _list.first()->value();
	_list.erase(0);
	return val;
    }

    T peek() {
	return _list.first()->value();
    }
    
};

template <typename T>
struct queue {

    linked_list<T> _list;
    
    void push(T &&value) {
	_list.push_back(std::move(value));
    }

    T pop() {
	T val = _list.first()->value();
	_list.erase(0);
	return val;
    }

    T peek() {
	return _list.first()->value();
    }
    
};

// Queue based in array. It would be better to have a template parameter defining the storage
template <typename T>
struct a_queue {
    
    std::vector<T> _list;
    size_t ini = 0;
    size_t end = 0;
    size_t count = 0;
    bool resize = false;

    a_queue() {
	_list.resize(4);
    }

    void auto_resize(bool r) {
	resize = r;
    }

    size_t get_pos(size_t pos) {
	// I know reminder is not optimal - likely 7x slower
	return pos % _list.size();
    }
    
    bool push(T &&value) {
	if( count == _list.size() ) {
	    if(resize) {
		std::cout << "Resize " << ini << "/" << end << std::endl;
		// We need to recalculate
		size_t old_size = _list.size();
		_list.resize(_list.size() * 2);

		if(ini >= end) {
		    // We have to move the data to the end
		    size_t offset = old_size - ini;
		    for(size_t s = 0; s != offset; ++s) {
			_list[ _list.size() - offset + s ] = std::move(_list[ ini + s ]);
			// TODO: Remove this init
			_list[ ini + s ] = T{};
		    }
		    ini =  _list.size() - offset;
		    std::cout << "moved ";
		    print();
		}
		std::cout << "Resize done" << std::endl;
	    } else {
		std::cout << "QUEUE FULL " << ini << "/" << end << " -> " << value << std::endl;
		return false;
	    }
	}

	++count;
	_list[end] = value;
	end = get_pos(++end);

	print();

	return true;
    }

    bool empty() {
	return (count == 0);
    }

    //TODO: We should return something like Either/Result
    //      Another possibility is to peek to get and pop to remove without return (return bool)
    T pop() {
	size_t pos = ini;
	ini = get_pos(++ini);
	--count;
	// return _list[pos];
	T v = _list[pos];
	//TODO: Remove T{}
	_list[pos] = T{};
	print();
	return v;
    }

    T peek() {
	return _list[ini];
    }

    void print() {
	std::cout << "[ ";
	for(const auto &i : _list) {
	    std::cout << i << " ";
	}
	std::cout << "]" << std::endl;
    }
    
};

}

#include <iostream>
namespace tmg_test {

    template<typename T>
    void print(tmg::linked_list<T> &l) {
	auto first = l.first();
	while(first != nullptr) {
	    std::cout << first->value() << std::endl;
	    first = first->next();
	}
    }
    
    void test_linked_list() {

	tmg::linked_list<int> l;
	l.push_back(20);
	l.push_back(30);
	l.push_back(40);
	l.push_front(10);
	l.push_front(5);

	print(l);
	std::cout << "--------------------" << std::endl;
	l.erase(0);
	print(l);
	l.erase(3);
	print(l);
	l.erase(0);
	l.erase(1);
	l.erase(0);
	print(l);

    }

    void test_stack() {
	tmg::stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	std::cout << "-> " << s.peek() << std::endl;
	s.push(4);

	std::cout << "-> " << s.peek() << std::endl;
	for(int i=0; i < 4; ++i) {
	    std::cout << s.pop() << std::endl;
	}
    }

    void test_queue() {
	tmg::queue<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	std::cout << "-> " << s.peek() << std::endl;
	s.push(4);

	std::cout << "-> " << s.peek() << std::endl;
	for(int i=0; i < 4; ++i) {
	    std::cout << s.pop() << std::endl;
	}
    }

    void test_a_queue() {
	tmg::a_queue<int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.push(6);
	s.pop();
	s.pop();
	s.push(7);
	s.pop();
	s.push(8);
	s.push(9);
	s.push(10);

	s.pop();
	s.pop();
	s.pop();
	s.pop();

	s.push(11);
	s.push(12);
	s.push(13);
	s.push(14);
	s.push(15);

	s = tmg::a_queue<int>();

	std::cout << "----------" << std::endl;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.pop();
	s.pop();
	s.push(5);
	s.push(6);
	s.auto_resize(true);
	s.push(7);
	s.push(8);
	s.push(9);
	s.push(10);
	s.push(11);
	std::cout << "peek: " << s.peek() << std::endl; // 3
	s.pop();
	s.pop();
	s.pop();
    }

}
#endif // LINKED_LIST_H
