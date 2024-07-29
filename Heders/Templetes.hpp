#include <iostream>

template <typename T>
class Number
{
  private:
    T num;
  public:
    void setNum(T n);
    T plus1()const;
};
template<typename T>
void Number<T>::setNum(T n)
{
  num = n;
}
template<typename T>
T Number<T>::plus1()const
{
  return num +1;
}
