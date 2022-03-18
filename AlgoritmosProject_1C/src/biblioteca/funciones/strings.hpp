#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

// --[ Funciones Basicas ]--

// Descripcion: Retorna la longitud de la cadena s
// Paramerto:
//    s - La cadena cuya longitud se desea conocer
// Retorna: la longitud de la cadena s
// Ejemplo: l
int length(string s)
{
   int i;
   for( i = 0; s[i]!='\0'; i++ )
   {

   }
   return i;
}

// Retorna la cantidad de veces que la cadena s contiene a c
int charCount(string s, char c)
{
   int n = 0;
   for( int i = 0; s[i]!='\0'; i++ )
   {
      if( s[i]==c )
      {
         n++;
      }
   }
   return n;
}

// Retorna la subcadena de s comprendida entre d (inclusive) y h (no inclusive)
string substring(string s, int d, int h)
{
   string f;
   for( int i = 0; s[i]!='\0'; i++ )
   {
      if( i>=d and i<h-1 )
      {
         f = f+s[i];
      }
   }
   return f;
}

// Retorna la subcadena de s que va desde d (inclusive) hasta el final
string substring(string s, int d) // ok
{
   string f;
   for( int i = 0; s[i]!='\0'; i++ )
   {
      if( i>=d )
      {
         f = f+s[i];
      }
   }
   return f;
}

// Retorna la posicion de la primer ocurrencia
// de c dentro s, o -1 si s no contiene a c
int indexOf(string s, char c) // ok
{
   int n = -1;
   for( int i = 0; s[i]!='\0'; i++ )
   {
      if( n==-1 and s[i]==c )
      {
         n = i;
      }
   }
   return n;
}

// Retorna la posicion de la primer ocurrencia de c dentro de s
// considerando la subcadena de s que va desde offset hasta el final.
// Ejemplo: indexOf("ALGORITMOS",'O',7) retorna: 1
int indexOf(string s, char c, int offSet) // ok
{
   int n = -1;
   for( int i = offSet; s[i]!='\0'; i++ )
   {
      if( n==-1 and s[i]==c )
      {
         n = i-offSet;
      }
   }
   return n;
}

// Retorna la posicion de la ultima ocurrencia de c dentro de s
// o -1 si s no contiene a c
int lastIndexOf(string s, char c)
{
   int n = -1;
   for( int i = 0; s[i]!='\0'; i++ )
   {
      if( s[i]==c )
      {
         n = i;
      }
   }
   return n;
}

// Retorna la posicion de la n-esima ocurrencia de c dentro de s.
// Por ejemplo: indexOfN("pedro|pablo|juan|rolo",'|',2) retorna 11.
int indexOfN(string s, char c, int n)
{
   int a = -1,x = 1;
   for( int i = 0; s[i]!='\0'; i++ )
   {
      if( x==n and s[i]==c )
      {
         a = i;
      }
      if( s[i]==c )
      {
         x++;
      }
   }
   return a;
}

// Retorna el valor numerico de ch.
// Ejemplo: charToInt('4') retorna: 4.
int charToInt(char ch)
{
   int a = ch-48;

   return a;
}

// Retorna el valor char de i.
// Ejemplo: intToChar(4) retorna: '4'.
char intToChar(int i)
{
   char a = i+48;
   return a;
}

// retorna el i-esimo digito de n contando desde la derecha
int getDigit(int n, int i) // ok
{
   int a = 0,div = 1,f;
   while( a<=i )
   {
      a++;
      div = div*10;
   }
   f = (n%div)/(div/10);
   return f;
}

int digitCount(int i) // ok
{
   int n = 1;
   while( i>=10 )
   {
      i = i/10;
      n++;
   }
   return n;
}

string intToString(int num) // ok
{
   string f;
   int n,i;
   for( i = digitCount(num)-1; i>=0; i-- )
   {
      n = getDigit(num,i);
      f = f+intToChar(n);
   }

   return f;
}

int stringToInt(string s) // ok
{
   int n = 0,a = 1;
   for( int i = length(s)-1; i>=0; i-- )
   {
      n = n+(charToInt(s[i])*a);
      a = a*10;
   }
   return n;
}

