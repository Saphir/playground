#include "strategies.h"

namespace strategy {
double StrategyDoller2Rmb::execute(const double doller) const { return doller * 6.98; }
double StrategyDoller2Yen::execute(const double doller) const { return doller * 137.36; }
}