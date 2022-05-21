import ctypes

from addressbook_pb2 import AddressBook

def _demo():
    demo1 = ctypes.cdll.LoadLibrary('./libplayground.so').demo1
    demo1.argtypes = [ctypes.py_object, ctypes.py_object]
    demo1.restype = ctypes.py_object
    s = demo1(7, "Billy")
    print(type(s))
    addressbook = AddressBook()
    addressbook.ParseFromString(s)
    print(addressbook)

if __name__ == '__main__':
    _demo()
