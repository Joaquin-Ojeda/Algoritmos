#ifndef _TLIST_TAD_
#define _TLIST_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template <typename T>
struct List
{
   Node<T>* p;
   Node<T>* q;
   Node<T>* aux;
};

template <typename T>
List<T> list()
{
   List<T> f;
   f.p = NULL;
   f.q = NULL;
   f.aux = f.p;
   return f;
}

template <typename T>
T* listAdd(List<T>& lst, T v)
{
   enqueue<T>(lst.p,lst.q,v);
   lst.aux = lst.p;
   return &lst.q->info;
}

template <typename T>
T* listAddFirst(List<T>& lst, T v)
{
   T* f=NULL;
   insertFirst<T>(lst.p,v);
   return f;
}

template <typename T, typename K>
T listRemove(List<T>& lst, K k, int cmpTK(T, K))
{
   T t = remove<T, K>(lst.p,k,cmpTK);
   lst.aux = lst.p;
   return t;
}

template <typename T, typename K>
T* listFind(List<T> lst, K k, int cmpTK(T, K))
{
   T* t = &find<T, K>(lst.p,k,cmpTK)->info;
   return t;
}

template <typename T>
T* listOrderedInsert(List<T>& lst, T t, int cmpTT(T, T))
{
   T* f = &orderedInsert<T>(lst.p,t,cmpTT)->info;
   lst.aux = lst.p;
   return f;
}

template <typename T>
void listSort(List<T>& lst, int cmpTT(T, T))
{
   sort<T>(lst.p,cmpTT);
   lst.aux = lst.p;
}

template <typename T>
bool listIsEmpty(List<T> lst)
{
   return lst.p==NULL;
}

template <typename T>
int listSize(List<T> lst)
{
   Node<T>* aux = lst.p;
   int x = 0;
   while( aux!=NULL )
   {
      aux = aux->sig;
      x++;
   }
   return x;

}

template <typename T>
bool listHasNext(List<T>& lst)
{

   return lst.aux!=NULL;
}

template <typename T>
T* listNext(List<T>& lst)
{
   T* f = &lst.aux->info;
   lst.aux = lst.aux->sig;
   return f;
}

template <typename T>
void listReset(List<T>& lst)
{
   lst.aux = lst.p;
}

template <typename T>
void listFree(List<T>& lst)
{
   free<T>(lst.p);
}

template <typename T>
T listRemoveFirst(List<T>& lst)
{
   T a = removeFirst<T>(lst.p);
   return a;
}
#endif
