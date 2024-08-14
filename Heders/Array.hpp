#include <cstddef>
#include <iterator>
class Array
{
  private:
    int* arr;
    std::size_t size;

  public:
    Array(std::size_t size);
    Array(const Array& other);
    ~Array();

    Array operator=(const Array& other);
    int& operator[](std::size_t index);
    const int& operator[](std::size_t index)const;
    std::size_t Size()const{return size;};

};
