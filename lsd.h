#include "stddef.h"
#include <iostream>
#include <algorithm>
#include <functional>

#ifndef _LSD_H
#define _LSD_H

template <typename T>
class LSD
{
public:
  typedef T Char;
  typedef Char* String;

  LSD(size_t width, size_t size) : logR(width), R(size)
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
void LSD<T>::Sort(String str, size_t length, Predicate& predicate)
{
  std::sort(&str[0], &str[length], std::ref(predicate));
}

#endif
