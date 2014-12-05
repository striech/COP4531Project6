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
  int charAt(fsu::Vector<Char> s, size_t pos);
  size_t logR; // 8 * sizeof(T)
  size_t R;    // 2^logR
  void privateSort( fsu::Vector< fsu::Vector<Char> > & str, fsu::Vector< fsu::Vector<Char> > & aux,
                    size_t lo, size_t hi, size_t d);
};

template <typename T>
template <class Predicate>
void MSD<T>::Sort(fsu::Vector< fsu::Vector<Char> > & msd_data, Predicate& predicate)
{
  (void)msd_data;
  fsu::Vector<fsu::Vector<Char> > aux( msd_data.Size());
  privateSort(msd_data, aux, 0, msd_data.Size()-1, 0);
  
}

template <typename T>
void MSD<T>::privateSort( fsu::Vector< fsu::Vector<Char> > & str, fsu::Vector< fsu::Vector<Char> > & aux,
                          size_t lo, size_t hi, size_t d){
  if(hi <= lo) return;
  fsu::Vector<size_t> Count;
 for(size_t j = 0; j <= R+2; j++) Count.PushBack(0); 
 for(size_t j = lo; j <= hi; j++){

    Count[charAt(str[j],d)+2]++;
 }
 for(size_t r = 0; r < R+1; r++)
    Count[r+1] += Count[r];
 for(size_t i = lo; i <= hi; i++)
    aux[Count[charAt(str[i],d)+1]++] = str[i];
 for(size_t i = lo; i <= hi; i++)
    str[i] = aux[i - lo];
 for(size_t r = 0; r < R; r++){
  if(lo + Count[r+1] < 1) continue;
  //std::cout << lo + Count[r] << " = lo " << lo + Count[r+1] -1 << " = hi" << d << std::endl;
  privateSort( str, aux, lo + Count[r] , lo + Count[r+1] - 1 , d+1);
 }
}

template <typename T>
int MSD<T>::charAt(fsu::Vector<Char> s, size_t pos){
  if(pos >= s.Size()) return -1;
  return s[pos];
}

#endif
