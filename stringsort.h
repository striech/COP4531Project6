#include "stddef.h"
#include <iostream>
#include <algorithm>
#include <functional>

#ifndef _STRINGSORT_H
#define _STRINGSORT_H

template <typename T>
class StringSorts
{
public:
  typedef T Char;
  typedef Char* String;

  StringSorts(size_t width, size_t size) : logR(width), R(size)
  {
  }

  template <class Predicate>
  void Sort_LSB(String str, size_t length, Predicate& predicate);

  template <class Predicate>
  void Sort_MSB(String str, size_t length, Predicate& predicate);

  template <class Predicate>
  void Sort_3WQS(String str, size_t length, Predicate& predicate);

private:
  size_t logR; // 8 * sizeof(T)
  size_t R;    // 2^logR
};

template <typename T>
template <class Predicate>
void StringSorts<T>::Sort_LSB(String str, size_t length, Predicate& predicate)
{
  std::sort(&str[0], &str[length], std::ref(predicate));
}

template <typename T>
template <class Predicate>
void StringSorts<T>::Sort_MSB(String str, size_t length, Predicate& predicate)
{
  std::sort(&str[0], &str[length], std::ref(predicate));
}

template <typename T>
template <class Predicate>
void StringSorts<T>::Sort_3WQS(String str, size_t length, Predicate& predicate)
{
  std::sort(&str[0], &str[length], std::ref(predicate));
}

#endif
