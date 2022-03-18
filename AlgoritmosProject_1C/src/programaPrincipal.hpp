#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/tads/Coll.hpp"
using namespace std;

struct Gasto
{
   int idCons;
   int fecha;
   double importe;
   char categoria[20];
};

struct Consorcio
{
   int idCons;
   char direccion[50];
   int cantPisos;
   int dtosPorPiso;
};

string gastoToString(Gasto x)
{
   char sep = 1;
   string sIdCons=to_string(x.idCons);
   string sFecha=to_string(x.fecha);
   string sImporte=to_string(x.importe);
   string sCategoria=x.categoria;
   return sIdCons+sep+sFecha+sep+sImporte+sep+sCategoria;
}

Gasto gastoFromString(string s)
{
   char sep = 1;
   Gasto x;
   string t0 = getTokenAt(s,sep,0);
   x.idCons=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   x.fecha=stoi(t1);
   string t2 = getTokenAt(s,sep,2);
   x.importe=stod(t2);
   string t3 = getTokenAt(s,sep,3);
   strcpy(x.categoria,t3.c_str());
   return x;
}

string gastoToDebug(Gasto x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idCons;
   sout << ",";
   sout << x.fecha;
   sout << ",";
   sout << x.importe;
   sout << ",";
   sout << x.categoria;
   sout<< "]";
   return sout.str();
}

Gasto gasto(int idCons,int fecha,double importe,string categoria)
{
   Gasto a;
   a.idCons = idCons;
   a.fecha = fecha;
   a.importe = importe;
   strcpy(a.categoria,categoria.c_str());
   return a;
}

bool gastoEquals(Gasto a,Gasto b)
{
   if(a.idCons!=b.idCons) return false;
   if(a.fecha!=b.fecha) return false;
   if(a.importe!=b.importe) return false;
   return true;
}

string consorcioToString(Consorcio x)
{
   char sep = 2;
   string sIdCons=to_string(x.idCons);
   string sDireccion=x.direccion;
   string sCantPisos=to_string(x.cantPisos);
   string sDtosPorPiso=to_string(x.dtosPorPiso);
   return sIdCons+sep+sDireccion+sep+sCantPisos+sep+sDtosPorPiso;
}

Consorcio consorcioFromString(string s)
{
   char sep = 2;
   Consorcio x;
   string t0 = getTokenAt(s,sep,0);
   x.idCons=stoi(t0);
   string t1 = getTokenAt(s,sep,1);
   strcpy(x.direccion,t1.c_str());
   string t2 = getTokenAt(s,sep,2);
   x.cantPisos=stoi(t2);
   string t3 = getTokenAt(s,sep,3);
   x.dtosPorPiso=stoi(t3);
   return x;
}

string consorcioToDebug(Consorcio x)
{
   stringstream sout;
   sout<< "[";
   sout << x.idCons;
   sout << ",";
   sout << x.direccion;
   sout << ",";
   sout << x.cantPisos;
   sout << ",";
   sout << x.dtosPorPiso;
   sout<< "]";
   return sout.str();
}

Consorcio consorcio(int idCons,string direccion,int cantPisos,int dtosPorPiso)
{
   Consorcio a;
   a.idCons = idCons;
   strcpy(a.direccion,direccion.c_str());
   a.cantPisos = cantPisos;
   a.dtosPorPiso = dtosPorPiso;
   return a;
}

bool consorcioEquals(Consorcio a,Consorcio b)
{
   if(a.idCons!=b.idCons) return false;
   if(a.cantPisos!=b.cantPisos) return false;
   if(a.dtosPorPiso!=b.dtosPorPiso) return false;
   return true;
}
struct Total
{
   char categoria[20];
   double total;
};
struct Final
{
   Coll<Total> totalColl;
   double final;
};
string totalToString(Total x)
{
   char sep = 1;
   string sCategoria=x.categoria;
   string sTotal=to_string(x.total);
   return sCategoria+sep+sTotal;
}

Total totalFromString(string s)
{
   char sep = 1;
   Total x;
   string t0 = getTokenAt(s,sep,0);
   strcpy(x.categoria,t0.c_str());
   string t1 = getTokenAt(s,sep,1);
   x.total=stod(t1);
   return x;
}

string totalToDebug(Total x)
{
   stringstream sout;
   sout<< "[";
   sout << x.categoria;
   sout << ",";
   sout << x.total;
   sout<< "]";
   return sout.str();
}

Total total(string categoria,double total)
{
   Total a;
   strcpy(a.categoria,categoria.c_str());
   a.total = total;
   return a;
}

bool totalEquals(Total a,Total b)
{
   if(a.total!=b.total) return false;
   return true;
}

string finalToString(Final x)
{
   char sep = 2;
   string sTotalColl=collToString<Total>(x.totalColl);
   string sFinal=to_string(x.final);
   return sTotalColl+sep+sFinal;
}

Final finalFromString(string s)
{
   char sep = 2;
   Final x;
   string t0 = getTokenAt(s,sep,0);
   x.totalColl=collFromString<Total>(t0);
   string t1 = getTokenAt(s,sep,1);
   x.final=stod(t1);
   return x;
}

string finalToDebug(Final x)
{
   stringstream sout;
   sout<< "[";
   collReset<Total>(x.totalColl);
   while(collHasNext<Total>(x.totalColl))
   {
      Total q = collNext<Total>(x.totalColl,totalFromString);
      sout << totalToDebug(q);
   }
   sout << ",";
   sout << x.final;
   sout<< "]";
   return sout.str();
}

Final final(Coll<Total> totalColl,double final)
{
   Final a;
   a.totalColl = totalColl;
   a.final = final;
   return a;
}

bool finalEquals(Final a,Final b)
{
   if(collToString<Total>(a.totalColl)!=collToString<Total>(b.totalColl)) return false;
   if(a.final!=b.final) return false;
   return true;
}


