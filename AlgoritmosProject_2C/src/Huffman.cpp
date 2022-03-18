#ifndef _MAIN
#define _MAIN

#include <iostream>
#include <stdio.h>
#include "biblioteca/tads/Arr.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/HuffmanTree.hpp"
#include "biblioteca/tads/BitWriter.hpp"
#include "biblioteca/tads/BitReader.hpp"
#include "Progress.hpp"

using namespace std;
bool sacarPorcentaje(int porcentaje, unsigned int cantidad, unsigned int total)
{
   bool a;
   unsigned int b = porcentaje*(total/100);
   if( b==cantidad )
   {
      a = true;
   }
   else
   {
      a = false;
   }
   return a;
}

struct HuffmanTable
{
   unsigned int n;
   string code;
};
int cmp(HuffmanTreeInfo a, HuffmanTreeInfo b)
{
   //primero comparo por cantidad de ocurrencias, sino los comparo por los caracteres.
   return (a.n-b.n)==0?(a.c-b.c)==0?-1:a.c-b.c:a.n-b.n;
}

//COMPRIMIR

void contarOcurrencias(string fName, HuffmanTable tabla[])
{
   //cuando le paso el string a fopen salta error por lo que tuve que crear un array de char para que lo tome.
   char fNew[100] = "";
   for( int i = 0; i<length(fName); i++ )
   {
      fNew[i] = fName[i];
   }

   //paso extra para limpiar el array ya que quedaban residuos en n.
   for( int i = 0; i<256; i++ )
   {
      tabla[i].n = 0;
   }

   //abrimos el archivo y empezamos a recorrerlo y contar ocurrencias.
   FILE* f = fopen(fNew,"r+b");

   int c = read<unsigned char>(f);
   while( !feof(f) )
   {
      tabla[c].n = tabla[c].n+1;
      c = read<unsigned char>(f);
   }
   fclose(f);
}

void crearLista(List<HuffmanTreeInfo>& lista, HuffmanTable tabla[])
{
   for( int i = 0; i<256; i++ )
   {
      if( tabla[i].n>0 )
      {
         HuffmanTreeInfo* x = huffmanTreeInfo(i,tabla[i].n,NULL,NULL);
         listOrderedInsert<HuffmanTreeInfo>(lista,*x,cmp);
      }
   }

}

HuffmanTreeInfo* crearArbol(List<HuffmanTreeInfo>& lista)
{
   int a = 256;
   HuffmanTreeInfo* nuevo = huffmanTreeInfo(a,0,NULL,NULL);
   HuffmanTreeInfo* aux = huffmanTreeInfo(0,0,NULL,NULL);
   HuffmanTreeInfo t;
   //si la lista tiene mas que 1 elemento entramos al while, cuando solo tenga 1 ahi tendremos nuestra raiz.
   while( listSize<HuffmanTreeInfo>(lista)>1 )
   {
      //removemos el primer elemento y lo guardamos en el hijo derecho.
      //y reinciamos las variables usadas ya que sino va a dar errores.
      t = listRemoveFirst<HuffmanTreeInfo>(lista);
      aux = huffmanTreeInfo(t.c,t.n,t.right,t.left);
      nuevo->right = aux;
      nuevo->n = nuevo->n+t.n;
      aux = huffmanTreeInfo(0,0,NULL,NULL);

      //lo mismo con el segundo, solo que lo guardamos a la izquierda.
      t = listRemoveFirst<HuffmanTreeInfo>(lista);
      aux = huffmanTreeInfo(t.c,t.n,t.right,t.left);
      nuevo->left = aux;
      nuevo->n = nuevo->n+t.n;
      aux = huffmanTreeInfo(0,0,NULL,NULL);

      listOrderedInsert<HuffmanTreeInfo>(lista,*nuevo,cmp);

      //incrementamos al contador y reiniciamos el nuevo para que no tire errores.
      a++;
      nuevo = huffmanTreeInfo(a,0,NULL,NULL);

   }

   HuffmanTreeInfo* raiz = listNext<HuffmanTreeInfo>(lista);

   return raiz;
}

void cargarCodigosEnTabla(HuffmanTreeInfo* raiz, HuffmanTable tabla[])
{
   // recorremos el arbol usando TAD HuffmanTree
   HuffmanTree ht = huffmanTree(raiz);
   string cod;
   // iteramos mientras queden hojas por visitar
   while( huffmanTreeHasNext(ht) )
   {
      // obtenemos un puntero a la proxima hoja
      HuffmanTreeInfo* x = huffmanTreeNext(ht,cod);

      // mostramos por pantalla lo que obtuvimos
      cout<<(char)x->c<<", ("<<x->n<<"),"<<"["<<length(cod)<<"]"<<endl;
      //metemos los code en la tabla
      tabla[x->c].code = cod;
   }
   cout<<"Arbol construido"<<endl;

}

