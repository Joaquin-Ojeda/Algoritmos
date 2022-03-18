#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Stack
{
};

template<typename T>
Stack<T> stack()
{
   return {};
}

template<typename T>
void stackPush(Stack<T>& st,T v)
{
}

template<typename T>
T stackPop(Stack<T>& st)
{
   T t;
   return t;
}

template<typename T>
bool stackIsEmpty(Stack<T> st)
{
   return false;
}

template<typename T>
int stackSize(Stack<T> s)
{
   return 0;
}

#endif
