#include <algorithm>
#include <boost/asio/ip/address.hpp>
#include <boost/system/detail/error_code.hpp>
#include <functional>
#include <stdexcept>
#include <any>
#include <cstddef>
#include <exception>
#include <bits/chrono.h>
#include <boost/mpl/assert.hpp>
#include <iostream>
#include <iterator>
#include <list>
#include <numeric>
#include <string>
#include <system_error>
#include <thread>
#include <vector>
#include <chrono>
#include "timer.hpp"
#include "Templetes.hpp"
#include <ctime>
#include <ratio>
#include <iomanip>
#include <cmath>
#include <limits>
#include <iostream>
#include <execution>

//BOOST_ASIO
#include <boost/asio.hpp>


using ULL = unsigned long long;
using CLL = const long long ;
using CLD = const long double;
namespace BOOST_ASIO
{
}
namespace TEMPLETE
{

  template <typename T> using pointer = T*;
  pointer<int> p  = new int;

  
  template<typename T,typename V,typename U>
  struct S
  {
    static void foo()
    {
      std::cout<<"General case "<<std::endl;
    }
  };
  
  template<typename V,typename U>
  struct S<int, V, U>
  {
     static void foo()
     {
       std::cout<<"T=int "<<std::endl;
     }
  };
template<typename U>
  struct S<int,double, U>
  {
     static void foo()
     {
       std::cout<<"T=int V=double "<<std::endl;
     }
  };

  void func6()
  {
    S<std::string,int, double>::foo();
    S<int,float,std::string>::foo();
    S<int ,double,std::string>::foo();
  } 

  

  namespace variadicTemplate
  {
    template <typename ... T>
    struct DataStructure{};

    template<typename T,typename ... Rest>
    struct DataStructure<T,Rest...>
    {
      DataStructure(const T& first,const Rest&... rest)
        :first(first),rest(rest...)
      {}


      T first;
      DataStructure<Rest...>rest;
    };
 
      void print(const DataStructure<>&)
      {}

      template<typename T,typename ...Rest>
      void print(const DataStructure<T,Rest...>& ds)
      {
        std::cout<<ds.first<<std::endl;
        print(ds.rest);
      }  
    void func1()
    {
      DataStructure<int,double,std::string>data(21,34.34,"sasha");
      print(data);
    }

  }
  template <typename T1,typename T2>
  struct MyPair
  {
    T1 first;
    T2 second;
    
   void show()
   {
     std::cout<<"first - "<<first<<std::endl<<"second - "<<second<<std::endl;
   } 

  };
  
  template <typename T1,typename T2>

  MyPair<T1,T2> make_MyPair (T1 t1,T2 t2)
  {
    return MyPair<T1,T2>{t1,t2};

  } 
  void func4()
  {
    auto val1 = MyPair<int,double>{5,3.44};
    auto val2 = make_MyPair(3,5.5454);
    val1.show();
    std::cout<<"val2 first - "<<val2.first<<"val2 second - "<<val2.second<<std::endl;


  }




  template <typename T>
    void print_sum(T a,T b)
    {
      std::cout<<(a+b)<<std::endl;
    }
  void func2()
  {

  }
  void func1()
  {
    Number<int>num;
    num.setNum(1);
    std::cout<<"My integer + 1 = "<<num.plus1()<<std::endl;
    Number<double>num1;
    num.setNum(1.435465766);
    std::cout<<"My double + 1 = "<<num1.plus1()<<std::endl;



  }
}
namespace macros 
{
  void t1()
  {
    std::cout<<__LINE__<<std::endl;
    std::cout<<__FILE__<<std::endl;
    std::cout<<__DATE__<<std::endl;
    std::cout<<__TIME__<<std::endl;
    std::cout<<__BASE_FILE__<<std::endl;
  }
}

namespace LAMBDA
{

  
  std::function<int(int,int)>gcd = [](int a,int b)
  {
    return b==0 ? a :gcd(b,a%b);
  };
  void func4()
  {
    int res = gcd(48,18);
    std::cout<<res<<std::endl;
  }
  struct isleesthat
  {
    isleesthat(int threshold):threshold(threshold)
     {}
    
      bool operator()(int value)const
      {
        return value>threshold;
      }
    
    private:
      int threshold;

  };
  void func3()
  {
    const int arr[] = {1,4,7,9,11,43,2,4};
    std::vector<int>vector(arr,arr+7);
    int numb = 10;
    std::vector<int>::iterator it = std::find_if(vector.begin(),vector.end(),[numb](int value)
    {
        return value>numb;
    });
    std::cout<<*it;
  
  }
  void func2()
  {
    auto funcL = [c=0]() mutable{++c;std::cout<<c;};
    funcL();
    int num = 5;

    auto timesFive = [num](int a){return a*num;};
    std::cout<<timesFive(2);


  }
  template <typename T>
    auto sort_cpp11 = [](const auto lhs,const auto rhs)
    {
      return lhs<rhs;
    };

