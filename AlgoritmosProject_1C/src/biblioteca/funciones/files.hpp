#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template<typename T> T read(FILE* f)
{
   T x;
   fread(&x,sizeof(T),1,f);
   return x;
}

template<typename T> void write(FILE* f, T v)
{
   fwrite(&v,sizeof(T),1,f);
}

template<typename T> void seek(FILE* f, int n)
{
   fseek(f,sizeof(T)*n,SEEK_SET);
}

template<typename T> long fileSize(FILE* f)
{
   int pa=ftell(f);
   fseek(f,0,SEEK_END);
   int pf=ftell(f);
   fseek(f,pa,SEEK_SET);
   return pf/sizeof(T);
}

template<typename T> long filePos(FILE* f)
{
   return ftell(f)/sizeof(T);
}

#endif
