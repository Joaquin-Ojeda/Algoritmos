#ifndef TBITWRITER_T
#define TBITWRITER_T

#include <iostream>
#include "../funciones/files.hpp"

//#include "biblioteca/tads/Arr.hpp"
//#include "biblioteca/tads/Map.hpp"
//#include "biblioteca/tads/1List.hpp"
//#include "biblioteca/tads/Stack.hpp"
//#include "biblioteca/tads/Queue.hpp"
//#include "biblioteca/funciones/strings.hpp"
//#include "biblioteca/funciones/tokens.hpp"
//#include "biblioteca/funciones/files.hpp"
using namespace std;

struct BitWriter
{
   FILE* f;
   unsigned char byte;
   int cont;
};

BitWriter bitWriterCreate(FILE* f)
{
   BitWriter bits;

   bits.f = f;
   bits.byte = 0;
   bits.cont = 0;

   return bits;
}

void bitWriterWrite(BitWriter& bw, int bit)
{
   bw.byte = (bw.byte<<1) | (char)bit;
   bw.cont = bw.cont + 1;

   if( bw.cont==8 )
   {
      write<char>(bw.f,bw.byte);
      bw.cont = 0;
   }
}

void bitWriterFlush(BitWriter bw)
{
   while( bw.cont != 0 )
   {
      bitWriterWrite(bw,0);
   }
}


#endif
