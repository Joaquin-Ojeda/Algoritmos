#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Arr.hpp"

using namespace std;

template <typename K, typename T>
struct Map
{
   Arr<K> key;
   Arr<T> value;
   int pos = 0;
};

template <typename K, typename T>
Map<K, T> map()
{
   Map<K, T> x;
   x.key = arr<K>();
   x.value = arr<T>();
   return x;
}

template <typename K, typename T>
T* mapGet(Map<K, T>& m, K k)
{
   T* p = NULL;
   for( int i = 0; i<m.key.len; i++ )
   {
      if( m.key.arr[i]==k )
      {
         p = &m.value.arr[i];
      }
   }

   return p;
}

template <typename K, typename T>
T* mapPut(Map<K, T>& m, K k, T v)
{
   T* p = mapGet<K, T>(m,k);
   if( p==NULL )
   {
      arrAdd<K>(m.key,k);
      arrAdd<T>(m.value,v);
   }
   else
   {
      *p = v;
   }

   return p;
}

template <typename K, typename T>
bool mapContains(Map<K, T>& m, K k)
{
   bool f = false;
   if( mapGet<K, T>(m,k)!=NULL )
   {
      f = true;
   }
   return f;
}

template <typename K, typename T>
T mapRemove(Map<K, T>& m, K k)
{
   T t;
   for( int i = 0; i<m.key.len; i++ )
   {
      if( m.key.arr[i]==k )
      {
         arrRemove<K>(m.key,i);
         t = arrRemove<T>(m.value,i);
      }
   }
   return t;
}

template <typename K, typename T>
void mapRemoveAll(Map<K, T>& m)
{
   m.key.len = 0;
   m.value.len = 0;
   m.pos = 0;
}

template <typename K, typename T>
int mapSize(Map<K, T> m)
{

   return arrSize(m.key);
}

template <typename K, typename T>
bool mapHasNext(Map<K, T>& m)
{

   return m.pos<m.key.len;
}

template <typename K, typename T>
K mapNextKey(Map<K, T>& m)
{
   K f = *arrGet<K>(m.key,m.pos);
   m.pos++;
   return f;
}

template <typename K, typename T>
T* mapNextValue(Map<K, T>& m)
{
   T* f = arrGet<T>(m.value,m.pos);
   m.pos++;
   return f;
}

template <typename K, typename T>
void mapReset(Map<K, T>& m)
{
   m.pos = 0;
}

template <typename K, typename T>
void mapSortByKeys(Map<K, T>& m, int cmpKK(K, K))
{
   Map<K, T> a = map<K, T>();
   K x,y;
   int z = 1;
   while( mapHasNext<K, T>(m) )
   {
      x = m.key.arr[0];
      y = m.key.arr[1];
      while( z<m.key.len )
      {
         if( cmpKK(x,y)>0 or cmpKK(x,y)==0 )
         {
            z++;
            y = m.key.arr[z];
         }
         else
         {
            z++;
            x = y;
            y = m.key.arr[z];
         }
      }
      arrAdd<K>(a.key,x);
      arrAdd<T>(a.value,*mapGet<K, T>(m,x));
      mapRemove<K, T>(m,x);
      z = 1;
   }
   arrAdd<K>(a.key,m.key.arr[0]);
   arrAdd<T>(a.value,m.value.arr[0]);
   mapRemoveAll<K, T>(m);
   for( int i = 0; i<a.key.len; i++ )
   {
      mapPut<K, T>(m,a.key.arr[i],a.value.arr[i]);
   }

}

template <typename K, typename T>
void mapSortByValues(Map<K, T>& m, int cmpTT(T, T))
{
   Map<K, T> a = map<K, T>();
      K x,y;
      int z = 1;
      while( mapHasNext<K, T>(m) )
      {
         x = m.key.arr[0];
         y = m.key.arr[1];
         while( z<m.key.len )
         {
            if( cmpTT(*mapGet<K,T>(m,x),*mapGet<K,T>(m,y))>0 or cmpTT(*mapGet<K,T>(m,x),*mapGet<K,T>(m,y))==0 )
            {
               z++;
               y = m.key.arr[z];
            }
            else
            {
               z++;
               x = y;
               y = m.key.arr[z];
            }
         }
         arrAdd<K>(a.key,x);
         arrAdd<T>(a.value,*mapGet<K, T>(m,x));
         mapRemove<K, T>(m,x);
         z = 1;
      }
      arrAdd<K>(a.key,m.key.arr[0]);
      arrAdd<T>(a.value,m.value.arr[0]);
      mapRemoveAll<K, T>(m);
      for( int i = 0; i<a.key.len; i++ )
      {
         mapPut<K, T>(m,a.key.arr[i],a.value.arr[i]);
      }
}

#endif
