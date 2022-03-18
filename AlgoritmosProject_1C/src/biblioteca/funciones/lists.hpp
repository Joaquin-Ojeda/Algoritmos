#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T> struct Node
{
};

template <typename T> Node<T>* add(Node<T>*& p, T x)
{
   return NULL;
}

template <typename T> void free(Node<T>*& p)
{
}

template <typename T, typename K>
Node<T>* find(Node<T>* p, K v, int cmpTK(T,K) )
{
   return NULL;
}

template <typename T, typename K>
void remove(Node<T>*& p, K v, int cmpTK(T,K))
{
}

template <typename T>
T removeFirst(Node<T>*& p)
{
   T t;
   return t;
}

template <typename T>
void insertFirst(Node<T>*& p, T v)
{
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p, T v, int cmpTT(T,T) )
{
   return NULL;
}

template <typename T>
void sort(Node<T>*& p, int cmpTT(T,T))
{
}

template <typename T> bool isEmpty(Node<T>* p)
{
   return false;
}

template <typename T> void push(Node<T>*& p, T v)
{
}

template <typename T> T pop(Node<T>*& p)
{
   T t;
   return t;
}

template <typename T>
void enqueue(Node<T>*& p, Node<T>*& q, T v)
{
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   T t;
   return t;
}

#endif
