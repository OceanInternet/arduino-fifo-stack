#include "FifoStack.h"

template<typename valueType, int stackSize>
void FifoStack<valueType, stackSize>::update (valueType value)
{

  this->stack[this->currentIndex] = value;

  this->currentIndex++;

  if (this->currentIndex == stackSize)
    {

      this->currentIndex = 0;
    }
}

template<typename valueType, int stackSize>
valueType FifoStack<valueType, stackSize>::getAverage ()
{

  valueType total;
  valueType average;
  valueType min;
  valueType max;

  int size = (sizeof this->stack / sizeof this->stack[0]);

  for (int i = 0; i < size; i++)
    {

      valueType tmpVal = this->stack[i];

      if (min > tmpVal)
        {
          min = tmpVal;
        }
      if (max < tmpVal)
        {
          max = tmpVal;
        }

      total += tmpVal;
    }

  if (size == stackSize)
    {

      total -= min;
      total -= max;

      average = total / (size - 2);
    }
  else
    {
      average = total / size;
    }

  return average;
}