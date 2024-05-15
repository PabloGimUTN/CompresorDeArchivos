#ifndef _TLIST_TAD_
#define _TLIST_TAD_
//MIRA LOS COMENTARIOS PPRFA
#include <iostream>

#include "../../funciones/lists.hpp"
#include "../../funciones/strings.hpp"
//BUENO FIJATE QUE LA FUINCION REMOVE TIENE UN TEMPLATE "T" Y "K" ESO QUIERE DECIR QUE
//PUEDE SER QUE CUANDO LO USEMOS EN LSO PROBLEMAS DE ERROR , YA QUE PUEDE SER QUE TENGAS
//QUE BUSCAR POR VALOR "K" Y NO POR "T"
using namespace std;

template<typename T>
struct List
{
   Node<T>* p;
   int pos;

};

template<typename T>
List<T> list()
{
   List<T> lst;
   lst.p=NULL;
   lst.pos=0;


   return lst;
}

template<typename T>
T* listAdd(List<T>& lst,T e)
{

   Node<T>* s=add<T>(lst.p,e);
   T* ret=&s->info;
   return ret;
}

template<typename T>
T* listAddFirst(List<T>& lst,T e)
{
   Node<T>* s=addFirst<T>(lst.p,e);
   T* ret=&s->info;


   return ret;
}

template<typename T,typename K>
T listRemove(List<T>& lst,K k,int cmpTK(T,K))
{
   T t=remove<T>(lst.p,k,cmpTK);


   return t;
}

template<typename T>
T listRemoveFirst(List<T>& lst)
{

   T t=removeFirst<T>(lst.p);

   return t;
}

template<typename T,typename K>
T* listFind(List<T> lst,K k,int cmpTK(T,K))
{
   Node<T>* s=find<T>(lst.p,k,cmpTK);
   T* ret=&s->info;
   return ret;
}

template<typename T>
bool listIsEmpty(List<T> lst)
{
   bool vacia;
   if(lst.p!=NULL)
   {
      vacia=false;
   }
   else
   {
      vacia=true;
   }
   return vacia;
}

template<typename T>
int listSize(List<T> lst)
{

   Node<T>* aux=lst.p;
   int contador=0;
   while(aux!=NULL)
   {
     contador++;

     aux=aux->sig;
   }


   return contador;
}

template<typename T>
void listFree(List<T>& lst)
{
   lst.p=NULL;
}

template<typename T>
T* listDiscover(List<T>& lst,T t,int cmpTT(T,T))
{
   T* ret=listFind<T>(lst,t,cmpTT);

   if(ret==NULL)
   {
      ret=listAdd<T>(lst,t);
   }


   return  ret;
}

template<typename T>
T* listOrderedInsert(List<T>& lst,T t,int cmpTT(T,T))
{
   Node<T>* s=orderedInsert<T>(lst.p,t,cmpTT);
   T* ret=&s->info;


   return ret;
}

template<typename T>
void listSort(List<T>& lst,int cmpTT(T,T))
{
   sort<T>(lst.p,cmpTT);
}

template<typename T>
void listReset(List<T>& lst)
{
   lst.pos=0;

}

template<typename T>
bool listHasNext(List<T> lst)
{
   return listSize<T>(lst)>lst.pos;
}

template<typename T>
T* _listGet(List<T> lst,int pos)
{
   T* t;
   Node<T>* aux=lst.p;
   int i=0;
   while(aux!=NULL && i!=pos)
   {
      aux=aux->sig;
      i++;
   }
   if(aux!=NULL)
   {
      t=&aux->info;
   }
   else
   {
      t=NULL;
   }

   return t;
}

template<typename T>
T* listNext(List<T>& lst)
{
   return _listGet<T>(lst,lst.pos++);
}

template<typename T>
T* listNext(List<T>& lst,bool& endOfList)
{

   if(lst.pos>=listSize<T> (lst) )
     {
        endOfList=true;
     }
     else
     {
        endOfList=false;
     }
   T* ret=_listGet<T>(lst,lst.pos++);

   return ret;
}

#endif
