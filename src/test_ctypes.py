#!/usr/bin/env python
# -*- coding: utf-8 -*-

import ctypes
from proto import addressbook_pb2


def test_c(load_cdll):
    char_type = ctypes.c_char(b"a")
    byte_type = ctypes.c_byte(1)
    string_type = ctypes.c_wchar_p("abc")
    int_type = ctypes.c_int(2)
    print("char_type:", char_type)
    print("byte_type:", byte_type)
    print("string_type:", string_type)
    print("int_type:", int_type)

    # 数组
    int_array = (ctypes.c_int * 3)(1, 2, 3)
    char_array = (ctypes.c_char * 3)(1, 2, 3)
    print("int_array:", int_array)
    print("int_array[0]:", int_array[0])
    print("char_array:", char_array)
    print("char_array.value:", char_array.value)

    # 指针
    int_obj = ctypes.c_int(3)
    int_p = ctypes.pointer(int_obj)
    # 使用contents方法访问指针
    print("int_p.contents:", int_p.contents)
    # 获取指针指向的值
    print("int_p[0]:", int_p[0])
    # 指针类型
    int_p = ctypes.POINTER(ctypes.c_int)
    # 实例化
    int_obj = ctypes.c_int(4)
    int_p_obj = int_p(int_obj)
    print("int_p_obj.contents:", int_p_obj.contents)
    print("int_p_obj[0]:", int_p_obj[0])
    # 创建空指针的方式
    null_ptr = ctypes.POINTER(ctypes.c_int)()
    if null_ptr:
        print("null_ptr not null:", null_ptr)
    else:
        print("null_ptr is null:", null_ptr)

    # 结构体类型
    # 学生信息如下
    stu_info = [("class", "A"),
                ("grade", 90),
                ("array", [1, 2, 3]),
                ("point", 4)]
    # 创建结构提类
    # typedef struct student {
    #   char cls;
    #   int grade;
    #   long array[3];
    #   int *point;
    # } student_t;
    class Student(ctypes.Structure):
        _fields_ = [
            ("cls", ctypes.c_char),
            ("grade", ctypes.c_int),
            ("array", ctypes.c_long * 3),
            ("point", ctypes.POINTER(ctypes.c_int))
        ]
        _pack_ = 4 # 对齐方式4字节 by default
        __str__ = lambda self: f"Student(cls={self.cls}, grade={self.grade}, array={[x for x in self.array]}, point={self.point[0]})"
    print("sizeof Student: ", ctypes.sizeof(Student))
    # 实例化
    student_info_value = [
        ctypes.c_char(b"A"),
        ctypes.c_int(90),
        (ctypes.c_long * 3)(1, 2, 3),
        ctypes.pointer(ctypes.c_int(4))
    ] 
    student_obj = Student(*student_info_value)
    print("student info:", student_obj)

    # 嵌套结构体
    # typedef struct nest_stu {
    #   char rank;
    #   student_t nest_stu;
    #   student_t strct_array[2];
    #   student_t *strct_point;
    #   student_t *strct_point_array[2];
    # } nest_stu_t;
    class NestStudent(ctypes.Structure):
        _fields_ = [
            ("rank", ctypes.c_char),
            ("nest_stu", Student)
        ]
        __str__ = lambda self: f"NestStudent(rank={self.rank}, nest_stu={self.nest_stu})"
    print("sizeof NestStudent: ", ctypes.sizeof(NestStudent))
    nest_student_info_value = [
        ctypes.c_char(b"A"),
        student_obj
    ]
    nest_student_obj = NestStudent(*nest_student_info_value)
    print("nest_student info:", nest_student_obj)

    # 创建结构体数组
    student_array = (Student * 2)(student_obj, student_obj)
    class NestStudent(ctypes.Structure):
        _fields_ = [
            ("rank", ctypes.c_char),
            ("nest_stu", Student),
            ("strct_array", Student * 2),
        ]
        __str__ = lambda self: \
            f"NestStudent(rank={self.rank}, "\
            f"nest_stu={self.nest_stu}), "\
            f"strct_array={[str(x) for x in self.strct_array]}"
    print("sizeof NestStudent: ", ctypes.sizeof(NestStudent))
    nest_student_info_value = [
        ctypes.c_char(b"A"),
        student_obj,
        (student_obj, student_obj)
    ]
    nest_student_obj = NestStudent(*nest_student_info_value)
    print("nest_student info:", nest_student_obj)

    # 创建结构体指针
    # 曾接结构体指针成员,注意使用类型初始化指针是POINTER()
    class NestStudent(ctypes.Structure):
        _fields_ = [
            ("rank", ctypes.c_char),
            ("nest_stu", Student),
            ("strct_array", Student * 2),
            ("strct_point", ctypes.POINTER(Student))
        ]
        __str__ = lambda self: \
            f"NestStudent(rank={self.rank}, "\
            f"nest_stu={self.nest_stu}), "\
            f"strct_array={[str(x) for x in self.strct_array]}, "\
            f"strct_point={self.strct_point.contents}"
    print("sizeof NestStudent: ", ctypes.sizeof(NestStudent))
    nest_student_info_value = [
        ctypes.c_char(b"A"),
        student_obj,
        (student_obj, student_obj),
        ctypes.pointer(student_obj)
    ]
    nest_student_obj = NestStudent(*nest_student_info_value)
    print("nest_student info:", nest_student_obj)

    # 创建结构体指针数组
    class NestStudent(ctypes.Structure):
        _fields_ = [
            ("rank", ctypes.c_char),
            ("nest_stu", Student),
            ("strct_array", Student * 2),
            ("strct_point", ctypes.POINTER(Student)),
            ("strct_point_array", ctypes.POINTER(Student) * 2)
        ]
        __str__ = lambda self: \
            f"NestStudent(rank={self.rank}, "\
            f"nest_stu={self.nest_stu}), "\
            f"strct_array={[str(x) for x in self.strct_array]}, "\
            f"strct_point={self.strct_point.contents}, "\
            f"strct_point_array={[str(x.contents) for x in self.strct_point_array]}"
    print("sizeof NestStudent: ", ctypes.sizeof(NestStudent))
    nest_student_info_value = [
        ctypes.c_char(b"A"),
        student_obj,
        (student_obj, student_obj),
        ctypes.pointer(student_obj),
        (ctypes.pointer(student_obj), ctypes.pointer(student_obj))
    ]
    nest_student_obj = NestStudent(*nest_student_info_value)
    print("nest_student info:", nest_student_obj)

    # 快速创建内存区域的方法
    p = ctypes.create_string_buffer(3)
    print(ctypes.sizeof(p), p.raw)
    p = ctypes.create_string_buffer(b"Hello")
    print(ctypes.sizeof(p), p.raw)
    p = ctypes.create_string_buffer(b"Hello", 10)
    print(ctypes.sizeof(p), p.raw)
    p.value = b"Hi"
    print(ctypes.sizeof(p), p.raw)

    # 调用动态链接库
    # 准备入参
    char_arg = ctypes.c_char(b"Z")
    int_arg = ctypes.c_int(13)
    float_arg = ctypes.c_float(3.14159)
    # 准备出参
    out_buf = ctypes.create_string_buffer(b"", ctypes.sizeof(Student))

    string_arg = ctypes.c_char_p(b"foo")
    load_cdll.test_c_func(char_arg, int_arg, float_arg, string_arg, ctypes.byref(student_obj), ctypes.byref(nest_student_obj), out_buf)
    print("out_buf:", ctypes.cast(out_buf, ctypes.POINTER(Student)).contents)

    # 调用C源码中的g_stu结构体
    so_symble = load_cdll.g_stu


def test_cpp(load_cdll):
    int_arg = ctypes.c_int(43)
    string_arg = ctypes.c_char_p(b"Test_Cpp")
    load_cdll._ZN8test_cpp13test_cpp_funcEi(int_arg)
    load_cdll._ZN8test_cpp13test_cpp_funcEPKc(string_arg)
    # load_cdll._ZN8test_cpp13test_cpp_funcERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE(string_arg)

def test_addressbook(addressbook_bin, load_cdll):
    addressbook = addressbook_pb2.AddressBook()
    addressbook_bin_ctypes = ctypes.c_char_p(addressbook_bin.encode('utf-8'))
    addressbook.ParseFromString(load_cdll.ReadAddressBook(addressbook_bin_ctypes))
    print(addressbook)

if __name__ == '__main__':
    load_cdll = ctypes.cdll.LoadLibrary("build/src/libtest.so")

    test_c(load_cdll)
    test_cpp(load_cdll)

