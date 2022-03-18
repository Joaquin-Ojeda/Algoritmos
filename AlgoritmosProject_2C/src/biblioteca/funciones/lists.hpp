#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T> struct Node
{
   T info;
   Node<T>* sig;
};

template <typename T> Node<T>* add(Node<T>*& p, T x)
{
   Node<T>* aux = p;
   Node<T>* nuevo = new Node<T>();
   nuevo->info = x;
   nuevo->sig = NULL;
   if( p!=NULL )
   {
      while( aux->sig!=NULL )
      {
         aux = aux->sig;
      }
      aux->sig = nuevo;
   }
   else
   {
      p = nuevo;
   }
   return nuevo;
}
template <typename T>
Node<T>* addFirst(Node<T>*& p, T e)
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   nuevo->sig = p;
   p = nuevo;
   return p;
}

template <typename T>
void free(Node<T>*& p)
{
   while( p!=NULL )
   {
      Node<T>* aux = p->sig;
      delete p;
      p = aux;
   }
}

template <typename T, typename K>
Node<T>* find(Node<T>* p, K v, int cmpTK(T, K))
{
   Node<T>* aux = p;
   if( aux!=NULL )
   {
      while( aux->sig!=NULL and cmpTK(aux->info,v)!=0 )
      {
         aux = aux->sig;
      }
      if( cmpTK(aux->info,v)!=0 )
      {
         aux = NULL;
      }
   }
   return aux;
}

template <typename T, typename K>
T remove(Node<T>*& p, K v, int cmpTK(T, K))
{
   Node<T>* aux = p;
   Node<T>* ant = NULL;

   while( aux!=NULL and cmpTK(aux->info,v)!=0 )
   {
      ant = aux;
      aux = aux->sig;
   }
   if( ant==NULL )
   {
      p = aux->sig;
   }
   else
   {
      ant->sig = aux->sig;
   }
   T x = aux->info;
   delete aux;
   return x;
}

template <typename T>
T removeFirst(Node<T>*& p)
{
   T t = p->info;
   Node<T>* aux = p;
   p = aux->sig;
   delete aux;
   return t;
}

template <typename T>
void insertFirst(Node<T>*& p, T v)
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = v;
   nuevo->sig = p;
   p = nuevo;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p, T v, int cmpTT(T, T))
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = v;
   Node<T>* ant = NULL;
   Node<T>* aux = p;
   while( aux!=NULL and cmpTT(aux->info,v)<0 )
   {
      ant = aux;
      aux = aux->sig;
   }
   if( ant==NULL )
   {
      nuevo->sig = p;
      p = nuevo;
   }
   else
   {
      ant->sig = nuevo;
      if( aux==NULL )
      {
         nuevo->sig = NULL;
      }
      else
      {
         nuevo->sig = aux;
      }
   }

   return nuevo;
}

template <typename T>
void sort(Node<T>*& p, int cmpTT(T, T))
{
   Node<T>* x = NULL;
   while( p!=NULL )
   {
      orderedInsert<T>(x,p->info,cmpTT);
      removeFirst<T>(p);
   }
   p = x;
}
template <typename T>
Node<T>* searchAndInsert(Node<T>*& p, T e, bool& enc, int cmpTT(T, T))
{
   Node<T>* x = find<T>(p,e,cmpTT);
   enc = true;
   if( x==NULL )
   {
      x = orderedInsert<T>(p,e,cmpTT);
      enc = false;
   }

   return x;
}
template <typename T>
bool isEmpty(Node<T>* p)
{
   bool x;
   if( p!=NULL )
   {
      x = false;
   }
   else
   {
      x = true;
   }
   return x;
}

template <typename T>
Node<T>* push(Node<T>*& p, T v)
{
   return addFirst<T>(p,v);
}

template <typename T>
T pop(Node<T>*& p)
{
   T t = removeFirst<T>(p);
   return t;
}

template <typename T>
void enqueue(Node<T>*& p, Node<T>*& q, T v)
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = v;
   nuevo->sig = NULL;
   if( q!=NULL )
   {
      q->sig = nuevo;

   }
   else
   {
      p = nuevo;
   }
   q = nuevo;
}

template <typename T>
Node<T>* enqueue(Node<T>*& q, T e)
{
   Node<T>* nuevo = new Node<T>();
   nuevo->info = e;
   if( q!=NULL )
   {
      nuevo->sig = q->sig;
      q->sig = nuevo;
   }
   else
   {
      nuevo->sig=nuevo;
   }
   q = nuevo;
   return q;
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   T t = removeFirst<T>(p);
   if( p==NULL )
   {
      q = NULL;
   }
   return t;
}

template <typename T>
T dequeue(Node<T>*& q)
{
   Node<T>* aux=q->sig;
   q->sig=aux->sig;
   T t=aux->info;
   if(aux==q)
   {
      q=NULL;
   }
   delete aux;
   return t;
}



#endif
