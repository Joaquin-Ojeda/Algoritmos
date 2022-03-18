
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Arr.hpp"

using namespace std;

template<typename K,typename T>
struct Map
{
};

template<typename K,typename T>
Map<K,T> map()
{
   return {};
}

template<typename K,typename T>
T* mapGet(Map<K,T>& m,K k)
{
   return NULL;
}

template<typename K,typename T>
T* mapPut(Map<K,T>& m,K k,T v)
{
   return NULL;
}

template<typename K,typename T>
bool mapContains(Map<K,T>& m,K k)
{
   return false;
}

template<typename K,typename T>
T mapRemove(Map<K,T>& m,K k)
{
   T t;
   return t;
}

template<typename K,typename T>
void mapRemoveAll(Map<K,T>& m)
{
}

template<typename K,typename T>
int mapSize(Map<K,T> m)
{
   return arrSize(m.keys);
}

template<typename K,typename T> bool mapHasNext(Map<K,T>& m)
{
   return m.curr<arrSize(m.keys);
}

template<typename K,typename T> K mapNextKey(Map<K,T>& m)
{
   return NULL;
}

template<typename K,typename T> T* mapNextValue(Map<K,T>& m)
{
   return NULL;
}


template<typename K,typename T> void mapReset(Map<K,T>& m)
{
}

template<typename K,typename T> void mapSortByKeys(Map<K,T>& m,int cmpKK(K,K))
{
}

template<typename K,typename T> void mapSortByValues(Map<K,T>& m,int cmpTT(T,T))
{
}

#endif
