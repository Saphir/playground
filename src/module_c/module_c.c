#include "module_c.h"

#include <stdio.h>

int check_main_argc(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage:  %s ADDRESS_BOOK_FILE\n", argv[0]);
    return -1;
  }
  return 0;
}