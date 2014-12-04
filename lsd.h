#include "stddef.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include "vector.h"

#ifndef _LSD_H
#define _LSD_H

template <typename T>
class LSD
{
public:
  typedef T Char;

  LSD(size_t width, size_t size) : logR(width), R(size)
  {
  }

  template <class Predicate>
  void Sort(fsu::Vector< fsu::Vector<Char> > & lsd_data, Predicate& predicate);

private:
  size_t logR; // 8 * sizeof(T)
  size_t R;    // 2^logR
};

template <typename T>
template <class Predicate>
void LSD<T>::Sort(fsu::Vector< fsu::Vector<Char> > & lsd_data, Predicate& predicate)
{
  (void)lsd_data;
  (void)predicate;
}

#endif
