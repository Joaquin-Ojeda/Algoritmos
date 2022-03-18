/*
 * =======>>> LEER LEER LEER LEER LEER LEER <<<==========
 * 1. Copiar copiar y pegar (CTRL+C, CTRL+V) este proyecto
 *    para crear uno nuevo con el nombre del TAD que se quiere
 *    crear. Por ejemplo: BigInt.hpp
 * 2. Cambiar: _TADXXXXX_ por: #ifndef _TADBIGINT_
 * 3. Programar la estructura y las funciones del TAD.
 */

#ifndef _TADBIGINT_
#define _TADBIGINT_

#include <iostream>
using namespace std;

struct BigInt
{
   string s;
};

BigInt bigIntCreate(string n)
{
   BigInt x = { n };
   return x;
}
BigInt bigIntSumar(BigInt a, BigInt b)
{
   BigInt x;
   string suma;
   char d,c;
   int y,z,s,r = 0;
   if( length(a.s)>length(b.s) )
   {
      for( int i = 0; i<length(a.s); i++ )
      {
         if( length(b.s)-1<i )
         {
            d = a.s[(length(a.s)-1)-i];
            c = '0';
         }
         else
         {
            d = a.s[(length(a.s)-1)-i];
            c = b.s[(length(b.s)-1)-i];
         }
         y = charToInt(d);
         z = charToInt(c);
         s = y+z+r;
         if( s<10 )
         {
            suma = intToChar(s)+suma;
         }
         else
         {
            r = getDigit(s,1);
            suma = intToChar(getDigit(s,0))+suma;
         }
      }
   }
   else
   {
      for( int i = 0; i<length(b.s); i++ )
      {
         if( length(a.s)-1<i )
         {
            d = '0';
            c = b.s[(length(b.s)-1)-i];
         }
         else
         {
            d = a.s[(length(a.s)-1)-i];
            c = b.s[(length(b.s)-1)-i];
         }
         y = charToInt(d);
         z = charToInt(c);
         s = y+z+r;
         if( s<10 )
         {
            suma = intToChar(s)+suma;
         }
         else
         {
            r = getDigit(s,1);
            suma = intToChar(getDigit(s,0))+suma;
         }
      }
   }
   if(r==1 and suma[0]=='0' )
   {
      suma='1'+suma;
   }
   x.s = suma;
   return x;
}

#endif
