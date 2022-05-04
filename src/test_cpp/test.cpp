#include <cstdio>

void test_cpp_func(int v) { printf("Hello, World!\nYour number is %d!\n", v); }

extern "C" {
void test_cpp_func_cwrapper(int v) { test_cpp_func(v); }
}
