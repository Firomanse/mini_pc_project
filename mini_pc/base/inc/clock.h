#ifndef CLOCK_H
#define CLOCK_H

class Clock
{
public:
  static void setSize(const int&);
  static void setTime(const int&);
  static int getNextTick();

private:
  inline static int time = 0;
  inline static int size = 0;
};

#endif //CLOCK_H
