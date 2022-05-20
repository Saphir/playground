import ctypes

from addressbook_pb2 import AddressBook

def _demo():
    demo = ctypes.cdll.LoadLibrary('./libplayground.so').demo
    demo.restype = ctypes.py_object
    s = demo()
    addressbook = AddressBook()
    addressbook.ParseFromString(s)
    print(addressbook)

if __name__ == '__main__':
    _demo()
