#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Stack
{
   Node<T>* p;
};

template<typename T>
Stack<T> stack()
{
   Stack<T> f;
   f.p=NULL;
   return f;
}

template<typename T>
T* stackPush(Stack<T>& st,T v)
{
   T* f=&push<T>(st.p,v)->info;
   return f;
}

template<typename T>
T stackPop(Stack<T>& st)
{
   T t=pop<T>(st.p);
   return t;
}

template<typename T>
bool stackIsEmpty(Stack<T> st)
{
   return st.p==NULL;
}

template<typename T>
int stackSize(Stack<T> s)
{
   Node<T>* aux = s.p;
      int x = 0;
      while( aux!=NULL )
      {
         aux = aux->sig;
         x++;
      }
      return x;
   return 0;
}

#endif
