#include <any>
#include <exception>
#include <bits/chrono.h>
#include <boost/mpl/assert.hpp>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <system_error>
#include <thread>
#include <vector>
#include <chrono>
#include "timer.hpp"
#include <ctime>
#include <ratio>
#include <iomanip>
#include <cmath>
#include <limits>
#include <iostream>




using ULL = unsigned long long;
using CLL = const long long ;
using CLD = const long double;

namespace ANY 
{
  void test_any()
  {
  std::any object{std::string("Sasha")};
  if(object.has_value())
  {
    std::cout<<std::any_cast<std::string>(object)<<std::endl;
  }
  try
  {
    std::any_cast<int>(object); 
  } 
  catch (std::bad_any_cast&)
  {
    std::cout<<"bad any cast"<<std::endl;  
  }
  
  try
  {
    std::cout<<std::any_cast<std::string&>(object) = "ivan"<<std::endl;
  
  }
  catch(std::bad_any_cast&)
  {
    std::cout<<"bad any cast"<<std::endl;  
  }


  }
}
namespace ONLY_CHRONO
{

  std::tm CreateTmStruct(
      int year,
      int month,
      int day,
      int hour,
      int minutes,
      int seconds )
  {
    struct tm tm_ret = {0};
    tm_ret.tm_sec = seconds;
    tm_ret.tm_min = minutes;
    tm_ret.tm_hour = hour;
    tm_ret.tm_mday = day;
    tm_ret.tm_mon = month-1;
    tm_ret.tm_year = year - 1900;
    return tm_ret;

    
  }

  int get_days_of_year(int year)
  {
    using namespace std;
    using namespace std::chrono;

   typedef duration<int,ratio_multiply<hours::period,ratio<24>>::type> days;
   std::tm tm_start = CreateTmStruct(year, 1,1,0,0,0);
   auto tms = system_clock::from_time_t(std::mktime(&tm_start));

 std::tm tm_end = CreateTmStruct(year + 1, 1, 1, 0, 0, 0);
 auto tme = system_clock::from_time_t(std::mktime(&tm_end));

 auto diff_in_days = std::chrono::duration_cast<days>(tme - tms);

 return diff_in_days.count();     
  } 











  void Exempl1()
  {
    auto start = std::chrono::system_clock::now();
    {
      std::this_thread::sleep_for(std::chrono::seconds(2));
    }
    auto end = std::chrono::system_clock::now();
    auto elapsedTime = std::chrono::duration_cast<seconds>(end-start);
    std::cout<<"elapsedTime = "<<elapsedTime.count();


  }

}



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