void grabarArchivoComprimido(string fName, HuffmanTable tabla[])
{
   //primero pasamos el string a un char array para que fopen lo tome.
   char fNam[500] = "";
   for( int i = 0; i<length(fName); i++ )
   {
      fNam[i] = fName[i];
   }
   FILE* g = fopen(fNam,"r+b");

   //lo mismo que antes pero a fName le agregamos el ".huf" para el nuevo archivo.
   fName += ".huf";
   char fNew[500] = "";
   for( int i = 0; i<length(fName); i++ )
   {
      fNew[i] = fName[i];
   }

   //cuento la cantidad de hojas.
   int a = 0;
   for( int i = 0; i<256; i++ )
   {
      if( tabla[i].n>0 )
      {
         a++;
      }
   }
   FILE* f = fopen(fNew,"w+b");
   //guardo el primer byte que representa la cantidad de hojas.
   write<int>(f,a);
   int cont = 0;
   int aux = 0;
   while( cont<(int)a )
   {
      //iteramos hasta encontrar el primer elemento de la tabla que tenga alguna ocurrencia.
      while( tabla[aux].n==0 )
      {
         aux++;
      }
      //guardamos el caracter.
      write<unsigned char>(f,(unsigned char)aux);

      //guardamos la longitud de su codigo.
      write<unsigned char>(f,(unsigned char)length(tabla[aux].code));

      //guardamos el codigo.
      for( int i = 0; i<length(tabla[aux].code); i++ )
      {
         write<unsigned char>(f,(unsigned char)tabla[aux].code[i]);
      }
      aux++;
      cont++;
   }

   //guardamos la longitud, en bytes, del archivo original.
   unsigned int x = 0;
   for( int i = 0; i<256; i++ )
   {
      if( tabla[i].n>0 )
      {
         x = x+tabla[i].n;
      }
   }
   write<unsigned int>(f,x);

//por ultimo guardamos la informacion.
   unsigned char car;

   BitWriter bw = bitWriterCreate(f);
   unsigned int contador = 0;
   int porcentaje = 0;
   while( !feof(g) )
   {
      car = read<unsigned char>(g);

      if( sacarPorcentaje(porcentaje,contador,x) and porcentaje<=100 )
      {
         cout<<"Grabado al "<<porcentaje<<"%"<<endl;
         porcentaje = porcentaje+10;
      }

      for( int i = 0; i<length(tabla[(int)car].code); i++ )
      {
         bitWriterWrite(bw,charToInt((char)tabla[(int)car].code[i]));
      }

      contador++;
   }
   if( porcentaje<100 )
   {
      cout<<"Grabado al 100%"<<endl;
   }
   cout<<"Se grabaron "<<contador-1<<" byte"<<endl;

   bitWriterFlush(bw);
//   progressDemo();
   fclose(g);
   fclose(f);
}

void comprimir(string fName)
{
   // paso 1
   HuffmanTable tabla[256];
   contarOcurrencias(fName,tabla);
   // paso 2
   List<HuffmanTreeInfo> lista = list<HuffmanTreeInfo>();
   crearLista(lista,tabla);
   // paso 3
   HuffmanTreeInfo* raiz = crearArbol(lista);
   // Recorro el arbol para obtener los codigos y los cargo
   // en el array de contadores, en el campo code
   cargarCodigosEnTabla(raiz,tabla);
   // Grabo el archivo comprimido
   grabarArchivoComprimido(fName,tabla);
}

//DESCOMPRIMIR

