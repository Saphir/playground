#pragma once

#include <string>

#include "proto/addressbook.pb.h"

namespace module_cpp {

// _ZN10module_cpp15ReadAddressBookEPN8tutorial11AddressBookERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
bool ReadAddressBook(tutorial::AddressBook* address_book,
                     const std::string& filename);
// _ZN10module_cpp15ReadAddressBookERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE

bool WriteAddressBook(const tutorial::AddressBook& address_book,
                      const std::string& filename);

void PromptForAddress(tutorial::Person* person);

/*
_ZN8test_cpp13test_cpp_funcEi
_ZN8test_cpp13test_cpp_funcEPKc
_ZN8test_cpp13test_cpp_funcERKNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
*/

void test_cpp_func(const int);
void test_cpp_func(const std::string&);
void test_cpp_func(const char*);

}  // namespace module_cpp

extern "C" {
const char* ReadAddressBook(const char* filename);
}
