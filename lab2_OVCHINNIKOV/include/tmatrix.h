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
      throw out_of_range("Vector size is invalid"); 
    pMem = new T[sz]();// {}; // У типа T должен быть констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s) // конструктор инициализатор
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v) // конструктор копирования
  {
      if (this == &v) throw("Meow");
      sz = v.sz;
      pMem = new T[sz];
      std::copy(v.pMem, v.pMem + sz, pMem);
  }
  TDynamicVector(TDynamicVector&& v) noexcept // для оператора перемещения 
  {
      pMem = nullptr;
      swap(*this, v);
  }
  ~TDynamicVector() // деструктор
  {
      delete[] pMem;
  }
  TDynamicVector& operator=(const TDynamicVector& v) // Копирующий оператор присваивания
  {
      if (this == &v) return *this; // проверка на самоприсваивание
      if (sz != v.sz) { // если размеры равны, то память перевыделять не нужно
          T* p = new T[v.sz];
          delete[] pMem;
          sz = v.sz;
          pMem = p;
      }
      std::copy(v.pMem, v.pMem + sz, pMem);
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      swap(*this, v);
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      if (ind < 0 || ind > sz) throw("Искл");
      return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
      if (ind < 0 || ind > sz) throw("Искл");
      return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if (ind < 0  || ind > sz) throw("Искл");
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if (ind < 0 || ind > sz) throw("Искл");
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz) return false;
      else {
          for (size_t i = 0; i < sz; i++) {
              if (pMem[i] != v.pMem[i]) return false;
          }
      }
      return true;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz) return true;
      else {
          for (size_t i = 0; i < sz; i++) {
              if (pMem[i] != v.pMem[i]) return true;
          }
      }
      return false;

  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] + val;
      }
      return tmp;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] - val;
      }
      return tmp;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] * val;
      }
      return tmp;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] + v.pMem[i];
      }
      return tmp;   
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      TDynamicVector tmp(sz);
      for (size_t i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] - v.pMem[i];
      }
      return tmp;
  }
  T operator*(const TDynamicVector& v) noexcept(noexcept(T()))
  {
      if (sz != v.sz) throw "not equal sizes";
      T k = 0;
      for (int i = 0; i < sz; i++) {
          k = k + pMem[i] * v.pMem[i];
      }
      return k;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : public TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s) // конструктор
  {
      if (sz > MAX_MATRIX_SIZE) throw("Meow");
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      return TDynamicVector<TDynamicVector<T>>::operator==(m);
  }

  // матрично-скалярные операции
  TDynamicVector<T> operator*(const T& val)
  {
      TDynamicMatrix tmp(sz);
      for (size_t i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] * val;
      }
      return tmp;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      TDynamicMatrix tmp(sz);
      for (size_t i = 0; i < sz; i++) {
          tmp[i] = pMem[i] * v;
      }
      return tmp;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      TDynamicMatrix tmp(sz);
      for (size_t i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] + m.pMem[i];
      }
      return tmp;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      TDynamicMatrix tmp(sz);
      for (size_t i = 0; i < sz; i++) {
          tmp.pMem[i] = pMem[i] - m.pMem[i];
      }
      return tmp;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      TDynamicMatrix tmp(sz);
      for (size_t i = 0; i < sz; i++)
          for(size_t j = 0; j<sz; j++)
              for (size_t k = 0; k < sz; k++) {
                  tmp.pMem[i][j] += pMem[i][k] * m.pMem[k][j];
              }
      return tmp;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++) {
          ostr << "\n";
          for (size_t j = 0; j < v.sz; j++)
              ostr << v.pMem[i][j] << " ";
      }
      return ostr;
  }
};

#endif
