#include "test.h"

#include <stdio.h>
#include <string.h>

g_stu_t g_stu = {11};

int test_c_func(char char_arg, int int_arg, float float_arg, char *string_arg,
                char *stu_buf, char *nest_stu_buf, char *out_buf) {
  // data type test
  printf("char arg: %c\n", char_arg);
  printf("int arg: %d\n", int_arg);
  printf("float arg: %f\n", float_arg);
  printf("string arg: %s\n", string_arg);

  student_t *stu_p = NULL;
  nest_stu_t *nest_stu_p = NULL;

  stu_p = (student_t *)stu_buf;
  nest_stu_p = (nest_stu_t *)nest_stu_buf;
  // struct type test
  printf("struct class: %c\n", stu_p->cls);
  printf("struct grade: %d\n", stu_p->grade);
  printf("struct array[0]: %ld array[1]: %ld\n", stu_p->array[0],
         stu_p->array[1]);
  printf("struct point: %d\n", *(stu_p->point));

  // nest struct test
  printf("nest struct rank: %d\n", nest_stu_p->rank);
  printf("nest struct stu grade: %d\n", nest_stu_p->nest_stu.grade);

  // struct array
  printf("nest struct array[0] grade: %d\n", nest_stu_p->strct_array[0].grade);
  printf("nest struct array[1] grade: %d\n", nest_stu_p->strct_array[1].grade);

  // struct point
  printf("nest struct point grade: %d\n", nest_stu_p->strct_point->grade);
  // struct point array
  printf("nest struct point array[0] grade: %d\n",
         nest_stu_p->strct_point_array[0]->grade);
  printf("nest struct point array[1] grade: %d\n",
         nest_stu_p->strct_point_array[1]->grade);

  // out buf test
  memcpy(out_buf, stu_p, sizeof(student_t));
  printf("out buf: grade: %d\n", ((student_t *)out_buf)->grade);

  return 1;
}