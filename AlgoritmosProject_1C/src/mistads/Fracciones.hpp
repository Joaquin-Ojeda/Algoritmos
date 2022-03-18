/*
 * =======>>> LEER LEER LEER LEER LEER LEER <<<==========
 * 1. Copiar copiar y pegar (CTRL+C, CTRL+V) este proyecto
 *    para crear uno nuevo con el nombre del TAD que se quiere
 *    crear. Por ejemplo: BigInt.hpp
 * 2. Cambiar: _TADXXXXX_ por: #ifndef _TADBIGINT_
 * 3. Programar la estructura y las funciones del TAD.
 */

#ifndef _TADFraccion_
#define _TADFraccion_

#include "../funciones/strings.hpp"
#include <iostream>
using namespace std;

struct Fraccion
{
   int num;
   int den;
};

Fraccion fraccionCreate(int num, int den)
{
   Fraccion f = { num, den };
   return f;
}
void fraccionSimplificar(Fraccion& f)
{
   int i = 2;
   while( i<=f.num )
   {
      if( f.num%i==0 and f.den%i==0 )
      {
         f.num = f.num/i;
         f.den = f.den/i;
         i = 2;
      }
      else
      {
         i++;
      }
   }

}
Fraccion fraccionSumar(Fraccion f1, Fraccion f2)
{
   Fraccion suma;
   suma.den = f1.den*f2.den;
   suma.num = ((suma.den/f1.den)*f1.num)+((suma.den/f2.den)*f2.num);
   fraccionSimplificar(suma);
   return suma;
}
Fraccion fraccionRestar(Fraccion f1, Fraccion f2)
{
   Fraccion resta;
   resta.den = f1.den*f2.den;
   resta.num = ((resta.den/f1.den)*f1.num)-((resta.den/f2.den)*f2.num);
   fraccionSimplificar(resta);
   return resta;
}
Fraccion fraccionMultiplicar(Fraccion f1, Fraccion f2)
{
   Fraccion producto=fraccionCreate(f1.num*f2.num,f1.den*f2.den);
   fraccionSimplificar(producto);
   return producto;
}
Fraccion fraccionDividir(Fraccion f1, Fraccion f2)
{
   Fraccion cociente=fraccionCreate(f1.num*f2.den,f1.den*f2.num);
   fraccionSimplificar(cociente);
   return cociente;
}
#endif
