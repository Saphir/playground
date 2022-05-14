from build import addressbook_pb2
import sys
import ctypes

def main():
    cxx_lib_path = "./build/libpython_binding.so"
    load_lib = ctypes.cdll.LoadLibrary(cxx_lib_path)

    import tempfile
    with tempfile.NamedTemporaryFile() as tmp:
        get_addressbook = load_lib.get_addressbook
        get_addressbook.argtypes = [ctypes.c_char_p]
        get_addressbook.restype = ctypes.c_bool
        res = load_lib.get_addressbook(tmp.name.encode('utf-8'))
        if res:
            addressbook = addressbook_pb2.AddressBook()
            addressbook.ParseFromString(tmp.read())
            print(addressbook)
        else:
            print("Failed to get addressbook")


if __name__ == '__main__':
    main()
    sys.exit(0)
