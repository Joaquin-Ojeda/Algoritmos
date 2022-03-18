/*
 * =======>>> LEER LEER LEER LEER LEER LEER <<<==========
 * 1. Copiar copiar y pegar (CTRL+C, CTRL+V) este proyecto
 *    para crear uno nuevo con el nombre del TAD que se quiere
 *    crear. Por ejemplo: BigInt.hpp
 * 2. Cambiar: _TADXXXXX_ por: #ifndef _TADBIGINT_
 * 3. Programar la estructura y las funciones del TAD.
 */

#ifndef _TADBITWRITER_
#define _TADBITWRITER_

#include "../funciones/strings.hpp"
#include "../funciones/files.hpp"
#include "../tads/Arr.hpp"
#include <iostream>
using namespace std;

struct BitWriter
{
   FILE* x;
   Arr<int> byte;
};

BitWriter bitWriter(FILE* f)
{
   BitWriter bit;
   bit.x = f;
   bit.byte = arr<int>();
   return bit;
}
void bitWriterWrite(BitWriter& bw, int bit)
{
   int aux = 1;
   int byte = 0;
   arrAdd<int>(bw.byte,bit);
   if( arrSize<int>(bw.byte)==8 )
   {
      for( int i = 7; i>=0; i-- )
      {
         if( bw.byte.arr[i]==1 )
         {
            byte = byte+aux;
         }
         aux = aux*2;
      }
      write<unsigned char>(bw.x,byte);

      aux = 1;
      byte = 0;
      arrRemoveAll<int>(bw.byte);
   }
}

void bitWriterFlush(BitWriter& bw)
{
   while( arrSize<int>(bw.byte)<7 )
   {
      bitWriterWrite(bw,0);
   }
   bitWriterWrite(bw,0);

}

#endif
