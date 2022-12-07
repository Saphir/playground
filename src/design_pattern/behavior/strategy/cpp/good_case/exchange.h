#pragma once

namespace strategy {

class Strategy {
  public:
    virtual ~Strategy() = default;
    virtual double execute(const double) const = 0;
};

class Exchange {
  public:
    double Execute(const double) const;
    Strategy* SetStrategy(Strategy* strategy);
    
    private:
    Strategy* strategy_{nullptr};
};

}