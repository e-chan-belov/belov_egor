﻿// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size)
  {
    if (sz == 0 || sz > MAX_VECTOR_SIZE)
      throw out_of_range("Vector size should be greater than zero");
    pMem = new T[sz]();
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v)
  {
    sz = v.sz;
    pMem = new T[sz];
    std::copy(v.pMem, v.pMem + sz, pMem);
  }
  TDynamicVector(TDynamicVector&& v)
  {
    pMem = nullptr;
    swap(*this, v);
  }
  ~TDynamicVector()
  {
    delete[] pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v)
   {
    if (this != &v) {
        if (sz != v.sz) {
            T* p = new T[v.sz];
            delete[] pMem;
            sz = v.sz;
            pMem = p;
        }
        for (int i = 0; i < sz; i++) {
            pMem[i] = v.pMem[i];
        }
    }
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v)
  {
    swap(*this, v);
    return *this;
  }

  size_t size() const { return sz; }

  // индексация
  T& operator[](size_t ind)
  { 
    if (ind < 0 || ind >= sz) {
      throw -1;
    }
    return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
    if (ind < 0 || ind >= sz) {
      throw -1;
    }
    return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
    if (ind < 0 || ind >= sz) {
      throw -1;
    }
    return pMem[ind];
  }
  const T& at(size_t ind) const
  {
    if (ind < 0 || ind >= sz) {
      throw -1;
    }
    return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const
  {
    if(sz != v.sz) return false;
    for(size_t i = 0; i < sz; i++){
      if(pMem[i] != v.pMem[i]) return false;
    }
    return true;
  }
  bool operator!=(const TDynamicVector& v) const
  {
       if(sz != v.sz) return true;
    for(size_t i = 0; i < sz; i++){
      if(pMem[i] != v.pMem[i]) return true;
    }
    return false;
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
    TDynamicVector tmp(sz);
    for(size_t i = 0; i < sz; i++){
      tmp.pMem[i] = pMem[i] + val;
    }
    return tmp;
  }
  TDynamicVector operator-(T val)
  {
    TDynamicVector tmp(sz);
    for(size_t i = 0; i < sz; i++){
      tmp.pMem[i] = pMem[i] - val;
    }
    return tmp;
  }
  TDynamicVector operator*(T val)
  {
    TDynamicVector tmp(sz);
    for(size_t i = 0; i < sz; i++){
      tmp.pMem[i] = pMem[i] * val;
    }
    return tmp;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
    if(sz != v.sz){
      throw -1;
    }
    TDynamicVector tmp(sz);
    for(size_t i = 0; i < sz; i++){
      tmp.pMem[i] = pMem[i] + v.pMem[i];
    }
    return tmp;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
    if(sz != v.sz){
      throw -1;
    }
    TDynamicVector tmp(sz);
    for(size_t i = 0; i < sz; i++){
      tmp.pMem[i] = pMem[i] - v.pMem[i];
    }
    return tmp;
  }
  T operator*(const TDynamicVector& v) // noexcept(noexcept(T()))
  {
    if (sz != v.sz) {
      throw -1;
    }
    T tmp = T();
    for (size_t i = 0; i < sz; i++) {
      tmp += pMem[i] * v.pMem[i];
    }
    return tmp;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) 
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i];
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; 
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : public TDynamicVector<TDynamicVector<T> >
{
  using TDynamicVector<TDynamicVector<T> >::pMem;
  using TDynamicVector<TDynamicVector<T> >::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T> >(s)
  {
    if (s > MAX_MATRIX_SIZE) {
      throw -1;
    }
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T> >::operator[];

  // сравнение
  bool operator==(const TDynamicMatrix& m) const
  {
    return TDynamicVector<TDynamicVector<T> >::operator==(m);
  }

  // матрично-скалярные операции
  TDynamicVector<T> operator*(const T& val)
  {
    TDynamicMatrix tmp(sz);
    for(size_t i = 0; i < sz; i++){
      tmp.pMem[i] = pMem[i] * val;
    }
    return tmp;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
    if (sz != v.size()) {
      throw out_of_range("Sizes are not equal.");
    }
    TDynamicVector<T> tmp(sz);
    for(size_t i = 0; i < sz; i++){
      tmp[i] = pMem[i] * v;
    }
    return tmp;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
    TDynamicMatrix tmp(sz);
    for(size_t i = 0; i < sz; i++){
      tmp.pMem[i] = pMem[i] + m.pMem[i];
    }
    return tmp;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
    TDynamicMatrix tmp(sz);
    for(size_t i = 0; i < sz; i++){
      tmp.pMem[i] = pMem[i] - m.pMem[i];
    }
    return tmp;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
    TDynamicMatrix tmp(sz);
    for(size_t i = 0; i < sz; i++){
      for(size_t j = 0; j < sz; j++){
        for(size_t k = 0; k < sz; k++){
          tmp.pMem[i][j] += pMem[i][k] * m.pMem[k][j];
        }
      }
    }
    return tmp;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
    for(size_t i = 0; i < v.sz; i++){
      for(size_t j = 0; j < v.sz; j++){
        istr >> v.pMem[i][j];
      }
    }
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
    size_t j;
    for (size_t i = 0; i < v.sz; i++) {
      ostr << "[ ";
      for (j = 0; j < v.sz - 1; j++) {
        ostr << v.pMem[i][j] << ' ';
      }
      ostr << v.pMem[i][j+1] << " ]" << endl;
    }

    return ostr;
  }
};

#endif