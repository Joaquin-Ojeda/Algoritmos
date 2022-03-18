#ifndef _TBITREADER_T_
#define _TBITREADER_T_

#include <iostream>
//#include "biblioteca/tads/Arr.hpp"
//#include "biblioteca/tads/Map.hpp"
//#include "biblioteca/tads/1List.hpp"
//#include "biblioteca/tads/Stack.hpp"
//#include "biblioteca/tads/Queue.hpp"
//#include "biblioteca/funciones/strings.hpp"
//#include "biblioteca/funciones/tokens.hpp"
//#include "biblioteca/funciones/files.hpp"
using namespace std;


struct BitReader
{
   FILE* f;
   unsigned char byte;
   int pos;
};

BitReader bitReaderCreate(FILE* f)
{
   BitReader bits;
   bits.f=f;
   bits.byte=0;
   bits.pos=0;
   return bits;
}

int bitReaderRead(BitReader& br)
{
   if(br.pos == 0)
   {
      br.byte = read<char>(br.f);
      br.pos = 8;
   }

   br.pos--;

   return (br.byte>>br.pos)&1;
}

#endif
