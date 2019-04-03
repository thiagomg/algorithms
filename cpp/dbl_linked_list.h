#pragma once

#include <utility>

namespace tmg {

template <typename T>
struct node_d_linked_list {
    node_d_linked_list<T> *_prev = nullptr;
    node_d_linked_list<T> *_next = nullptr;
    T _value;

    node_d_linked_list(T &value) {
        _value = std::move(value);
    }

    bool has_prev() {
        return _prev != nullptr;
    }
    bool has_next() {
        return _next != nullptr;
    }
    node_d_linked_list<T> *prev() {
	return _prev;
    }
    node_d_linked_list<T> *next() {
	return _next;
    }
    T &value() {
	return _value;
    }
};

template <typename T>
struct d_linked_list {
    node_d_linked_list<T> *_first = nullptr;
    node_d_linked_list<T> *_last = nullptr;

    ~d_linked_list() {
        while(_first != nullptr) {
            node_d_linked_list<T> *next = _first->next();
            delete _first;
            _first = next;
        }
    }

    node_d_linked_list<T> *first() {
        return _first;
    }

    node_d_linked_list<T> *last() {
        return _last;
    }

    void push_back(T &&value) {
	node_d_linked_list<T> *n_item = new node_d_linked_list<T>(value);
	if(_first == nullptr && _last == nullptr) {
	    _first = n_item;
	    _last = n_item;
	    return;
	}
	_last->_next = n_item;
	n_item->_prev = _last;
	_last = n_item;
    }

    void push_front(T &&value) {
	node_d_linked_list<T> *n_item = new node_d_linked_list<T>(value);
	if(_first == nullptr && _last == nullptr) {
	    _first = n_item;
	    _last = n_item;
	    return;
	}
	_first->_prev = n_item;
	n_item->_next = _first;
	_first = n_item;
    }

    void erase(int pos) {
	if(_first == _last && _first != nullptr) {
	    //Just one item. Let's simplify
	    delete _first;
	    _first = nullptr;
	    _last = nullptr;
	}
	
	node_d_linked_list<T> *cur = _first;
	for(int i=0; i < pos && cur != nullptr; ++i) {
	    cur = cur->next();
	}
	
	if(cur != nullptr) {
	    node_d_linked_list<T> *p = cur->_prev;
	    node_d_linked_list<T> *n = cur->_next;
	    if(p != nullptr) p->_next = n;
	    if(n != nullptr) n->_prev = p;
	    if(_first == cur) _first = n;
	    if(_last == cur) _last = p;
	    delete cur;
	}

	// std::cout << "ERASE[" << pos << "]" << std::endl;
    }

};

}

#include <iostream>
namespace tmg_test {

    template<typename T>
    void print(tmg::d_linked_list<T> &l) {

	auto first = l.first();
	while(first != nullptr) {
	    std::cout << first->value() << std::endl;
	    first = first->next();
	}

    }

    template<typename T>
    void print_rev(tmg::d_linked_list<T> &l) {

	auto last = l.last();
	while(last != nullptr) {
	    std::cout << last->value() << std::endl;
	    last = last->prev();
	}

    }

    void test_d_linked_list() {

	tmg::d_linked_list<std::string> l;
	l.push_back ("+20");
	l.push_back ("+30");
	l.push_back ("+40");
	l.push_front("+10");
	l.push_front("+5");

	print(l);
	std::cout << "----------" << std::endl;
	print_rev(l);
	std::cout << "----------" << std::endl;
	l.erase(0);
	print(l);
	l.erase(2);
	print(l);
	l.erase(0);
	print(l);
	l.erase(1);
	print(l);
	l.erase(0);
	print(l);
    }

}
