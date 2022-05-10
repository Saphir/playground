#ifndef TEST_H

typedef struct student {
  char cls;
  int grade;
  long array[3];
  int *point;
} student_t;

typedef struct nest_stu {
  char rank;
  student_t nest_stu;
  student_t strct_array[2];
  student_t *strct_point;
  student_t *strct_point_array[2];
} nest_stu_t;

typedef struct g_student {
  int g_grade;
} g_stu_t;

int test_c_func(char char_arg, int int_arg, float float_arg, char *string_arg,
                char *stu_buf, char *nest_stu_buf, char *out_buf);

#endif  // TEST_H
