#include "exchange.h"

namespace strategy {

double Exchange::Execute(const double base) const {
  return strategy_->execute(base);
}

Strategy* Exchange::SetStrategy(Strategy* strategy) {
  strategy_ = strategy;
  return strategy_;
}

}
