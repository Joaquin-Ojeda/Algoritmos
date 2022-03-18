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
#include <iostream>
using namespace std;

struct BitWriter
{
   FILE* x;
};

BitWriter bitWriterCreate(FILE* f)
{
   BitWriter bin;
   bin.x=f;
   return bin;
}
void bitWriterWrite(BitWriter bw,int bit)
{
   write(bw.x,bit);
}
#endif
