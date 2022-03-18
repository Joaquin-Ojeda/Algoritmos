#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[], int& len, T v)
{
   arr[len] = v;
   len ++;
   return len;
}

template <typename T>
void insert(T arr[], int& len, T v, int pos)
{
   for( int i = len; i>pos; i-- )
   {
      arr[i+1] = arr[i];
      arr[i] = arr[i-1];
   }
   arr[pos] = v;
   len++;
}

template <typename T>
T remove(T arr[], int& len, int pos)
{
   T ret = arr[pos];
   for( int i = pos; i<len-1; i++ )
   {
      arr[i] = arr[i+1];
   }
   len--;
   return ret;
}

template <typename T, typename K>
int find(T arr[], int len, K v, int cmpTK(T, K))
{
   int a = -1;
   for( int i = 0; i<len; i++ )
   {
      if( cmpTK(arr[i],v)==0 and a==-1 )
      {
         a = i;
      }
   }
   return a;
}

template <typename T>
int orderedInsert(T arr[], int& len, T v, int cmpTT(T, T))
{
   int f = -1;
   for( int i = 0; i<len and f==-1; i++ )
   {
      if( cmpTT(arr[i],v)==0 or cmpTT(arr[i],v)>0 )
      {
         insert<T>(arr,len,v,i);
         f = i;
      }
   }
   if (f==-1)
   {
      f=len;
      add<T>(arr,len,v);

   }

   return f;
}

template <typename T>
void sort(T arr[], int len, int cmpTT(T, T))
{
   T ar[len];
   int lenn = 0;
   for( int i = 0; i<len; i++ )
   {
      if( i!=0 )
      {
         orderedInsert<T>(ar,lenn,arr[i],cmpTT);
      }
      else
      {
         add<T>(ar,lenn,arr[i]);
      }
   }
   for( int i = 0; i<len; i++ )
   {
      arr[i] = ar[i];
   }
}

#endif
