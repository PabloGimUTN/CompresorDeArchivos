#ifndef _TARR_TAD_
#define _TARR_TAD_

#include <iostream>
#include <stdlib.h>
#include "../../funciones/arrays.hpp"

using namespace std;
//el contador apuntar al siguiente espacio,
template<typename T>
struct Array
{
   T* a;
   int len;
   int capacidad=100;
};

template<typename T>
Array<T> array()
{

   Array<T> ret;
   ret.a=new T[ret.capacidad];
   ret.len=0;

   return ret;
}

template<typename T>
int arrayAdd(Array<T>& a,T t)
{
   Array<T> nuevoArray=array<T>();
   if(a.len==a.capacidad)
   {
      a.capacidad=a.capacidad*2;
      nuevoArray.a=new T[a.capacidad];
      nuevoArray.capacidad=a.capacidad;

      for(int i=0;i<a.len;i++)
      {

        add<T>(nuevoArray.a,nuevoArray.len,a.a[i]);

      }
//borrar el anterior
      delete[] a.a;
      a=nuevoArray;

   }

   int retorno=add<T>(a.a,a.len,t);



   return retorno;
}

template<typename T>
T* arrayGet(Array<T> a,int p)
{
   T* ret;

   for(int i=0;i<a.len;i++)
   {

      if(p==i)
      {
         ret=&a.a[i];
         break;
      }

   }


   return ret;
}

template<typename T>
void arraySet(Array<T>& a,int p,T t)
{
   T* valorCambiar=arrayGet<T>(a,p);
   *valorCambiar=t;


}

template<typename T>
void arrayInsert(Array<T>& a,T t,int p)
{
   insert<T>(a.a,a.len,t,p);

}

template<typename T>
int arraySize(Array<T> a)
{


   return a.len;
}

template<typename T>
T arrayRemove(Array<T>& a,int p)
{
  T ret= remove<T>(a.a,a.len,p);


   return ret;
}

template<typename T>
void arrayRemoveAll(Array<T>& a)
{
   a.len=0;
}

template<typename T,typename K>
int arrayFind(Array<T> a,K k,int cmpTK(T,K))
{
   return find<T,K>(a.a,a.len,k,cmpTK);
}

template<typename T>
int arrayOrderedInsert(Array<T>& a,T t,int cmpTT(T,T))
{

   return orderedInsert<T>(a.a,a.len,t,cmpTT);

}

template<typename T>
T* arrayDiscover(Array<T>& a,T t,int cmpTT(T,T))
{
   int p=arrayFind<T,T>(a,t,cmpTT);
   T* ret;
   if(p<0)
   {
      int nuevaPosAgregada=arrayAdd<T>(a,t);
      ret=arrayGet<T>(a,nuevaPosAgregada);

   }
   else if(p>=0)
   {
      ret=arrayGet<T>(a,p);

   }


   return ret;
}


template<typename T>
void arraySort(Array<T>& a,int cmpTT(T,T))
{
   sort<T>(a.a,a.len,cmpTT);

}

#endif
