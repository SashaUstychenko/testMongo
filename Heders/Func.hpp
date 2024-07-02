#include <iostream>
#include <iterator>
#include <numeric>
#include <thread>
#include <vector>
#include <chrono>
#include "timer.hpp"

using ULL = unsigned long long;
using CLL = const long long ;

namespace THREAD_CHRONO 
{

  ULL Sum(ULL start,ULL end)
  {
    ULL sum = 0;
    for(ULL number = start;number<=end;number++)
    {
      sum +=number;
    }
    return sum;
  }

  void Exemple1MultiThreading()
  {
    ULL RANGE_BEGIN = 0ULL;
    ULL RANGE_END   = 100'000'000ULL;

    StopWatch st1;
    st1.Start();

    const unsigned int THREADS_COUNT = std::thread::hardware_concurrency();
    std::vector<std::thread>threads(THREADS_COUNT);
    std::vector<ULL>subSumResults(threads.size());
    CLL RANGE__SIZE = RANGE_END - RANGE_BEGIN;
    CLL CHUNK_SIZE  = RANGE__SIZE / threads.size();

    for(int i = 0;i<threads.size();++i)
    {
      ULL chunk_start = RANGE_BEGIN+i*CHUNK_SIZE;
      ULL chunk_end   = (i!= threads.size())?chunk_start+CHUNK_SIZE:RANGE_END;

      threads[i] = std::thread(
          [&subSumResults,i,chunk_start,chunk_end]()
          {
            subSumResults[i] = Sum(chunk_start,chunk_end);
          }
      );
    }

     for(std::thread& thread : threads)
     {
       thread.join();
     }
     ULL sum = std::accumulate(std::begin(subSumResults),
                               std::end(subSumResults),
                               0ULL);
     auto elapsedTime = st1.Stop();
     std::cout<<"Multi-threading sum : "<<sum<<std::endl;
     std::cout<<"Multi-threading elapsed time : "<<elapsedTime.count()<<std::endl;

    }





  

 // void Exemple1NonMultiThreading()
 // {
 //   ULL RANGE_BEGIN = 0ULL;
 //   ULL RANGE_END   = 100'000'000ULL;
 //   //non multithreading
 //   StopWatch st1;
 //   st1.Start();
//
  //  ULL sum = Sum(RANGE_BEGIN,RANGE_END);
  //  auto elapsedTime = st1.Stop();
   // std::cout<<"Singe-threaded sum : "<<sum<<std::endl;
   // std::cout<<"Singe-threaded elapsed Time : "<<elapsedTime.count()<<std::endl;


  //}


  

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
