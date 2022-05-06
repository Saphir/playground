#include <unistd.h> /* read sleep NULL close */

#include <cstdio>   /* fopen fgets printf */
#include <cstdlib>  /* exit system malloc atoi rand */
#include <iostream> /* std::cout std::endl */
#include "module_cpp/module_cpp.hpp"
#include "proto/addressbook.pb.h"

extern "C" {
#include "module_c/module_c.h"
}

void foo() {
  int a = 7;
  student_t s1 = {0};
  s1.cls = 'A';
  s1.grade = 100;
  s1.point = &a;

  student_t s2 = {0};
  s2.cls = 'B';
  s2.grade = 99;
  s2.point = &a;

  nest_stu_t ns = {0};
  ns.rank = 'A';
  ns.nest_stu = s1;
  ns.strct_array[0] = s2;
  ns.strct_point = &s1;
  ns.strct_point_array[0] = &s1;
  ns.strct_point_array[1] = &s2;

  nest_stu_t out = {0};

  char str[] = "foo";
  test_c_func('a', 1, 2.3, str, (char *)&s1, (char *)&ns, (char *)&out);
}

void bar() { module_cpp::test_cpp_func(7); }

// Main function:  Reads the entire address book from a file,
//   adds one person based on user input, then writes it back out to the same
//   file.
int main(int argc, char* argv[]) {
  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  if (check_main_argc(argc, argv) != 0) {
    return -1;
  }

  GOOGLE_PROTOBUF_VERIFY_VERSION;

  tutorial::AddressBook address_book;

  if (!module_cpp::ReadAddressBook(&address_book, std::string(argv[1]))) {
    return -1;
  }

  // Add an address.
  module_cpp::PromptForAddress(address_book.add_people());

  if (!module_cpp::WriteAddressBook(address_book, argv[1])) {
    return -1;
  }

  // Optional:  Delete all global objects allocated by libprotobuf.
  google::protobuf::ShutdownProtobufLibrary();

  return 0;
}
