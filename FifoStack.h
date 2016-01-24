#ifndef RACECOMPUTER_FIFOSTACK_H
#define RACECOMPUTER_FIFOSTACK_H

template<typename valueType, int stackSize>
class FifoStack {
 public:
  void update (valueType value);
  valueType getAverage();
 private:
  int currentIndex = 0;
  valueType stack[stackSize];
};

#endif //RACECOMPUTER_FIFOSTACK_H
