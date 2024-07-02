#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

//#include "timer.hpp"

namespace THREAD_CHRONO {


  void ShowMessage(int i)
  {
     std::cout<<"Thread - "<<i<<"isRunning\n";
  }
  void ThreadExemple()
  {
     const auto THEARDS_COUNT = std::thread::hardware_concurrency();
    std::vector<std::thread>threads(THEARDS_COUNT);
    for(int thread_index = 0;thread_index<THEARDS_COUNT;thread_index++)
    {
      threads[thread_index] = std::thread(ShowMessage,thread_index);
    }

    for(std::thread& thread:threads)
    {
       thread.join();
    }

    {

      auto wakeTime = std::chrono::system_clock::now()+std::chrono::seconds(8);
      std::this_thread::sleep_until(wakeTime);
  
      std::cout<<"end"<<std::endl;
    }

  }

}
