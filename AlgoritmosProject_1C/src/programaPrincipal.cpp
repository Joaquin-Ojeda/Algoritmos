#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "programaPrincipal.hpp"
using namespace std;
//Estrategia: A medida que se leen los gastos ir guardando los datos que se piden para el listado y un total para luego sacar
//el porcentaje. ordenar los datos por "Categoria" de manera ascendente y mostrarlo. Repetir esto para cada consorcio.

Coll<Consorcio> crearCollConsorcio(FILE* g)
{
   Coll<Consorcio> x = collCreate<Consorcio>();
   Consorcio a = read<Consorcio>(g);
   while( !feof(g) )
   {
      collAdd<Consorcio>(x,a,consorcioToString);
      a = read<Consorcio>(g);
   }
   return x;
}
int cmpTotalString(Total x, string y)
{
   return x.categoria==y?1:-1;
}
void cargarGastos(Gasto x, Coll<Final>& fin)
{
   Final rfin = collGetAt<Final>(fin,0,finalFromString);
   rfin.final += x.importe;
   collRemoveAt<Final>(fin,0);
   collSetAt<Final>(fin,rfin,0,finalToString);
   Total rtot;
   int y = collFind<Total, string>(rfin.totalColl,x.categoria,cmpTotalString,totalFromString);
   if( y>0 )
   {
      rtot = collGetAt<Total>(rfin.totalColl,y,totalFromString);
      rtot.total += x.importe;
      collRemoveAt<Total>(rfin.totalColl,y);
      collSetAt<Total>(rfin.totalColl,rtot,y,totalToString);
   }
   else
   {
      (string)rtot.categoria =x.categoria;
      rtot.total = x.importe;
      collAdd<Total>(rfin.totalColl,rtot,totalToString);
   }
}
int cmpConsorcioInt(Consorcio x, int y)
{
   return x.idCons==y?1:-1;
}
int cmpTotalTotal(Total x, Total y)
{
   return x.categoria>y.categoria?1:x.categoria<y.categoria?-1:0;
}
void mostrarListado(Coll<Final> fin, Coll<Consorcio> cons, int idConsorcio)
{
   int x = collFind<Consorcio, int>(cons,idConsorcio,cmpConsorcioInt,consorcioFromString);
   Consorcio a = collGetAt<Consorcio>(cons,x,consorcioFromString);
   cout<<"Consorcio "<<idConsorcio<<" calle: "<<a.direccion<<endl;
   Final final = collNext<Final>(fin,finalFromString);

   collSort<Total>(final.totalColl,cmpTotalTotal,totalFromString,totalToString);
   Total t = collNext<Total>(final.totalColl,totalFromString);
   while( collHasNext<Total>(final.totalColl) )
   {
      cout<<"Categoria: "<<t.categoria<<endl;
      cout<<"Total gastos: "<<t.total<<endl;
      cout<<"Porc. total: "<<(t.total*100)/final.final<<"%"<<endl;
      t=collNext<Total>(final.totalColl,totalFromString);
   }
}

void resetColl(Coll<Final>& fin)
{
   Final final = collNext<Final>(fin,finalFromString);
   final.final=0;
   collRemoveAll(final.totalColl);
}

int main()
{
FILE* f = fopen("GASTOS.dat","r+b");
FILE* g = fopen("CONSORCIO.dat","r+b");
//Primero pasamos todos los datos del consorcio a una collecion.
Coll<Consorcio> cons = crearCollConsorcio(g);
//Creamos una coleccion con los datos que necesitamos para el listado.Como adentro hay otra coleccion hay que crear esa primero.
Coll<Total> tot = collCreate<Total>();
Coll<Final> fin = collCreate<Final>();
//Leemos los gastos(no hace falta guardar los gastos en una colleccion ya que solo los vamos a leer 1 vez cada uno por que estan ordenados por "idCons").
Gasto x = read<Gasto>(f);
int idConsorcio = x.idCons;
while( !feof(f) )
{
   //Una condicion para que cuando cambie de consorcio se muestre el listado pedido.
   if( idConsorcio!=x.idCons )
   {
      mostrarListado(fin,cons,idConsorcio);
      //Funcion para resetear la coleccion.
      resetColl(fin);
      idConsorcio = x.idCons;
   }
   //Cargo los datos en la coleccion.
   cargarGastos(x,fin);
   //Leo el proximo gasto.
   x = read<Gasto>(f);
}
//Para que el ultimo listado no quede fuera vuelvo a invocar la funcion.
mostrarListado(fin,cons,idConsorcio);
fclose(f);
fclose(g);
return 0;
}

