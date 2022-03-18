#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template <typename T>
struct Queue
{
   Node<T>* p;
   Node<T>* q;
};

template <typename T>
Queue<T> queue()
{
   Queue<T> f;
   f.p = NULL;
   f.q = NULL;
   return f;
}

template <typename T>
T* queueEnqueue(Queue<T>& q, T v)
{
   T* f = &enqueue<T>(q.q,v)->info;
   return f;
}

template <typename T>
T queueDequeue(Queue<T>& q)
{
   T t = dequeue<T>(q.q);
   return t;
}

template <typename T>
bool queueIsEmpty(Queue<T> q)
{

   return q.q==NULL;
}

template <typename T>
int queueSize(Queue<T> q)
{
   Node<T>* aux = q.q->sig;
   int x = 1;
   while( aux!=q.q )
   {
      aux = aux->sig;
      x++;
   }
   return x;
}

#endif
