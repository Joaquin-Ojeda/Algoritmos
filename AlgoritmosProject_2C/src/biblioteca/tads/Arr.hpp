#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template <typename T>
struct Arr
{
   T arr[500];
   int len;
   int cap;
};

template <typename T>
Arr<T> arr(int size)
{
   Arr<T> f;
   f.len = size;
   f.cap = size;
   return f;
}

template <typename T>
Arr<T> arr()
{
   Arr<T> f;
   f.len = 0;
   f.cap = 0;
   return f;
}

template <typename T>
int arrAdd(Arr<T>& a, T v)
{
   int f = add<T>(a.arr,a.len,v);

   return f;
}

template <typename T>
T* arrGet(Arr<T> a, int p)
{
   T* x = &a.arr[p];
   return x;
}

template <typename T>
void arrSet(Arr<T>& a, int p, T t)
{
   a.arr[p] = t;
}

template <typename T>
void arrInsert(Arr<T>& a, T v, int p)
{
   insert<T>(a.arr,a.len,v,p);
}

template <typename T>
int arrSize(Arr<T> a)
{
   int x = a.len;
   return x;
}

template <typename T>
T arrRemove(Arr<T>& a, int p)
{
   T t = remove<T>(a.arr,a.len,p);
   return t;
}

template <typename T>
void arrRemoveAll(Arr<T>& a)
{
   a.len = 0;
}

template <typename T, typename K>
int arrFind(Arr<T>& a, K k, int cmpTK(T, K))
{
   int x = find<T, K>(a.arr,a.len,k,cmpTK);
   return x;
}

template <typename T>
int arrOrderedInsert(Arr<T>& a, T t, int cmpTT(T, T))
{
   int x = orderedInsert<T>(a.arr,a.len,t,cmpTT);
   return x;
}

template <typename T>
void arrSort(Arr<T>& a, int cmpTT(T, T))
{
   sort<T>(a.arr,a.len,cmpTT);
}

#endif
