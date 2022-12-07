#pragma once

#include "exchange.h"

namespace strategy {
class StrategyDoller2Rmb : public Strategy {
  public:
    double execute(const double) const override;
};

class StrategyDoller2Yen : public Strategy {
  public:
    double execute(const double) const override;
};
}