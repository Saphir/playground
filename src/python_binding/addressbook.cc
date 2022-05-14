#include <fstream>
#include <iostream>
#include <string>

#include "addressbook.pb.h"

namespace python_binding {

tutorial::AddressBook generate_addressbook() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;
  tutorial::AddressBook addressbook{};

  auto person = addressbook.add_people();
  person->set_id(1);
  person->set_name("John Doe");
  person->set_email("john_dow@example.com");

  auto phone_number = person->add_phones();
  phone_number->set_number("555-4321");
  phone_number->set_type(tutorial::Person::MOBILE);
  phone_number = person->add_phones();
  phone_number->set_number("555-4322");
  phone_number->set_type(tutorial::Person::HOME);

  return addressbook;
}

}  // namespace python_binding

extern "C" {
bool get_addressbook(const char* output_file) {
  auto addressbook = python_binding::generate_addressbook();
  std::fstream output(output_file,
                      std::ios::out | std::ios::trunc | std::ios::binary);
  return addressbook.SerializeToOstream(&output);
}
}
