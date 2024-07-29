#include <cstdarg>
#include <iostream>


namespace VARIADIC_TEMPLATES
{
  void print(int size,...)
  {
    va_list arguments;
    va_start(arguments,size);
    for (int i =0 ;i<size; i++) 
    {
      int element = va_arg(arguments,int);
      std::cout<<element<<" ";
    
    }
    std::cout<<std::endl;
    va_end(arguments);

  }
  void test1()
  {
    print(5,35,22,68,69,77);
  }
}
