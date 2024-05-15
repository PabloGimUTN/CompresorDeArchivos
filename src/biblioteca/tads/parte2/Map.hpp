
#ifndef _TMAP_TAD_
#define _TMAP_TAD_

#include <iostream>
#include "Array.hpp"

using namespace std;

template<typename K,typename V>
struct Map
{
   Array<K> keys;
   Array<V> values;
   int pos;

};

template<typename K,typename V>
Map<K,V> map()
{
   Map<K,V> m;
   m.keys=array<K>();
   m.values=array<V>();
   m.pos=0;

   return {m};
}
//si me da NULL va  a dar mal xd
template<typename K,typename V>
V* mapGet(Map<K,V> m,K k)
{
   int posicion;
   V* retorno;
   for(int i=0;i<arraySize<K>(m.keys);i++)
   {
      K* valorRetorno=arrayGet<K>(m.keys,i);
      if(*valorRetorno==k)
      {
         posicion=i;
         break;
      }
//hay que ver que pasa con NULL si retornamos eso

   }

   if(posicion>=0)
   {
     retorno=arrayGet<V>(m.values,posicion);
   }
   else if(posicion<0)
   {
      retorno=nullptr;
   }




   return retorno;
}

template<typename K,typename V>
V* mapPut(Map<K,V>& m,K k,V v)
{
   V* elementoRetornado;
   bool existe=false;

   for(int i=0;i<arraySize<K>(m.keys);i++)
   {
      if(k==*arrayGet<K>(m.keys,i))
      {
         //si exsite lo cambiamos eso estamos haciendo
         arraySet<V>(m.values,i,v);
         elementoRetornado=arrayGet<V>(m.values,i);
         existe=true;
         break;

      }

   }

   if(existe==false)
   {
      arrayAdd<K>(m.keys,k);
      int i=arrayAdd<V>(m.values,v);
      elementoRetornado=arrayGet<V>(m.values,i);
   }


   return elementoRetornado;
}

template<typename K,typename V>
bool mapContains(Map<K,V> m,K k)
{
   bool retornado=false;

   for(int i=0;i<arraySize<K>(m.keys);i++)
   {
      if(k==*arrayGet<K>(m.keys,i))
      {
         retornado=true;
         break;
      }


   }



   return retornado;
}

template<typename K,typename V>
V mapRemove(Map<K,V>& m,K k)
{
   int posicionBorrada;
   for(int i=0;i<arraySize<K>(m.keys);i++)
     {
        if(k==*arrayGet<K>(m.keys,i))
        {
           posicionBorrada=i;
           break;
        }


     }
   arrayRemove<K>(m.keys,posicionBorrada);
   V v=arrayRemove<V>(m.values,posicionBorrada);


   return v;
}

template<typename K,typename V>
void mapRemoveAll(Map<K,V>& m)
{
   arrayRemoveAll<K>(m.keys);
   arrayRemoveAll<V>(m.values);
}

template<typename K,typename V>
int mapSize(Map<K,V> m)
{



   return arraySize<K>(m.keys);
}

template<typename K,typename V>
bool mapHasNext(Map<K,V> m)
{

   return mapSize<K>(m)>m.pos;
}

template<typename K,typename V>
K mapNextKey(Map<K,V>& m)
{


   return *arrayGet<K>(m.keys,m.pos++);
}

template<typename K,typename V>
V* mapNextValue(Map<K,V>& m)
{
   return  arrayGet<V>(m.values,m.pos++);
}

template<typename K,typename V>
void mapReset(Map<K,V>& m)
{

   m.pos=0;
}

template<typename K,typename V>
V* mapDiscover(Map<K,V>& m,K k,V v)
{

   return mapPut<K,V>(m,k,v);
}


template<typename K,typename V>
void mapSortByKeys(Map<K,V>& m,int cmpKK(K,K))
{


   for(int j=0;j<arraySize<K>(m.keys);j++)
   {

      for(int i=0;i<arraySize<K>(m.keys);i++)
      {

         if((i+1)!=arraySize<K>(m.keys))
         {

            K* k1=arrayGet<K>(m.keys,i);
            K* k2=arrayGet<K>(m.keys,i+1);
            K valorMedio;
            if(cmpKK(*k1,*k2)>0)
            {

               V* v1=mapGet<K,V>(m,*k1);
               V* v2=mapGet<K,V>(m,*k2);
               V valorNuevoMedio;

               valorNuevoMedio=*v1;
               *v1=*v2;
               *v2=valorNuevoMedio;

               //entramos y modificamos las keys

               valorMedio=*k1;
               *k1=*k2;
               *k2=valorMedio;

            }
         }
      }
   }

}

template<typename K,typename V>
void mapSortByValues(Map<K,V>& m,int cmpVV(V,V))
{


   for(int j=0;j<arraySize<V>(m.values);j++)
   {

      for(int i=0;i<arraySize<V>(m.values);i++)
      {

         if((i+1)!=arraySize<V>(m.values))
         {

            V* v1=arrayGet<V>(m.values,i);
            V* v2=arrayGet<V>(m.values,i+1);
            V valorMedio;
            if(cmpVV(*v1,*v2)>0)
            {
               valorMedio=*v1;
               *v1=*v2;
               *v2=valorMedio;
               //entramos y modificamos las keys
               K* k1=arrayGet<K>(m.keys,i);
               K* k2=arrayGet<K>(m.keys,i+1);
               K valorMedio2;

               valorMedio2=*k1;
               *k1=*k2;
               *k2=valorMedio2;


            }
         }
      }
   }
}

#endif
