/*
 * =======>>> LEER LEER LEER LEER LEER LEER <<<==========
 * 1. Copiar copiar y pegar (CTRL+C, CTRL+V) este proyecto
 *    para crear uno nuevo con el nombre del TAD que se quiere
 *    crear. Por ejemplo: BigInt.hpp
 * 2. Cambiar: _TADXXXXX_ por: #ifndef _TADBIGINT_
 * 3. Programar la estructura y las funciones del TAD.
 */

#ifndef _TADFecha_
#define _TADFecha_

#include <iostream>
using namespace std;

struct Fecha
{
   int dia;
   int mes;
   int anio;
};
Fecha fechaCreate(int d, int m, int a)
{
   Fecha fecha = { d, m, a };
   return fecha;
}
bool fechaAnioBisiesto(Fecha f)
{
   bool x = false;
   if( f.anio%4==0 or (f.anio%100==0 and f.anio%400!=0) )
   {
      x = true;
   }
   return x;
}
int fechaDiasDelMes(Fecha f)
{
   int d;
   bool x = fechaAnioBisiesto(f);
   if( f.mes==2 )
   {
      if( x==true )
      {
         d = 29;
      }
      else
      {
         d = 28;
      }
   }
   else
   {
      if( f.mes==1 or f.mes==3 or f.mes==5 or f.mes==7 or f.mes==8 or f.mes==10 or f.mes==12 )
      {
         d = 31;
      }
      else
      {
         d = 30;
      }
   }
   return d;
}
Fecha fechaSumarDias(Fecha f, int n)
{
   int i = fechaDiasDelMes(f);
   Fecha fecha = f;
   while( n!=0 )
   {
      if( fecha.dia+n>i )
      {
         i = fechaDiasDelMes(fecha);
         fecha.mes++;
         n = (n-1)-(i-fecha.dia);
         fecha.dia = 1;
         if( fecha.mes>12 )
         {
            fecha.mes = 1;
            fecha.anio++;
         }
      }
      else
      {
         fecha.dia = fecha.dia+n;
         n = 0;
      }
   }

   return fecha;
}
int fechaDiferenciaEnDias(Fecha f1, Fecha f2)
{
   int d;
   if( f1.anio==f2.anio )
   {
      if( f1.mes==f2.mes )
      {
         if( f1.dia>f2.dia )
         {
            d = f1.dia-f2.dia;
         }
         else
         {
            d = f2.dia-f1.dia;
         }
      }
      else
      {
         if( f1.mes>f2.mes )
         {
            d = f1.dia;
            f1.mes--;
            while( f1.mes!=f2.mes )
            {
               d = d+fechaDiasDelMes(f1);
               f1.mes--;
            }
            d = d+(fechaDiasDelMes(f2)-f2.dia);
         }
         else
         {
            d = f2.dia;
            f2.mes--;
            while( f2.mes!=f1.mes )
            {
               d = d+fechaDiasDelMes(f2);
               f2.mes--;
            }
            d = d+(fechaDiasDelMes(f1)-f1.dia);
         }
      }
   }
   else
   {
      if( f1.anio>f2.anio )
      {
         d = (f1.anio-f2.anio)*365;
         if( f1.mes==f2.mes )
         {
            if( f1.dia>f2.dia )
            {
               d = d+f1.dia-f2.dia;
            }
            else
            {
               d = d+f2.dia-f1.dia;
            }
         }
         else
         {
            if( f1.mes>f2.mes )
            {
               d = d+f1.dia;
               f1.mes--;
               while( f1.mes!=f2.mes )
               {
                  d = d+fechaDiasDelMes(f1);
                  f1.mes--;
               }
               d = d+(fechaDiasDelMes(f2)-f2.dia);
            }
            else
            {
               d = d+f2.dia;
               f2.mes--;
               while( f2.mes!=f1.mes )
               {
                  d = d+fechaDiasDelMes(f2);
                  f2.mes--;
               }
               d = d+(fechaDiasDelMes(f1)-f1.dia);
            }
         }

      }
      else
      {
         d = (f2.anio-f1.anio)*365;
         if( f1.mes==f2.mes )
         {
            if( f1.dia>f2.dia )
            {
               d = d+f1.dia-f2.dia;
            }
            else
            {
               d = d+f2.dia-f1.dia;
            }
         }
         else
         {
            if( f1.mes>f2.mes )
            {
               d = d+f1.dia;
               f1.mes--;
               while( f1.mes!=f2.mes )
               {
                  d = d+fechaDiasDelMes(f1);
                  f1.mes--;
               }
               d = d+(fechaDiasDelMes(f2)-f2.dia);
            }
            else
            {
               d = d+f2.dia;
               f2.mes--;
               while( f2.mes!=f1.mes )
               {
                  d = d+fechaDiasDelMes(f2);
                  f2.mes--;
               }
               d = d+(fechaDiasDelMes(f1)-f1.dia);
            }
         }

      }
   }
   return d;
}
void fechaMasCercana(Fecha f1, Fecha f2, Fecha f3)
{
   if( fechaDiferenciaEnDias(f1,f2)>fechaDiferenciaEnDias(f1,f3) )
   {
      cout<<"La fecha mas cercana a "<<f1.dia<<"/"<<f1.mes<<"/"<<f1.anio<<" es "<<f3.dia<<"/"<<f3.mes<<"/"<<f3.anio<<endl;
   }
   else
   {
      if( fechaDiferenciaEnDias(f1,f2)==fechaDiferenciaEnDias(f1,f3) )
      {
         cout<<"Ambas fechas estan a la misma cantidad de dias"<<endl;
      }
      else
      {
         cout<<"La fecha mas cercana a "<<f1.dia<<"/"<<f1.mes<<"/"<<f1.anio<<" es "<<f2.dia<<"/"<<f2.mes<<"/"<<f2.anio<<endl;
      }
   }
}
#endif
