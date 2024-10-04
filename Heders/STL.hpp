#include <algorithm>
#include <cstddef>
#include <cstring>
#include <iterator>
#include <memory>
#include <iostream>
#include <regex>
#include <vector>

namespace SHARED_PTR
{
  class Person
  {
    private:
      int age = 0;
      char name[30] = "NoNAme";
    public:
      Person()
      {
        std::cout<<"Default Constuctor"<<std::endl;
      }
      Person(int age,const char* name)
        :age(age)
        {
          strcpy(this->name,name);

        std::cout<<"Constuctor age,name"<<std::endl;
        }
      ~Person()
      {
        std::cout<<"Destuctor"<<std::endl;
      }
      void ShowInfo()const
      {
        std::cout<<" age - "<<age<<" name - "<<name<<std::endl; 
      }
      void someMethod()
      {
        std::cout<<"Hello from Person"<<std::endl;
      }
      void showAllOfInfo()const
      {
        std::cout<<"Age "<<age<<" Name - "<<name<<std::endl;
      }

  };

    
  void Showw(std::vector<std::shared_ptr<Person>>&pers)
  {
    for (const auto &i:pers)
    {
      i->showAllOfInfo();
    
    } 
    
  }
  void make()
  {
    std::shared_ptr<Person>ptr {std::make_unique<Person>()};
    std::shared_ptr<Person>ptr1 {std::make_unique<Person>(22,"sass")};
    std::shared_ptr<Person>ptr2 {std::make_unique<Person>(54,"saddss")};
    std::shared_ptr<Person>ptr3 {std::make_unique<Person>(32,"ddsass")};
    std::shared_ptr<Person>ptr4 {std::make_unique<Person>(52,"bss")};
    std::vector<std::shared_ptr<Person>>persons;
    persons.push_back(ptr1);
    persons.push_back(ptr2);
    persons.push_back(ptr3);
    persons.push_back(ptr4);
    Showw(persons);


  }
  void methods()
  {
    std::shared_ptr<Person>p1(new Person{20,"Sasha"});
    p1->ShowInfo();
    p1.reset(new Person{12,"ivan"});
    p1->ShowInfo();
  }
  void test1()
  {



    {
    std::shared_ptr<Person>ptr1(new Person{});
    }
    {
    std::shared_ptr<Person>ptr2(new Person{15,"Sasha"});
    }
  }
}
namespace UNIQUE_PTR 
{
  class MyClass
  {
    public:
      MyClass()
      {
        std::cout<<"constructor of myClass"<<std::endl;
      }

      void Method()const
      {
        std::cout<<"hello from vunc of MyClass"<<std::endl;
      }
      
      ~MyClass()
      {
        std::cout<<"destructor of myClass"<<std::endl;

      }

  };
  namespace HAW_USE 
  {
    void func1()
    {
      std::unique_ptr<MyClass> ptr {new MyClass{}};
      //overload operators <-|
      ptr->Method();
      (*ptr).Method();
      //overload operator to bool
      if(ptr)
        std::cout<<"our pointer points to our object"<<std::endl;
      ptr.get()->Method();

      std::unique_ptr<int>ptr1 {new int{10}};
      ptr1.reset(new int{30});

      //pointer to array
      std::unique_ptr<int[]>pArr {new int[10]};
      for(size_t i = 0 ;i<10;++i)
      {
        pArr[i] = 10-i;
        std::cout<<pArr[i]<<" ";
      }

    }  
    
  }
  namespace CONSTRUCTORS 
  {
    class MYDeleterC
    {
      public:
        void operator()(int* ptr)
        {
          std::cout<<"operator from class MYDeleter"<<std::endl;
          delete ptr;

        }
    };
    void MYDeleter(int* ptr)
    {
      std::cout<<"func MYDeleter"<<std::endl;
      delete ptr;
    }

    void t_func()
    {
      std::unique_ptr<int> ptr;
      std::unique_ptr<int> ptr1{new int{5}};
      std::cout<<"start\n";
      {
        std::unique_ptr<int , void(*)(int*)> ptr {new int{5},MYDeleter};
      }
      {
        std::unique_ptr<int,MYDeleterC> ptr {new int{5},MYDeleterC()};
      }
      {
        std::unique_ptr<int> ptr1 {new int};
        std::unique_ptr<int>ptr2 {std::move(ptr1)};
      }
      std::cout<<"end\n";
    }
  }

}


namespace VECTOR 
{


}
