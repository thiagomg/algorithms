#pragma once

#include <vector>

#include <limits>
#include <algorithm>

#include "prettyprint.hpp"

#define assert_equal _assert{__FILE__, __LINE__}

namespace tmg_test {
		
	struct _assert {
		std::string _file_name;
		int _line;
		
		template<typename T>
		void _print_error(const std::string &s, int line, const T& v, const T& expected) {
			std::cout << s << " - " << line << std::endl;
			std::cout << "Ouch! Something happened. The values should be the same" << std::endl;
			std::cout << "- Expected: " << expected << std::endl;
			std::cout << "- Found:    " << v << std::endl;
			std::cout << "------------------------------" << std::endl;
		}
		
		void operator()(const std::string& v, const std::string& expected) {
			bool ret = (v == expected);
			if(!ret) {
				_print_error(_file_name, _line, v, expected);
			}    
		}

		void operator()(int v, int expected) {
			bool ret = (v == expected);
			if(!ret) {
				_print_error(_file_name, _line, v, expected);
			}    
		}
		
		void operator()(size_t v, size_t expected) {
			bool ret = (v == expected);
			if(!ret) {
				_print_error(_file_name, _line, v, expected);
			}    
		}

		std::string _from_bool(bool v) {
			return v ? "true" : "false";
		}

		void operator()(bool v, bool expected) {
			bool ret = (v == expected);
			if(!ret) {
				_print_error(_file_name, _line, _from_bool(v), _from_bool(expected));
			}    
		}

		template<typename T>
		void operator()(const std::vector<T>& v, const std::vector<T>& expected) {
			bool ret = std::equal(std::begin(v), std::end(v), std::begin(expected), std::end(expected));
			if(!ret) {
				_print_error(_file_name, _line, v, expected);
			}
		}
	};


}
