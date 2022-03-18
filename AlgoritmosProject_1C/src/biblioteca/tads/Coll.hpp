#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"

using namespace std;

template <typename T>
struct Coll
{
   string s;
   char sep;
   int pos;
};

// collCreate
template <typename T>
Coll<T> collCreate()
{
   Coll<T> x;
   x.sep = '/';
   x.pos=0;
   return x;
}

template <typename T>
Coll<T> collCreate(char c)
{
   Coll<T> x;
   x.sep = c;
   x.pos=0;
   return x;
}

template <typename T>
int collSize(Coll<T> c)
{
   return tokenCount(c.s,c.sep);
}

template <typename T>
void collRemoveAll(Coll<T>& c)
{
   c.s = "";
}

template <typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   removeTokenAt(c.s,c.sep,p);
}

// -- [GENERICAS] --

template <typename T>
int collAdd(Coll<T>& c, T t, string tToString(T))
{
   string x = tToString(t);
   addToken(c.s,c.sep,x);
   return collSize(c)-1;
}

template <typename T>
void collSetAt(Coll<T>& c, T t, int p, string tToString(T))
{
   string x = tToString(t);
   setTokenAt(c.s,c.sep,x,p);
}

template <typename T>
T collGetAt(Coll<T> c, int p, T tFromString(string))
{
   string x = getTokenAt(c.s,c.sep,p);
   T t = tFromString(x);
   return t;
}

template <typename T, typename K>
int collFind(Coll<T> c, K k, int cmpTK(T, K), T tFromString(string))
{
   int x = -1;
   for( int i = 0; i<collSize(c); i++ )
   {
      if( cmpTK(collGetAt(c,i,tFromString),k)==0 and x==-1 )
      {
         x = i;
      }
   }
   return x;
}

template <typename T>
void collSort(Coll<T>& c, int cmpTT(T, T), T tFromString(string), string tToString(T))
{
   Coll<T> x = collCreate<T>(c.sep);
   int a = 0,b = 1,i = 0,y = 1,z=collSize(c);
   while( a<z )
   {
      while( b<collSize(c) )
      {
         if( cmpTT(collGetAt(c,i,tFromString),collGetAt(c,y,tFromString))>=0 )
         {
            y++;

         }
         else
         {
            i = y;
            y++;

         }
         b++;
      }
      collAdd(x,collGetAt(c,i,tFromString),tToString);
      collRemoveAt(c,i);
      i = 0;
      y = 1;
      a++;
      b=1;
   }
   c.s = x.s;
}

template <typename T>
bool collHasNext(Coll<T> c)
{
   while(c.pos<collSize(c))
   {
      return true;
   }
   return false;
}

template <typename T>
T collNext(Coll<T>& c, T tFromString(string))
{
   T t;
   t=collGetAt(c,c.pos,tFromString);
   c.pos++;
   return t;
}

template <typename T>
void collReset(Coll<T>& c)
{
   c.pos=0;
}
template<typename T>
string collToString(Coll<T> c)
{
   return c.sep+c.s;
}

template<typename T>
Coll<T> collFromString(string s)
{
   Coll<T> c;
   c.sep=s[0];
   c.s=substring(s,1);
   return c;
}

#endif
