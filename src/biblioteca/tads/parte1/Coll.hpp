#ifndef _TCOLL_T_
#define _TCOLL_T_

#include <iostream>
#include "../../funciones/strings.hpp"

using namespace std;



template<typename T>
struct Coll
{

   string s;
   char sep;
   int pos;
};

template<typename T>
Coll<T> coll(char sep)
{
   string s;
   int numero=0;

   Coll<T> c={s,sep,numero};





   return c;
}

template<typename T>
Coll<T> coll()
{
   char sep='|';
   string s;
   int numero=0;
   Coll<T> c={s,sep,numero};



   return c;
}

template<typename T>
int collSize(Coll<T> c)
{
   int nuevo=tokenCount(c.s,c.sep);


   return nuevo;

}

template<typename T>
void collRemoveAll(Coll<T>& c)
{
   string vacio;
   c.s=vacio;

}

template<typename T>
void collRemoveAt(Coll<T>& c, int p)
{
   removeTokenAt(c.s,c.sep, p);


}

template<typename T>
int collAdd(Coll<T>& c,T t,string tToString(T))
{
   string nuevo=tToString(t);

   addToken(c.s,c.sep,nuevo);
   //hasta aca podemos agregar el token.
   int longitud=collSize(c);
   longitud--;
   return longitud;
}

//da error esta y n oise porque ,jkuinto con la de set tokenat.

template <typename T>
void collSetAt(Coll<T>& c,T t,int p,string tToString(T))
{
   string nuevo=tToString(t);
   setTokenAt(c.s,c.sep, nuevo,p);


}

template <typename T>
T collGetAt(Coll<T> c,int p,T tFromString(string))
{
   string nuevo=getTokenAt(c.s,c.sep,p);

   T t=tFromString(nuevo);


   return t;
}//Si le ponemos un numero directo a p , no te deja,pero si lo pones en variable si??
//no seporque pasa eso asi que solo lo aclaro.

template <typename T, typename K>
int collFind(Coll<T> c,K k,int cmpTK(T,K),T tFromString(string))
{
   string eAgarrado;
   T generico1;
   int posicion=-1;
   for(int i=0;i<collSize<T>(c);i++)
   {


      eAgarrado=getTokenAt(c.s,c.sep,i);
      generico1=tFromString(eAgarrado);
      if(cmpTK(generico1,k)==0)
      {
         posicion=i;
         break;
      }
   }





   return posicion;
}

template <typename T>//mayormente elorden es de menor a mayor(equipo1.dni-equipo2.dni)
void collSort(Coll<T>& c,int cmpTT(T,T),T tFromString(string),string tToString(T))
{
   int pCero=0;
   int pUno=1;
   T aElem=collGetAt<T>(c,pCero,tFromString);
   T pElem=collGetAt<T>(c,pUno,tFromString);
   int iteraciones=0;
   int j;
   int i=1;

   while(i<=collSize<T>(c))
   {
      j=i;
      aElem=collGetAt<T>(c,i-1,tFromString);
      pElem=collGetAt<T>(c,j,tFromString);


      if(cmpTT(aElem,pElem)>0)
      {



         collSetAt(c,aElem,i,tToString);
         collSetAt(c,pElem,j-1,tToString);
         i++;

      }
      else if(cmpTT(aElem,pElem)<=0)
      {

         i++;

      }
      if(i==collSize<T>(c))
      {
         iteraciones++;
         i=1;
         if(iteraciones==collSize<T>(c))
         {
            break;
         }
      }

   }
}



template<typename T>
bool collHasNext(Coll<T> c)
{



   return collSize<T>(c)>c.pos;
}




template<typename T>
T collNext(Coll<T>& c,T tFromString(string))
{

   return collGetAt<T>(c,c.pos++,tFromString);
}

template<typename T>
T collNext(Coll<T>& c,bool& endOfColl,T tFromString(string))
{
   if(c.pos>=collSize<T> (c) )
   {
      endOfColl=true;
   }
   else
   {
      endOfColl=false;
   }

   T t=collGetAt<T>(c,c.pos++,tFromString);




     return t;
}

template<typename T>
void collReset(Coll<T>& c)
{
   c.pos=0;
}

template<typename T>
string collToString(Coll<T> c)
{
   return c.sep+c.s;
}

template<typename T>
Coll<T> collFromString(string s)
{
   Coll<T> c;
   c.sep=s[0];
   c.s=substring(s,1);
   return c;
}




#endif
