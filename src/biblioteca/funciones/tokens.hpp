#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s,char sep)
{
   int contador=charCount(s,sep);
   int posicion;
   int longitud=length(s)-1;
   bool pregunta=false;
   int contadorpregunta=0;

   if(s!="")
   {
   for(int i=0;s[i]!='\0';i++)
   {
      if(s[i]==sep)
      {
      posicion=i;
      if(pregunta==true)
      {
         contador--;
      }
      pregunta=true;;

      }
      else if(s[i]!=sep)
      {
         pregunta=false;
         contadorpregunta++;
      }

   }

   if(posicion!=longitud)
   {
      contador++;

   }


   if(contador==0)
   {
   contador++;

   }
   if(contadorpregunta==0)
   {
      contador=0;
   }

   }

   else
   {
   contador=0;
   }




   return contador;
}
// lafuncion de arriba va a dar un valor raro si ponemos por ejemlo"raul|tito||"
//  Lo perffeccione para que de 2 , y tambien por ejemmplo  string nuevo="||||||"
// aca va a dar 0 tambien,a la api no especificaaba nada asi que lo hice a libre
// interpretacion.
void addToken(string& s,char sep,string t)
{

   if(tokenCount(s,sep)!=0)
   {
      s=s+sep;
      s+=t;


   }

   else
   {
      s+=t;
   }







}

string getTokenAt(string s,char sep, int i)
{
   int valor=0;
   int f=0;
   //CREO QUE ES ACA EL� PROBLEMA
   string nuevo;
   if(tokenCount(s,sep)-1>=i)
   {


      if(tokenCount(s,sep)!=0)
      {

        for(f=0;s[f]!='\0';f++)
        {

         if(s[f]==sep)
         {
            valor++;


            if(valor>i)
            {
               break;
            }

         }
         if(valor==i && s[f]!=sep)
         {
            nuevo+=s[f];

         }
        }




      }
    else
    {
      nuevo+=s;
    }

}





   return nuevo;
}

void removeTokenAt(string& s,char sep, int i)
{
   string nuevo;
   int numeroTokens=0;
   int posicion=0;
   if(tokenCount(s,sep)-1>=i)
   {
      if(i==0)
      {
         for(int f=0;s[f]!='\0';f++)
         {
            if(s[f]==sep)
            {
               posicion=f;
               break;
            }


         }
         s=substring(s,posicion+1);

      }
      else
      {

      for(int f=0;s[f]!='\0';f++)
      {
         if(s[f]==sep)
         {
            numeroTokens++;

         }

         if(numeroTokens!=i)
         {
            nuevo+=s[f];

         }

      }

      s=nuevo;

      }
      }

}

void setTokenAt(string& s,char sep, string t,int i)
{

   string s1;
   string s2;
   int numerosep=0;
   int posicionInicial;
   int posicionFinal;


   if(i==0 && tokenCount(s,sep)==1)
   {
      s=t;
   }
   else
   {


      if(tokenCount(s,sep)-1==i)
      {
      removeTokenAt(s,sep,i);
      addToken(s,sep,t);
      }

      else
      {
          for(int f=0;s[f]!='\0';f++)
          {

             if(s[f]==sep)
             {
                numerosep++;
                if(numerosep==i)
                {
                   posicionInicial=f;
                }
                else if(numerosep==i+1)
                {
                   posicionFinal=f;
                   break;
                }
             }

          }

          if(i==0)
          {
             s2=substring(s,posicionFinal,length(s));
             s=t+s2;
          }
          else
          {

          s1=substring(s,0,posicionInicial+1);
          s2=substring(s,posicionFinal,length(s));
          s=s1+t+s2;
          }
      }



   }

}

int findToken(string s,char sep, string t)
{
   int valor=indexOf(s,t);
   int numeroTokens=0;
   if(valor>=0){

   for(int i=0;s[i]!='\0';i++)
   {
      if(s[i]==sep)
      {
         numeroTokens++;
      }
      if(valor==i)
      {
         break;
      }
   }
   }
   else
   {
      numeroTokens=-1;
   }


   return numeroTokens;
}

#endif

