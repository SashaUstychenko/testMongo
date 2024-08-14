#include <iostream>
#include <mutex>


namespace TASKS2
{
  class LazySingleton
  {
    private:
      LazySingleton() { }
      static LazySingleton* instance;
    public:
      static LazySingleton* getInstance()
      {
        if (instance==nullptr)
        {
          instance = new LazySingleton();        
        }
        return instance;
      }
      void SomeFunc()
      {
        std::cout<<"<<---SASHA--->>"<<std::endl;
      }


  };

  LazySingleton* LazySingleton::instance = nullptr;
}
namespace TASKS1
{
  class Singleton
  {
    private:
      Singleton() { }
      Singleton(const Singleton& other) = delete;
      Singleton& operator=(const Singleton& other) = delete;
    public:
      static Singleton& getInstance()
      {
        static Singleton instance;
        return instance;
      }
      void SomeFunc()
      {
        std::cout<<"<<---SASHA--->>"<<std::endl;
      }
  };
}































namespace SINGLETON_LESONS1
{
  class Singleton
  { private:

      Singleton() 
      {
        std::cout<<"constructor"<<std::endl;
      }
      ~Singleton()
      {
        std::cout<<"constructor"<<std::endl;
      }
      Singleton(const Singleton& other) = delete;
      Singleton& operator=(const Singleton& other)= delete;


    public:
      // статичний метод для отримання єдиного екземпляра
      static Singleton& getInstance()
      {
        static Singleton instance;//Єдиний екземпляр створується тут
        return instance;        
      }
      void ShowMessage()
      {
        std::cout<<"Hello from singleton"<<std::endl;
      }

   };
}
namespace SINGLETON_LESONS2
{
  class TredSafeSingleton
  {
    private:
      TredSafeSingleton() { }
      TredSafeSingleton (const TredSafeSingleton& other) = delete;
      TredSafeSingleton& operator=(const TredSafeSingleton& other) = delete;

      static TredSafeSingleton* instance;
      static std::mutex mutex_;

    public:
      static TredSafeSingleton& getInstance()
      {
        std::lock_guard<std::mutex>lock(mutex_);
        if(instance == nullptr)
        {
          instance = new TredSafeSingleton();
        }
        return *instance;
      }
       void ShowMessage()
      {
 
        std::cout<<"Hello from singleton"<<std::endl;
      }

  };

  TredSafeSingleton* TredSafeSingleton::instance = nullptr;
  std::mutex TredSafeSingleton::mutex_;
}
namespace SINGLETON_LESONS3 
{
  class ConfigurableSingleton
  {
    private:
      int value;

      ConfigurableSingleton(int value)
        :value(value)
      { }

      ConfigurableSingleton(const ConfigurableSingleton& other) = delete;
      ConfigurableSingleton& operator=(const ConfigurableSingleton& other) = delete;
    public:
      static ConfigurableSingleton& getInstance(int value =0)
      {
        static ConfigurableSingleton instance(value);
        return instance;
      }
      void ShowValue()const
      {
        std::cout<<"Value - "<<value<<std::endl;
      }

  };
}
