#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include <string>

#include "addressbook.pb.h"

#ifdef __cplusplus
extern "C" {
#endif

static tutorial::AddressBook generate_address_book(const int64_t id,
                                                   const std::string &name) {
  tutorial::AddressBook address_book{};

  auto people = address_book.add_people();
  people->set_id(id);
  people->set_name(name);
  people->set_email("john@example.com");

  auto phone = people->add_phones();
  phone->set_number("555-4321");
  phone->set_type(tutorial::Person::MOBILE);
  phone = people->add_phones();
  phone->set_number("555-4322");
  phone->set_type(tutorial::Person::HOME);

  return address_book;
}

PyObject *demo1(PyObject *arg_id, PyObject *arg_name) {
  std::string serialized;
  const long id = PyLong_AsLong(arg_id);
  const std::string name = PyUnicode_AsUTF8(arg_name);
  generate_address_book(id, name).SerializeToString(&serialized);
  return PyBytes_FromStringAndSize(serialized.data(), serialized.size());
}

static PyObject *method_demo(PyObject *self, PyObject *args) {
  int i = 0;
  double d = 0.0;
  char *s = nullptr;

  /* Parse arguments */
  if (!PyArg_ParseTuple(args, "ids", &i, &d, &s)) {
    return nullptr;
  }

  return PyLong_FromLong(1);
}

#ifdef __cplusplus
}
#endif
