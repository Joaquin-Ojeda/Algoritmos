/*
 * =======>>> LEER LEER LEER LEER LEER LEER <<<==========
 * 1. Copiar copiar y pegar (CTRL+C, CTRL+V) este proyecto
 *    para crear uno nuevo con el nombre del TAD que se quiere
 *    crear. Por ejemplo: BigInt.hpp
 * 2. Cambiar: _TADXXXXX_ por: #ifndef _TADBIGINT_
 * 3. Programar la estructura y las funciones del TAD.
 */

#ifndef _TADBITREADER_
#define _TADBITREADER_

#include "../funciones/strings.hpp"
#include "../funciones/files.hpp"
#include <iostream>
using namespace std;

struct BitReader
{
   FILE* x;
   unsigned char byte;
   int aux;
};

BitReader bitReader(FILE* f)
{
   BitReader bin;
   bin.x = f;
   bin.byte = '\0';
   bin.aux = 7;
   return bin;
}
int bitReaderRead(BitReader& br)
{
   int bit;
   if( br.byte=='\0' )
   {
      br.byte = read<unsigned char>(br.x);
   }
   if( br.aux>0 )
   {
      bit = br.byte>>br.aux;
      bit = bit&1;
      br.aux--;
   }
   else
   {
      bit = br.byte>>br.aux;
      bit = bit&1;
      br.aux=7;
      br.byte = read<unsigned char>(br.x);
   }

   return (int)bit;
}

#endif
