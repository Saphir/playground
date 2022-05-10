#include "test.hpp"

#include <cstdio>

namespace test_cpp {

/*
_ZN8test_cpp13test_cpp_funcEi
_ZN8test_cpp13test_cpp_funcEPKc
_ZN8test_cpp13test_cpp_funcERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
*/

void test_cpp_func(int v) { printf("Hello, World!\nYour number is %d!\n", v); }
void test_cpp_func(const std::string& s) {
  printf("Hello, World!\nYour string is %s!\n", s.c_str());
}
void test_cpp_func(const char* s) {
  printf("Hello, World!\nYour char* is %s!\n", s);
}
}  // namespace test_cpp
