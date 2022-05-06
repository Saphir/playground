#include "module_cpp.hpp"

#include <fstream>
#include <iostream>

namespace module_cpp {

bool ReadAddressBook(tutorial::AddressBook* address_book,
                     const std::string& filename) {
  // Read the existing address book.
  std::fstream input(filename, std::ios::in | std::ios::binary);
  if (!input) {
    std::cout << filename << ": File not found.  Creating a new file."
              << std::endl;
  } else if (!address_book->ParseFromIstream(&input)) {
    std::cerr << "Failed to parse address book." << std::endl;
    return false;
  }

  return true;
}

// This function fills in a Person message based on user input.
void PromptForAddress(tutorial::Person* person) {
  std::cout << "Enter person ID number: ";
  int id;
  std::cin >> id;
  person->set_id(id);
  std::cin.ignore(256, '\n');

  std::cout << "Enter name: ";
  getline(std::cin, *person->mutable_name());

  std::cout << "Enter email address (blank for none): ";
  std::string email;
  getline(std::cin, email);
  if (!email.empty()) {
    person->set_email(email);
  }

  while (true) {
    std::cout << "Enter a phone number (or leave blank to finish): ";
    std::string number;
    getline(std::cin, number);
    if (number.empty()) {
      break;
    }

    tutorial::Person::PhoneNumber* phone_number = person->add_phones();
    phone_number->set_number(number);

    std::cout << "Is this a mobile, home, or work phone? ";
    std::string type;
    getline(std::cin, type);
    if (type == "mobile") {
      phone_number->set_type(tutorial::Person::MOBILE);
    } else if (type == "home") {
      phone_number->set_type(tutorial::Person::HOME);
    } else if (type == "work") {
      phone_number->set_type(tutorial::Person::WORK);
    } else {
      std::cout << "Unknown phone type.  Using default." << std::endl;
    }
  }
}

bool WriteAddressBook(const tutorial::AddressBook& address_book,
                      const std::string& filename) {
  // Write the new address book back to disk.
  std::fstream output(filename,
                      std::ios::out | std::ios::trunc | std::ios::binary);
  if (!address_book.SerializeToOstream(&output)) {
    std::cerr << "Failed to write address book." << std::endl;
    return false;
  }

  return true;
}

}  // namespace module_cpp
