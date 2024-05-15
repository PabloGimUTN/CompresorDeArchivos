#ifndef _TARRAYS_T_
#define _TARRAYS_T_

#include <iostream>

template <typename T>
int add(T arr[],int& len,T e)
{
   arr[len]=e;
   len++;
   return len-1;
}

template <typename T>
void insert(T arr[],int& len,T e,int p)
{
   len++;

   if(len-1>0)
   {
   for(int i=len-1;i>p;i--)
     {
        arr[i]=arr[i-1];

     }
     arr[p]=e;

   }
   else if(len-1==0)
   {
      arr[p]=e;
   }



}


template <typename T>
T remove(T arr[],int& len,int p)
{
   T ret;
   len--;
   if(len!=p)
   {
      for(int i=p;i<len;i++)
      {

         if(i==p)
         {
           ret=arr[i];
         }

         arr[i]=arr[i+1];
      }
   }
   else if(len==p)
   {
      ret=arr[p];
   }



   return ret;
}

template <typename T, typename K>
int find(T arr[],int len,K k,int cmpTK(T,K))
{
   int posicion=-1;

   for(int i=0;i<len;i++)
   {
      if(cmpTK(arr[i],k)==0)
      {
         posicion=i;
         break;
      }



   }



   return posicion;
}

template <typename T>
int orderedInsert(T arr[],int& len,T e,int cmpTT(T,T))
{
   int posicion=-1;


   for(int i=0;i<len;i++)
   {

      if(cmpTT(arr[i],e)>0)
      {

      insert<T>(arr,len,e,i);
      posicion=i;
      break;

      }


   }

   if(posicion==-1)
   {
      posicion=add<T>(arr,len,e);
   }




   return posicion;
}

template <typename T>
void sort(T arr[],int len,int cmpTT(T,T))
{
   T valormedio;

   for(int j=0;j<len;j++)
   {

      for(int i=0;i<len;i++)
      {


            if(cmpTT(arr[i],arr[i+1])>0 && (i+1)!=len)
            {
               valormedio=arr[i];
               arr[i]=arr[i+1];
               arr[i+1]=valormedio;
            }
      }

   }







   return;
}



#endif

