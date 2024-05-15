#ifndef _TLIST_T_
#define _TLIST_T_

#include <iostream>
#include <stdio.h>

template <typename T>
struct Node
{
   T info;
   Node<T>* sig;
};

template <typename T>
Node<T>* add(Node<T>*& p,T e)
{

   Node<T>* ret;

   Node<T>* nuevo=new Node<T>();
   nuevo->info=e;
   nuevo->sig=NULL;

   Node<T>* aux=p;

   if(p==NULL)
   {
      p=nuevo;
   }
   else
   {
      while(aux->sig != NULL)
      {
         aux=aux->sig;
      }
      aux->sig=nuevo;

   }

   ret=nuevo;



   return ret;
}

template <typename T>
Node<T>* addFirst(Node<T>*& p,T e)
{

   Node<T>* nuevo=new Node<T>();
   nuevo->info=e;


   if(p==NULL)
   {

      nuevo->sig=NULL;
      p=nuevo;
   }
   else
   {
      Node<T>* aux;
      aux=p;
      nuevo->sig=aux;
      p=nuevo;

   }




   return nuevo;
}

template <typename T, typename K>
T remove(Node<T>*& p,K k,int cmpTK(T,K))
{

   Node<T>* aux=p;
   Node<T>* ant=NULL;
   T ret;
   while(aux!=NULL && cmpTK(aux->info,k)!=0)
   {
      ant=aux;
      aux=aux->sig;

   }
   if(ant==NULL)
   {
      p=aux->sig;
   }
   else
   {
      ant->sig=aux->sig;
   }
   ret=aux->info;
   delete aux;

   return ret;
}

template <typename T>
T removeFirst(Node<T>*& p)
{
   T t;
   Node<T>* aux=p;
   p=p->sig;
   t=aux->info;
   delete aux;

   return t;
}

template <typename T, typename K>
Node<T>* find(Node<T>* p,K k,int cmpTK(T,K))
{
   Node<T>* aux=p;
   while(aux!=NULL && cmpTK(aux->info,k)!=0)
   {

      aux=aux->sig;
   }



   return aux;
}

template <typename T>
Node<T>* orderedInsert(Node<T>*& p,T e,int cmpTT(T,T))
{
   Node<T>* aux=p;
   Node<T>* ant=NULL;
   Node<T>* nuevo=new Node<T>();
   nuevo->info=e;
   nuevo->sig=NULL;

   while(aux!=NULL && cmpTT(aux->info,e)<=0)
   {
      ant=aux;
      aux=aux->sig;
   }
   if(ant==NULL)
   {
      //si p ya contenia algo entonces hacemos intercambio
      //si no le ponemos el nuevo y ya esta
      if(p!=NULL)
      {
         nuevo->sig=aux;
         p=nuevo;

      }
      else
      {

       p=nuevo;

      }
   }
   else
   {
      if(aux!=NULL)
      {
         nuevo->sig=aux;
         ant->sig=nuevo;
      }
      else
      {
         //ponemos el nuevo elemento a lo ultimo
         ant->sig=nuevo;
      }
   }

   return nuevo;
}

template <typename T>
Node<T>* searchAndInsert(Node<T>*& p,T e,bool& enc,int cmpTT(T,T))
{
   Node<T>* encontrado=find<T,T>(p,e,cmpTT);
   if(encontrado!=NULL)
   {
      enc=true;
   }
   else
   {
      enc=false;
      encontrado=orderedInsert<T>(p,e,cmpTT);
   }

   return encontrado;
}
template <typename T>
void _ordenamosPares(Node<T>*& ant,Node<T>*& aux,int cmpTT(T,T))
{
   T valorAnterior=ant->info;
   T valorPosterior=aux->info;

   if(cmpTT(valorAnterior,valorPosterior)>0)
   {
      ant->info=valorPosterior;
      aux->info=valorAnterior;

   }

}

template <typename T>
int _sizeNode(Node<T>* p)
{
  Node<T>* aux=p;
  int contador=0;
  while(aux!=NULL)
  {
     contador++;

     aux=aux->sig;
  }


return contador;
}



template <typename T>
void sort(Node<T>*& p,int cmpTT(T,T))
{
   int s=_sizeNode(p);
   Node<T>* ant=NULL;
   Node<T>* aux=p;

   for(int i=0;i<s;i++)
   {
      while(aux!=NULL)
        {
           if(ant!=NULL)
           {
              _ordenamosPares(ant,aux,cmpTT);
           }
           ant=aux;
           aux=aux->sig;
        }
      aux=p;
      ant=NULL;
   }

}

// cuando el nodo tiene elementos entonces no esta vacia
//por eso vacia=false, ya que no esta vacia.
template <typename T>
bool isEmpty(Node<T>* p)
{
   bool vacia;
   if(p!=NULL)
   {
      vacia=false;
   }
   else
   {
      vacia=true;
   }
   return vacia;
}

template <typename T>
void free(Node<T>*& p)
{

   p=NULL;

}

template <typename T>
Node<T>* push(Node<T>*& p,T e)
{
   return addFirst<T>(p,e);
}

template <typename T>
T pop(Node<T>*& p)
{
   return removeFirst<T>(p);
}

template <typename T>
Node<T>* enqueue(Node<T>*& p,Node<T>*& q,T e)
{
   Node<T>* nuevo=new Node<T>();
   nuevo->info=e;
   nuevo->sig=NULL;
   if(q!=NULL)
   {
      q->sig=nuevo;
   }
   else
   {
      p=nuevo;
   }
   q=nuevo;



   return nuevo;
}

template <typename T>
Node<T>* enqueue(Node<T>*& q,T e)
{
   Node<T>* nuevo=new Node<T>();
   nuevo->info=e;
   if(q!=NULL)
   {
      nuevo->sig=q->sig;
      q->sig=nuevo;
   }
   else
   {
      nuevo->sig=nuevo;
   }
   q=nuevo;



   return nuevo;
}

template <typename T>
T dequeue(Node<T>*& p, Node<T>*& q)
{
   T t=p->info;
   Node<T>* aux=p;
   p=p->sig;
   delete aux;

   if(p==NULL)
   {
      q=NULL;
   }



   return t;
}

template <typename T>
T dequeue(Node<T>*& q)
{

   Node<T>* aux=q->sig;
   q->sig=aux->sig;
   T ret=aux->info;

   if(aux==q)
   {
      q=NULL;
   }
   delete aux;
   return ret;
}

#endif
