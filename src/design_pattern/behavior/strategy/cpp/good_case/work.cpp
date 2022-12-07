#include "work.h"

#include <cstdio>

#include "exchange.h"
#include "strategies.h"

namespace strategy {

void Work() {
  double doller{100};
  Exchange ex{};

  StrategyDoller2Rmb s1{};
  ex.SetStrategy(&s1);

  double result{ex.Execute(doller)};
  printf("%f doller to rmb is %f\n", doller, result);

  StrategyDoller2Yen s2{};
  ex.SetStrategy(&s2);

  result = ex.Execute(doller);
  printf("%f doller to yen is %f\n", doller, result);
}

}
