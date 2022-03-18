#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

// --[Funciones Token]--

// s = "John|Paul|George|Ringo"
int tokenCount(string s, char sep) // ok
{
   return charCount(s,sep)+1;
}

// pablo|juan|pedro|carlos
string getTokenAt(string s, char sep, int p)  // ok
{
   string f;
   int a = 0,b = 1;
   for( int i = 0; i<=p; i++ )
   {
      if( p==tokenCount(s,sep)-1 )
      {
         i = p+1;
         f = substring(s,lastIndexOf(s,sep)+1);
      }
      else
      {
         f = substring(s,a,indexOfN(s,sep,b)+1);
         a = indexOfN(s,sep,b)+1;
         b++;
      }
   }
   return f;
}

void addToken(string& s, char sep, string t) // ok
{
   if( s=="" )
   {
      s = t;
   }
   else
   {
      s = s+sep+t;
   }
}

void removeTokenAt(string& s, char sep, int p) //  ok
{
   string f = "";
   int a = 0;
   for( int i = 1; i<=tokenCount(s,sep); i++ )
   {
      if( a!=p )
      {
         addToken(f,sep,getTokenAt(s,sep,a));
      }
      a++;
   }
   s = f;
}

void setTokenAt(string& s, char sep, string t, int p) // ok
{
   string f = "";
   int a = 0;
   for( int i = 1; i<=tokenCount(s,sep); i++ )
   {
      if( a!=p )
      {
         addToken(f,sep,getTokenAt(s,sep,a));
      }
      else
      {
         addToken(f,sep,t);
      }
      a++;
   }
   s = f;
}

int findToken(string s, char sep, string t)
{
   int i,a;
   for (i=0;i<=tokenCount(s,sep)-1;i++)
   {
      if (t==getTokenAt(s,sep,i))
      {
         a=i;
      }
   }
   return a;
}

// --[/Funciones Token]--

#endif
