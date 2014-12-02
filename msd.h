#include "stddef.h"
#include <iostream>
#include <algorithm>
#include <functional>

#ifndef _MSB_H
#define _MSB_H

template <typename T>
class MSB
{
public:
  typedef T Char;
  typedef Char* String;

  MSB(size_t width, size_t size) : logR(width), R(size)
  {
  }

  template <class Predicate>
  void Sort(String str, size_t length, Predicate& predicate);

private:
  size_t logR; // 8 * sizeof(T)
  size_t R;    // 2^logR
};

template <typename T>
template <class Predicate>
void MSB<T>::Sort(String str, size_t length, Predicate& predicate)
{
  std::sort(&str[0], &str[length], std::ref(predicate));
}

#endif
