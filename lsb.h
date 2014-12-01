#include "stddef.h"
#include <iostream>
#include <algorithm>
#include <functional>

#ifndef _LSB_H
#define _LSB_H

template <typename T>
class LSB
{
public:
  typedef T Char;
  typedef Char* String;

  LSB(size_t width, size_t size) : logR(width), R(size)
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
void LSB<T>::Sort(String str, size_t length, Predicate& predicate)
{
  std::sort(&str[0], &str[length], std::ref(predicate));
}

#endif
