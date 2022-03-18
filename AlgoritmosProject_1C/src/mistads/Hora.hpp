/*
 * =======>>> LEER LEER LEER LEER LEER LEER <<<==========
 * 1. Copiar copiar y pegar (CTRL+C, CTRL+V) este proyecto
 *    para crear uno nuevo con el nombre del TAD que se quiere
 *    crear. Por ejemplo: BigInt.hpp
 * 2. Cambiar: _TADXXXXX_ por: #ifndef _TADBIGINT_
 * 3. Programar la estructura y las funciones del TAD.
 */

#ifndef _TADHORA_
#define _TADHORA_


#include <iostream>
using namespace std;

struct Hora
{
   int hora;
   int minutos;
   int segundos;
};
Hora horaCreate(int h,int m,int s)
{
   Hora hora={h,m,s};
   return hora;
}
int horaAMinutos(Hora h)
{
   int min=(h.hora*60)+h.minutos;
   return min;
}
int horaASegundos (Hora h)
{
   int seg=((horaAMinutos(h)*60)+h.segundos);
   return seg;
}
Hora horaSumarSegundos(Hora h, int n)
{
   Hora h2=h;
   while (n!=0)
   {
      if (h2.segundos+n>59)
      {
         n=(n-1)-(60-h2.segundos);
         h2.minutos++;
         h2.segundos=1;
         if (h2.minutos>=60)
         {
            h2.hora++;
            h2.minutos=1;
         }
         if (h2.hora>=24)
         {
            h2.hora=0;

         }
      }
      else
      {
         h2.segundos=h2.segundos+n;
         n=0;
      }
   }
   return h2;
}

#endif
