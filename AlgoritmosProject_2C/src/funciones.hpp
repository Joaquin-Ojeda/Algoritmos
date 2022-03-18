#ifndef _FUNCIONES
#define _FUNCIONES

#include <iostream>
#include "biblioteca/tads/Arr.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/HuffmanTree.hpp"
#include "biblioteca/tads/Fecha.hpp"

struct Obra
{
int idObra;
char titulo[100];
Fecha fEstreno; //TAD
int idTeatro;
};

struct Teatro
{
int idTeatro;
char direccion[50];
int capacidad;
int sectores;
};

struct Reserva
{
int idCliente;
int idObra;
int idFuncion;
int sector; // sector de la sala; ej: Pullman,Platea...
int cant;
};
struct Funcion
{
int idFuncion;
int diaSem; // 1=>Lunes, 2=>Martes, ...
int hora; // TAD
};

struct rSectores
{
   Arr<int> cap;
};


struct rFunciones
{
   Funcion fun;
   Obra ob;
   Teatro tea;
   rSectores cant;
   bool acep;
   int rechazadas;
};
struct FuncionesObra
{
   List<Funcion> lista;
   int idObra;
};

List<Funcion>funcionesProgramadas(int idObra)
{
   return{};
}
int capacidadSector(int idTeatro,int sector)
{
   return 0;
}
int cmpFuncionesObraInt(FuncionesObra a,int b)
{
   return a.idObra-b;
}

template <typename K, typename T>
Map<K, T>pasarArchivosAMap(FILE* f)
{
   Map<K,T> x=map<K,T>();
   return x;
}
int cmpIdFuncion(Funcion a,int b)
{
   return a.idFuncion-b;
}
int cmpRFuncionesFuncion(rFunciones a,Funcion b)
{
   return a.fun.idFuncion-b.idFuncion;
}

int cmpFuncionObraIdObra(FuncionesObra a,int b)
{

   return a.idObra-b;
}

void llenarSectores(rFunciones* y)
{
   int capacidad;
   for(int i=1;i<=y->tea.sectores;i++)
   {
      capacidad=capacidadSector(y->tea.idTeatro,i);
      arrAdd<int>(y->cant.cap,capacidad);
   }
}

rFunciones operarReserva(Reserva res,Map<int,Obra>obras,Map<int,Teatro>teatros,List<rFunciones> func,List<FuncionesObra> fu)
{
   FuncionesObra funci=*listFind<FuncionesObra>(fu,res.idObra,cmpFuncionObraIdObra);
   Funcion* x=listFind<Funcion>(funci.lista,res.idFuncion,cmpIdFuncion);
   rFunciones* y=listFind<rFunciones>(func,*x,cmpRFuncionesFuncion);
   if(y==NULL)
   {
    y->fun=*x;
    y->ob=*mapGet<int,Obra>(obras,res.idObra);
    y->tea=*mapGet<int,Teatro>(teatros,y->ob.idTeatro);
    llenarSectores(y);
    listAdd<rFunciones>(func,*y);
   }
   if(*arrGet<int>(y->cant.cap,res.sector-1)-res.cant>=0)
   {
      y->acep=true;
      int* capActualizada=arrGet<int>(y->cant.cap,res.sector-1);
      *capActualizada=*arrGet<int>(y->cant.cap,res.sector-1)-res.cant;
   }
   else
   {
      y->acep=false;
      y->rechazadas+=res.cant;
   }

   return *y;

}



void mostrarRechazadas(List<rFunciones>rechazadas)
{
   rFunciones* x=listNext<rFunciones>(rechazadas);
   while(listHasNext<rFunciones>(rechazadas))
   {
      cout<<x->ob.titulo<<endl;
      cout<<x->fun.diaSem<<"/"<<x->fun.hora<<"     "<<x->rechazadas<<endl;
      x=listNext<rFunciones>(rechazadas);
   }
}


#endif