int stringToInt(string s, int b) // ok
{
// PROGRAMAR AQUI...
   return 0;
}

string charToString(char c)
{
   string f;
   f = f+c;
   return f;
}

char stringToChar(string s)
{
   char c = s[0];
   return c;
}

string stringToString(string s)
{
   return s;
}

string doubleToString(double d)
{
   int a = (int)d,b;
   string f = intToString(d)+'.';
   while( d>a )
   {
      d = d*10;
      a = (int)d;
      b = getDigit(a,0);
      f = f+intToChar(b);
   }
   return f;
}

double stringToDouble(string s)
{
   double d = 0,x = 0.1;
   int i = 0;
   for( i = 0; s[i]!='.'; i++ )
   {
      d = d*10+charToInt(s[i]);
   }
   for( i = i+1; s[i]!='\0'; i++ )
   {
      d = d+charToInt(s[i])*x;
      x = x/10;
   }
   return d;
}

bool isEmpty(string s)
{
   bool n = false;
   if( s[0]=='\0' )
   {
      n = true;
   }
   return n;
}

bool contains(string s, char c)
{
   bool n = false;
   for( int i = 0; s[i]!='\0'; i++ )
   {
      if( s[i]==c )
      {
         n = true;
      }
   }
   return n;
}

string replace(string s, char oldChar, char newChar)
{
   string f;
   for( int i = 0; s[i]!='\0'; i++ )
   {
      if( s[i]==oldChar )
      {
         f = f+newChar;
      }
      else
      {
         f = f+s[i];
      }
   }
   return f;
}

string insertAt(string s, int pos, char c)
{
   string f;
   for( int i = 0; s[i]!='\0'; i++ )
   {
      if( i==pos )
      {
         f = f+c;
      }
      f = f+s[i];
   }
   return f;
}

string removeAt(string s, int pos)
{
   string f;
   for( int i = 0; s[i]!='\0'; i++ )
   {
      if( i!=pos )
      {
         f = f+s[i];
      }
   }
   return f;
}

string ltrim(string s)
{
   string f;
   for( int i = 0; s[i]!='\0'; i++ )
   {
      while( s[i]==' ' and f=="" )
      {
         i++;
      }
      f = f+s[i];
   }
   return f;
}

string rtrim(string s)
{
   string f = s;
   for( int i = length(f)-1; f[i]==' '; i-- )
   {
      f = removeAt(f,i);
   }
   return f;
}

string trim(string s)
{
   string f = ltrim(s);
   f = rtrim(f);
   return f;
}

string replicate(int n, char c)
{
   string s;
   for( int i = 0; i<n; i++ )
   {
      s = s+c;
   }
   return s;
}

string spaces(int n)
{
   string s;
   for( int i = 0; i<n; i++ )
   {
      s = s+' ';
   }
   return s;
}

string lpad(string s, int n, char c)
{
   string f;
   for( int i = n-length(s); i>0; i-- )
   {
      f = f+c;
   }
   f = f+s;
   return f;
}

string rpad(string s, int n, char c)
{
   string f;
   f = f+s;
   for( int i = n-length(s); i>0; i-- )
   {
      f = f+c;
   }

   return f;
}

string cpad(string s, int n, char c)
{
   int i = n-length(s),a = length(s)+(i/2);
   string f = lpad(s,a,c);
   f = rpad(f,n,c);

   return f;
}

bool isDigit(char c)
{
   if( c>47 and c<58 )
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool isLetter(char c)
{
   if( (c>64 and c<91) or (c>96 and c<123) )
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool isUpperCase(char c)
{
   if( c>64 and c<91 )
   {
      return true;
   }
   else
   {
      return false;
   }
}

bool isLowerCase(char c)
{
   if( c>96 and c<123 )
   {
      return true;
   }
   else
   {
      return false;
   }
}

char toUpperCase(char c)
{
   char a = c-32;
   return a;
}

char toLowerCase(char c)
{
   char a = c+32;
   return a;
}

#endif
