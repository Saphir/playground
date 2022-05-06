#pragma once

#include <string>

#include "proto/addressbook.pb.h"

namespace module_cpp {

bool ReadAddressBook(tutorial::AddressBook* address_book,
                     const std::string& filename);

bool WriteAddressBook(const tutorial::AddressBook& address_book,
                      const std::string& filename);

void PromptForAddress(tutorial::Person* person);

}  // namespace module_cpp