HuffmanTreeInfo* recrearArbol(string fName)
{
   char fNam[500] = "";
   for( int i = 0; i<length(fName); i++ )
   {
      fNam[i] = fName[i];
   }
   int nom = 256;
   //creamos la raiz y la inicializamos.
   HuffmanTreeInfo* raiz = huffmanTreeInfo(nom,0,NULL,NULL);

   FILE* f = fopen(fNam,"r+b");

   int cant = read<int>(f);
   unsigned char a;
   unsigned char longitud;
   for( int i = 0; i<cant; i++ )
   {
      //leemos el primer caracter.
      a = read<unsigned char>(f);

      //leemos la logitud de su codigo.
      longitud = read<unsigned char>(f);

      //leemos el codigo y dependiendo de si es 0 o 1 avanzamos en el arbol y a su vez lo creamos.
      HuffmanTreeInfo* ult = raiz;
      for( int x = 0; x<longitud; x++ )
      {
         unsigned char aux = read<unsigned char>(f);
         if( aux=='1' )
         {
            //preguntamos si se puede avanzar en el arbol o si esta vacio.
            //si esta vacio creamos una nueva rama, sino simplemente nos posicionamos en la siguiente.
            if( ult->right==NULL )
            {
               nom++;
               HuffmanTreeInfo* nuevo = huffmanTreeInfo(nom,0,NULL,NULL);
               ult->right = nuevo;
               ult = nuevo;
            }
            else
            {
               ult = ult->right;
            }
         }
         else
         {
            //lo mismo que el otro pero con el izquierdo.
            if( ult->left==NULL )
            {
               nom++;
               HuffmanTreeInfo* nuevo = huffmanTreeInfo(nom,0,NULL,NULL);
               ult->left = nuevo;
               ult = nuevo;
            }
            else
            {
               ult = ult->left;
            }
         }

      }
      //cuando salimos del for vamos a estar en la ultima hoja donde estara la letra.
      ult->c = a;
   }
   //guardo en donde se quedo el archivo en el n de la raiz ya que no se usa.
   raiz->n = filePos<unsigned char>(f);
   HuffmanTree ht = huffmanTree(raiz);
   string cod;
   while( huffmanTreeHasNext(ht) )
   {
      HuffmanTreeInfo* x = huffmanTreeNext(ht,cod);

      cout<<(char)x->c<<", " "["<<length(cod)<<"]"<<endl;
   }
   cout<<"Arbol reconstruido"<<endl;
   fclose(f);
   return raiz;
}

void leerInfo(string fName, HuffmanTreeInfo* raiz)
{
   string nuevo = substring(fName,0,length(fName)-4);
   char fN[500] = "";
   for( int i = 0; i<length(nuevo); i++ )
   {
      fN[i] = nuevo[i];
   }
   FILE* g = fopen(fN,"w+b");

   //abrimos el archivo.
   char fNam[500] = "";
   for( int i = 0; i<length(fName); i++ )
   {
      fNam[i] = fName[i];
   }
   FILE* f = fopen(fNam,"r+b");

   //Nos posicionamos luego de las 12 hojas, que guarde en la n de la raiz.
   //dicho numero sera la cantidad de bytes del archivo original.
   seek<unsigned char>(f,raiz->n);
   unsigned int cant = read<unsigned int>(f);
   cout<<cant<<" bytes para grabar"<<endl;
   //Leemos el primer byte y empezamos a iterar segun la cantidad de bytes del archivo original.
   BitReader br = bitReaderCreate(f);
   HuffmanTreeInfo* ult = raiz;
   unsigned int contador = 0;
   int porcentaje = 0;
   for( unsigned int i = 0; i<cant; i++ )
   {
      if( sacarPorcentaje(porcentaje,contador,cant) and porcentaje<=100 )
      {
         cout<<"Grabado al "<<porcentaje<<"%"<<endl;
         porcentaje = porcentaje+10;
      }

      int bit;
      //siempre que el contenido de c no sea un caracter vamos a seguir avanzando en el arbol.
      //y dependiendo del bit que se lee nos vamos a izquierda o derecha.
      while( ult->c>255 )
      {
         bit = bitReaderRead(br);
         if( bit==0 )
         {
            ult = ult->left;
         }
         else
         {
            ult = ult->right;
         }
      }
      //una vez que salimos del while quiere decir que estamos en la hoja que contiene un caracter.
      write<char>(g,ult->c);
      contador++;
      ult = raiz;
   }
   if( porcentaje<100 )
   {
      cout<<"Grabado al 100%"<<endl;
   }
   cout<<"Se grabaron "<<contador<<" byte"<<endl;

   fclose(f);
   fclose(g);
}

void descomprimir(string fName)
{

   //paso 1: Rearmamos el arbol.
   HuffmanTreeInfo* raiz = recrearArbol(fName);

   //paso 2: Leemos la informacion codificada y la guardamos en el archivo nuevo.
   leerInfo(fName,raiz);

}

// PROGRAMA PRINCIPAL
int main(int argc, char** argv)
{
   // recibo el nombre de archivo
   string fName = argv[1];
   // si no termina con ".huf" comprimo

   if( !endsWith(fName,".huf") )
   {
      comprimir(fName);
   }
   else
   {
      descomprimir(fName);
   }
   return 0;
}

#endif
