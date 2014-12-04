#include "stddef.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include "vector.h"

#ifndef _MSD_H
#define _MSD_H

template <typename T>
class MSD
{
public:
  typedef T Char;

  MSD(size_t width, size_t size) : logR(width), R(size)
  {
  }

  template <class Predicate>
  void Sort(fsu::Vector< fsu::Vector<Char> > & msd_data, Predicate& predicate);

private:
  size_t logR; // 8 * sizeof(T)
  size_t R;    // 2^logR
};

template <typename T>
template <class Predicate>
void MSD<T>::Sort(fsu::Vector< fsu::Vector<Char> > & msd_data, Predicate& predicate)
{
  (void)msd_data;
  (void)predicate;
}

#endif
