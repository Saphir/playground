#include <unistd.h> /* read sleep NULL close */

#include <cstdio>   /* fopen fgets printf */
#include <cstdlib>  /* exit system malloc atoi rand */
#include <iostream> /* std::cout std::endl */

#include "test_cpp/test.hpp"
extern "C" {
#include "test_c/test.h"
}

void foo() {
  int a = 7;
  student_t s1 = {0};
  s1.cls = 'A';
  s1.grade = 100;
  s1.point = &a;

  student_t s2 = {0};
  s2.cls = 'B';
  s2.grade = 99;
  s2.point = &a;

  nest_stu_t ns = {0};
  ns.rank = 'A';
  ns.nest_stu = s1;
  ns.strct_array[0] = s2;
  ns.strct_point = &s1;
  ns.strct_point_array[0] = &s1;
  ns.strct_point_array[1] = &s2;

  nest_stu_t out = {0};
  test_c_func('a', 1, 2.3, (char *)&s1, (char *)&ns, (char *)&out);
}

void bar() { test_cpp_func(7); }

int main(int argc, char *argv[]) {
  foo();
  bar();
  return EXIT_SUCCESS;
}
