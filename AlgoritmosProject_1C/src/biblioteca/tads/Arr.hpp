#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../funciones/arrays.hpp"

using namespace std;

template<typename T>
struct Arr
{
};

template<typename T>
Arr<T> arr(int size)
{
   return {};
}

template<typename T>
Arr<T> arr()
{
   return {};
}

template<typename T>
int arrAdd(Arr<T>& a,T v)
{
   return 0;
}

template<typename T>
T* arrGet(Arr<T> a,int p)
{
   return NULL;
}

template<typename T>
void arrSet(Arr<T>& a,int p,T t)
{
}

template<typename T>
void arrInsert(Arr<T>& a,T v,int p)
{
}

template<typename T>
int arrSize(Arr<T> a)
{
   return 0;
}

template<typename T>
T arrRemove(Arr<T>& a,int p)
{
   T t;
   return t;
}

template<typename T>
void arrRemoveAll(Arr<T>& a)
{
}

template<typename T,typename K>
int arrFind(Arr<T>& a,K k, int cmpTK(T,K))
{
   return 0;
}

template<typename T>
int arrOrderedInsert(Arr<T>& a,T t,int cmpTT(T,T))
{
   return 0;
}

template<typename T>
void arrSort(Arr<T>& a,int cmpTT(T,T))
{
}

#endif
