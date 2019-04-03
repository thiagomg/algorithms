#ifndef U_BTREE_H
#define U_BTREE_H

#pragma once

#include <vector>

namespace tmg {

template <typename T>
struct node_u_btree {
    node_u_btree *_left = nullptr;
    node_u_btree *_right = nullptr;
    T _value;
    node_u_btree(T value) {
        _value = value;
    }
};

template <typename T>
struct u_btree {
    using value_type = T;

    node_u_btree<T> *_root = nullptr;

    void add(T value) {
        _root = _add(_root, value);
    }

    node_u_btree<T> *_add(node_u_btree<T> *current, T value) {
        if(current == nullptr) {
            return new node_u_btree<T>(value);
        }

        if(value <= current->_value) {
            current->_left = _add(current->_left, value);
        } else {
            current->_right = _add(current->_right, value);
        }
        return current;
    }

    void _from_level(std::vector<T> &v, node_u_btree<T> *node, unsigned int level) {
        if(node == nullptr) {
            return;
        }

        if(level == 0) {
            v.push_back(node->_value);
            return;
        }
        _from_level(v, node->_left, level-1);
        _from_level(v, node->_right, level-1);
    }

    std::vector<T> from_level(unsigned int level) {
        if(_root == nullptr) {
            return {};
        }

        std::vector<T> values;
        _from_level(values, _root, level);
        return values;
    }

    void _items(std::vector<T> &v, node_u_btree<T> *node, unsigned int count) {
        if(node == nullptr) {
            return;
        }

        _items(v, node->_left, count);
        if(v.size() < count) {
            v.push_back(node->_value);
        }
        _items(v, node->_right, count);
    }

    std::vector<T> items(unsigned int count) {
        if(_root == nullptr) {
            return {};
        }

        std::vector<T> values;
        _items(values, _root, count);
        return values;
    }
};

}

#include <iostream>

namespace tmg_test {

using namespace tmg;

template <typename T>
void print_tree(node_u_btree<T> *node, int spaces) {
    for(int i=0; i < spaces; ++i) {
        std::cout << " ";
    }
    if(spaces > 0) std::cout << "+- ";
    if(node == nullptr) {
        std::cout << std::endl;
        return;
    }
    std::cout << node->_value<< std::endl;
    print_tree(node->_left, spaces+3);
    print_tree(node->_right, spaces+3);
}

template <typename T>
void print_tree(u_btree<T> &tree) {
    print_tree(tree._root, 0);
}

template <typename T>
void print_vec(std::vector<T> l) {
    for(const auto &v : l) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

void test_u_btree() {
    u_btree<int> tree;

    tree.add(10);
    tree.add(5);
    tree.add(7);
    tree.add(20);
    tree.add(3);
    tree.add(23);
    tree.add(18);
    tree.add(17);
    tree.add(16);
    tree.add(19);

    print_tree(tree);

    std::vector<int> v = tree.from_level(0);
    print_vec(v);

    print_vec(tree.from_level(0));
    print_vec(tree.from_level(1));
    print_vec(tree.from_level(2));
    print_vec(tree.from_level(3));
    print_vec(tree.from_level(4));
    print_vec(tree.from_level(5));

    std::cout << "--------------------" << std::endl;

    for(unsigned int i=0; i < 13; ++i) {
        print_vec(tree.items(i));
    }
    std::cout << "--------------------" << std::endl;
}

}

#endif // U_BTREE_H
