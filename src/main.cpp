#include <fstream>
#include <iostream>
#include <string>

#include "module_cpp/module_cpp.hpp"
#include "proto/addressbook.pb.h"

extern "C" {
#include "module_c/module_c.h"
}

// Main function:  Reads the entire address book from a file,
//   adds one person based on user input, then writes it back out to the same
//   file.
int main(int argc, char* argv[]) {
  if (check_main_argc(argc, argv) != 0) {
    return -1;
  }

  // Verify that the version of the library that we linked against is
  // compatible with the version of the headers we compiled against.
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  tutorial::AddressBook address_book;

  if (!module_cpp::ReadAddressBook(&address_book, argv[1])) {
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
