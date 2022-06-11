#!/usr/bin/env python
# -*- coding: utf-8 -*-

import demo_ext

class DemoObject(object):
    def __init__(self):
        self.demo_char = b'c'
        self.demo_int = 1
        self.demo_s = "demo string"
        self.demo_bytes = b'\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f'

    def __str__(self):
        return f"DemoObject(demo_char={self.demo_char}, demo_int={self.demo_int}, demo_s={self.demo_s}, demo_bytes={self.demo_bytes})"

def demo():
    demo_obj = DemoObject()
    print("[PY]", demo_obj)

    demo_ext.demo_c_func(
        demo_obj.demo_char,
        demo_obj.demo_int,
        demo_obj.demo_s,
        data=demo_obj.demo_bytes,
        obj=demo_obj)

    b = getattr(demo_obj, "demo_bytes")
    print("[PY]", b)

if __name__ == '__main__':
    demo()

