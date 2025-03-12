#include "../inc/clock.h"

void Clock::setSize(const int& size_)
{
  size = size_;
}

void Clock::setTime(const int& time_)
{
  time = time_;
}

int Clock::getNextTick()
{
  if (time >= size) { time -= size; }
  return time++;
}
