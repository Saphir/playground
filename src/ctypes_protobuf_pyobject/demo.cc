#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <string>

#include "addressbook.pb.h"

#ifdef __cplusplus
extern "C" {
#endif

PyObject *demo() {
  tutorial::AddressBook address_book;

  auto people = address_book.add_people();
  people->set_id(1);
  people->set_name("John Doe");
  people->set_email("john@example.com");

  auto phone = people->add_phones();
  phone->set_number("555-4321");
  phone->set_type(tutorial::Person::MOBILE);
  phone = people->add_phones();
  phone->set_number("555-4322");
  phone->set_type(tutorial::Person::HOME);

  std::string serialized;
  address_book.SerializeToString(&serialized);
  return PyBytes_FromStringAndSize(serialized.data(), serialized.size());
}

#ifdef __cplusplus
}
#endif
