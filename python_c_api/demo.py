#!/usr/bin/env python
# -*- coding: utf-8 -*-

import demo_ext

def demo():
    demo_char = b'c'
    demo_int = 1
    demo_s = "demo string"
    demo_bytes = b'\x00\x01\x02\x03\x04\x05\x06\x07\x08\x09\x0a\x0b\x0c\x0d\x0e\x0f'

    demo_ext.demo_c_func(demo_char, demo_int, demo_s, demo_bytes)

if __name__ == '__main__':
    demo()
