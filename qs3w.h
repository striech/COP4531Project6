#include "stddef.h"
#include <iostream>
#include <algorithm>
#include <functional>
#include "vector.h"

#ifndef _QS3W_H
#define _QS3W_H

template <typename T>
class QS3W
{
public:
  typedef T Char;

  QS3W(size_t width, size_t size) : logR(width), R(size)
  {
  }

  template <class Predicate>
  void Sort(fsu::Vector< fsu::Vector<Char> > & qs3w_data, Predicate& predicate);

private:
  size_t logR; // 8 * sizeof(T)
  size_t R;    // 2^logR
};

template <typename T>
template <class Predicate>
void QS3W<T>::Sort(fsu::Vector< fsu::Vector<Char> > & qs3w_data, Predicate& predicate)
{
  (void)qs3w_data;
  (void)predicate;
}

#endif
