#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>
#include "../../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Queue
{
   Node<T>* p;
   Node<T>* q;
};

template<typename T>
Queue<T> queue()
{
   Queue<T> q;
   q.q=NULL;
   q.p=NULL;
   return q;
}

template<typename T>
T* queueEnqueue(Queue<T>& q,T e)
{
   Node<T>* nuevo=enqueue<T>(q.p,q.q,e);
   T* ret=&nuevo->info;


   return ret;
}

template<typename T>
T queueDequeue(Queue<T>& q)
{
   return dequeue<T>(q.p, q.q);
}

template<typename T>
bool queueIsEmpty(Queue<T> q)
{
   return isEmpty<T>(q.p);
}

template<typename T>
int queueSize(Queue<T> q)
{
   return _sizeNode<T>(q.p);
}

#endif
