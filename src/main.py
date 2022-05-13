#!/usr/bin/env python
# -*- coding: utf-8 -*-

import ctypes
import sys
import tempfile
from test_ctypes import test_addressbook

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print(f"Usage:  {sys.argv[0]} ADDRESS_BOOK_FILE\n")
        sys.exit(-1)


    with tempfile.NamedTemporaryFile(suffix='.proto.bin', prefix='CheckerFusionLaneList', delete=True) as f:
        print(f"f.name: {f.name}")

    sys.exit(0)

    load_lib = ctypes.cdll.LoadLibrary("./build/src/libplayground.so")
    print(load_lib)
    test_addressbook(sys.argv[1], load_lib)