 void func1()
 {
  std::vector<int>vector{1,6,3,8,4,9,34,6}; 
  std::sort(vector.begin(),vector.end(),sort_cpp11<int>);
  for(const auto& v:vector)
  {
    std::cout<<v<<" ";
  }
  std::cout<<std::endl;
 }
}
namespace EXEPTION
{

  
  class EXCEPTION :virtual public std::exception
  {
    public:
      const char* what()const noexcept override
      {
        return "my castom exception";
      }


  };
  void test_exeption2()
  {
    try 
    {
      throw EXCEPTION();
    }
    catch(const EXCEPTION& e)
    {
      std::cerr<<"Cought EXCEPTION : "<<e.what()<<std::endl;
    }
  }
  void test_exeption1()
  {
    try
    {
      throw std::runtime_error("an error ocuured");

    }
    catch(const std::runtime_error& e)
    {
      std::cerr<<"caught runtime error: "<<e.what()<<std::endl;
    }
    catch(const std::exception& e)
    {
      std::cerr<<"caught  error: "<<e.what()<<std::endl;
    }
  }

  void test_exeption()
  {
    std::string str("foo");
    try
    {
      str.reserve(2);
   
    }
    catch(const std::exception& e)
    {
      std::cout<<e.what();
    }

  }

}

void showv(std::vector<int>vector)
{
  std::cout<<"Vector :"<<std::endl;
  for(auto &vec : vector)
  {
    std::cout<<vec<<" ";
  }
  std::cout<<std::endl;
}

namespace SLA
{
  void test_sort()
  {
    //-list ,forvard_list

    std::vector<int>vector{5,2,4};
    showv(vector);
    
    std::sort(vector.begin(),vector.end());
    showv(vector);
    

    std::list<int>list{6,8,2};
    list.sort();

   

  }
  void test_count()
  {
    std::vector<int>vector{4,6,8,9,10,30,55,100,45,2,4,7,9,43,48};

    size_t count9 = count(vector.begin(),vector.end(),9);
    size_t count4 = count(vector.begin(),vector.end(),4);
    size_t count8 = count(vector.begin(),vector.end(),8);
    size_t count55 = count(vector.begin(),vector.end(),55);
    size_t count1 = count(vector.begin(),vector.end(),0);

    std::cout<<"there are - "<<count1<<" 1 s"<<std::endl;
    std::cout<<"there are - "<<count4<<" 4 s"<<std::endl;
    std::cout<<"there are - "<<count8<<" 8 s"<<std::endl;
    std::cout<<"there are - "<<count55<<" 55 s"<<std::endl;
    std::cout<<"there are - "<<count9<<" 9 s"<<std::endl;


    std::vector<int>::iterator itr4 = std::find(vector.begin(),vector.end(),4);

    size_t count_4 = count(itr4,vector.end(),*itr4);
    std::cout<<"count 4 - "<<count_4<<std::endl;

  }
  void test_nth_elem()
  {
    std::vector<int>vector{7,3,8,5,2};
    std::vector<int>::iterator b = vector.begin();
    std::vector<int>::iterator e = vector.end();
    std::vector<int>::iterator mid = b;

    std::advance(mid,vector.size()/2);
   
    std::nth_element(b,mid,e);
   std::cout<<"mediana - "<<*mid<<std::endl;
    
  }
  void test_find()
  {
    std::vector<int>vector{12,654,78,234,54,2345,98,34,87,12};

    std::vector<int>::iterator itr54;
    std::vector<int>::iterator itr78;
    std::vector<int>::iterator itr93;

    itr54 = std::find(vector.begin(),vector.end(),54);
    itr78 = std::find(vector.begin(),vector.end(),78);
    itr93 = std::find(vector.begin(),vector.end(),93);


    std::cout<<*itr54<<std::endl;
    std::cout<<*itr78<<std::endl;
    std::cout<<*itr93<<std::endl;

  }
  void test_accumulate()
  {
    std::vector<int>vector{1,2,3,4,5,6,7,8};
    int sum = std::accumulate(vector.begin(),vector.end(),0);
    std::cout<<"Sum of vector - "<<sum<<std::endl;

  }
  void test_for_each()
  {
    std::vector<int>vector{1,2,3,4,5,6,7,8,9};
    std::for_each(vector.begin(),vector.end(),[](int elem){std::cout<<elem<<" ";});
  }
  void test_next_permutation()
  {
    std::vector<int>vector{1,2,3,4};
    do 
    {
      for (int i = 0;i<vector.size(); ++i )
      {
        std::cout<<vector[i];           
      }
    std::cout<<std::endl;

    }while (std::next_permutation(vector.begin(),vector.end()));

  }

}
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
    std::cout<<(std::any_cast<std::string&>(object) = "ivan")<<std::endl;
  
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

