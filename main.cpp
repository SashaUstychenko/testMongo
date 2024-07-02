#include <bits/chrono.h>
#include <ctime>
#include <iostream>
#include <string>
#include <iterator>
#include <thread>

#include "bcrypt/BCrypt.hpp"

#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>
#include <mongocxx/uri.hpp>

#include <bsoncxx/json.hpp>
#include <bsoncxx/builder/stream/document.hpp>

#include <boost/filesystem.hpp>
#include <boost/asio.hpp>
#include <chrono>
#include <vector>

#include "Heders/timer.hpp"

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



}

int main() 
{
  ThreadExemple();

  auto wakeTime = std::chrono::system_clock::now()+std::chrono::seconds(8);
  std::this_thread::sleep_until(wakeTime);

  std::cout<<"end"<<std::endl;

}


