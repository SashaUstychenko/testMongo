#include "Heders/timer.hpp"
#include <chrono>

void StopWatch::Start()
{
  time = steady_clock::now();
  isRunning = true;
}
microseconds StopWatch::Stop()
{
  if (isRunning)
  {
    isRunning = false;
    return duration_cast<microseconds>(steady_clock::now()-time);  
  }
  else 
  {
    return duration_cast<microseconds>(time.time_since_epoch());  
  }
}
