#include <chrono>
#include <bits/chrono.h>
using namespace std::chrono;

class StopWatch
{
  private:
    time_point<steady_clock> time;
    bool isRunning = false;

  public:

    void Start();
    microseconds Stop();




};


