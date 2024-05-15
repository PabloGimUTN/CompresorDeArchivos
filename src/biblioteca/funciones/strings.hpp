#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s)
{
   int i=0;

  while(s[i]!='\0')
  {
     i++;
  }

   return i;
}

int charCount(string s,char c)
{
   int i=0;
   for(int j=0;s[j]!='\0';j++)
   {
      if(s[j]==c)
      {
         i++;
      }
   }

   return i;
}

string substring(string s,int d,int h)
{
   string nuevo="";


   for(int j=0;s[j]!='\0';j++)
   {
      if(j>=d && j<h)
      {
         nuevo=nuevo+s[j];
      }
   }



   return nuevo;
}

string substring(string s,int d) // ok
{
   string nuevo="";
   for(int j=0;s[j]!='\0';j++)
   {
         if(j>=d)
         {
            nuevo=nuevo+s[j];
         }
    }

   return nuevo;
}

int indexOf(string s,char c) // ok
{

   int posicion=-1;
   for(int j=0;s[j]!='\0';j++)
   {

         if(s[j]==c)
         {
            posicion=j;
            break;
         }

   }




   return posicion;
}

int indexOf(string s,char c,int offSet) // ok
{
   int posicion=-1;
   for(int j=offSet;s[j]!='\0';j++)
   {
      if(s[j]==c)
      {
         posicion=j;
         break;
      }

   }



   return posicion;
}

int indexOf(string s,string toSearch) // ok
{
   int i=0;
   int posicionInicial=0;
   for(int j=0;s[j]!='\0';j++)
   {

      if(s[j]==toSearch[i])
      {

       while(i<length(toSearch))
       {


           if(s[j+i]==toSearch[i])
           {
              i++;
           }
           else
           {

                break;
           }

       }
          if(i==length(toSearch))
          {
             posicionInicial=j;
             break;
          }

      }
   }

   if(i!=length(toSearch))
   {
      posicionInicial=-1;
   }





   return posicionInicial;
}

int indexOf(string s,string toSearch,int offset) // ok
{
      int i=0;
      int posicionInicial=0;
      for(int j=offset;s[j]!='\0';j++)
      {

         if(s[j]==toSearch[i])
         {

          while(i<length(toSearch))
          {


              if(s[j+i]==toSearch[i])
              {
                 i++;
              }

              else
              {
                 break;
              }

          }

          if(i==length(toSearch))
          {
            posicionInicial=j;
            break;
          }

         }
      }

      if(i!=length(toSearch))
      {
         posicionInicial=-1;
      }






      return posicionInicial;
}

int lastIndexOf(string s,char c)
{
   int posicion=-1;
   for(int j=0;s[j]!='\0';j++)
   {

         if(s[j]==c)
         {
            posicion=j;
         }

   }
   return posicion;
}

int indexOfN(string s,char c,int n)
{
   int posicion;
   int contador=0;
   n=n-1;

   for(int i=0;s[i]!='\0';i++)
   {
      if(s[i]==c)
      {

         if(contador==n)
         {
            posicion=i;
            break;
         }
         contador++;

      }


   }






   return posicion;
}

int charToInt(char c)
{

   if(c>='A'&& c<='Z')
   {
      c=c-55;
   }
   else if(c>='a'&& c<='z')
   {
      c=c-87;
   }
   else
   {
   c=c-48;

   }



   return c;
}

char intToChar(int i)
{
   char c;
   if(i>=10&& i<=35)
   {
       c=55+i;
   }
   else if(i>=0 && i<10)
   {
   c=i+48;

   }


   return c;
}

int getDigit(int n,int i)
{

   double s=pow(10,i);
   int x=n/(int)s;
   x=x%10;

   return x;
}

int digitCount(int n)
{
   int c=0;
   for(int i=0;n/(long)pow(10,i)>=1;i++)
   {
      c++;
   }

   return c;
}

string intToString(int i)
{
   int n=digitCount(i);

   string nuevo="";

   if(n!=0)
   {
      for(int z=n-1;z>=0;z--)
      {
         int d=getDigit(i,z);
         char c=d+48;
         nuevo+=c;
      }

   }
   else if(n==0)
   {
      nuevo="0";
   }

   return nuevo;
}

int stringtoint(string s,int b) // ok
{

   return 0;
}

int stringToInt(string s) // ok
{
   double sum=0;
   double n=length(s)-1;
   double i=0;
   for(int j=n;j>=0;j--)
   {

      if(s[j]>='0' && s[j]<='9')
      {

      sum=sum +(s[j]-48)*pow(10,i);
      i++;

      }
      else if(s[j]>='A' && s[j]<='Z')
      {
         sum=sum +(s[j]-55)*pow(10,i);
         i++;
      }
      else if(s[j]>='a' && s[j]<='z'){
         sum=sum +(s[j]-87)*pow(10,i);
         i++;
      }

   }


   return sum;
}

string charToString(char c)
{
   string nuevo="";

   nuevo+=c;


   return nuevo;
}

char stringToChar(string s)
{

   char c;
   for(int i=0;s[i]!='\0';i++)
   {
      c+=s[i];
   }

   return c;
}

string stringToString(string s)
{
   return s;
}

string doubleToString(double d)
{

   string nuevo= to_string(d);


   // me salian pero hasta 4 decimales bien,despues salia todo mal por eso opte por esto




   return nuevo;

}

double stringToDouble(string s)
{

   string nuevo;
   string nuevo2;
   bool pregunta=false;
   for(int i=0;s[i]!='\0';i++)
   {
      if(s[i]=='.' || pregunta==true)
      {

         if(s[i]!='.')
         {
         nuevo2+=s[i];

         }
        pregunta=true;
      }
      else
      {
      nuevo+=s[i];

      }

   }



   double variableEntero;
   double variable2;
   int valor;
   int valor2;
   valor=stringToInt(nuevo);
   valor2=stringToInt(nuevo2);

   variable2=valor2/(pow(10,length(nuevo2)));
   variableEntero=valor+variable2;

   return variableEntero;
}//estoy desquiciado al hacer esta funcion me salio re bien JSAJSA que pasooo

bool isEmpty(string s)
{
   bool pregunta=true;
   if(s=="")
   {
      pregunta=false;
   }


   return pregunta;
}

bool startsWith(string s,string x)
{
   bool pregunta=false;
   string nuevo=substring(s,0,length(x));

   if(nuevo==x)
   {
      pregunta=true;
   }


   return pregunta;
}

bool endsWith(string s,string x)
{
   int valorInicio=length(s)-length(x);
   string nuevo=substring(s,valorInicio,length(s)+1);
   bool pregunta=false;

   if(nuevo==x)
   {
      pregunta=true;
   }



   return pregunta;
}

bool contains(string s,char c)
{
   bool pregunta=false;
   for(int i=0;s[i]!='\0';i++)
   {
      if(s[i]==c)
      {
         pregunta=true;
         break;
      }

   }


   return pregunta;
}

string replace(string s,char oldChar,char newChar)
{
   string nueva="";
   for(int i=0;s[i]!='\0';i++)
   {

      if(oldChar==s[i])
      {
         nueva+=newChar;
      }
      else
      {
         nueva+=s[i];
      }

   }

   return nueva;
}

string insertAt(string s,int pos,char c)
{
  string nuevo;
  int limite=length(s);
  bool pregunta=false;

  for(int i=0;i<=limite;i++)
  {
     if(i==pos && pregunta==false)
     {
        nuevo+=c;
        pregunta=true;
        i--;
     }
     else if(i==limite)
     {
        break;
     }
     else
     {
        nuevo+=s[i];
     }

  }




   return nuevo;
}

string removeAt(string s,int pos)
{

   string nuevo;
   int limite=length(s);
   for(int i=0;i<limite;i++)
   {

      if(i!=pos)
      {
         nuevo+=s[i];
      }

   }


   return nuevo;
}

string ltrim(string s)
{
   string nuevo;
   int posiciondondeTermina;

   for(int i=0;s[i]!='\0';i++)
   {
      if(s[i]!=' ' )
      {
         posiciondondeTermina=i;
         break;
      }
   }

   for(int i=posiciondondeTermina;s[i]!='\0';i++)
   {

      nuevo+=s[i];

   }


   return nuevo;
}

string rtrim(string s)
{
   int i=length(s)-1;
   int Posiciondondetermina;
   string nuevo;
   for(;i>=0;i--)
   {
      if(s[i]!=' ')
      {
         Posiciondondetermina=i+1;
         break;
      }
// string s="          "; si es asi no anda bien esta funciuon
   }

   for(int i=0;i!=Posiciondondetermina;i++)
   {
      nuevo+=s[i];
   }


   return nuevo;
}

string trim(string s)
{
   string nuevo= rtrim(s);
   nuevo=ltrim(nuevo);


   return nuevo;
}

string replicate(char c,int n)
{
   string nuevo="";
   for(int i=0;i<n;i++)
   {
      nuevo=nuevo+c;
   }

   return nuevo;
}

string spaces(int n)
{
   string nuevo;

   for(int i=1;i<=n;i++)
   {
      nuevo+=' ';
   }


   return nuevo;
}

string lpad(string s,int n,char c)
{

   string nuevo;
   if(n!=length(s))
   {
      int posicion;
      for(int i=0;i<n-length(s);i++)
      {
         nuevo+=c;
         posicion=i;
      }
      int j=0;
      for(int i=posicion;s[j]!='\0';i++)
      {
         nuevo+=s[j];
         j++;

      }

   }
   else if(n==length(s))
   {
      nuevo=s;
   }



   return nuevo;
}
// LA UNICA QUE NO FUNCIONA ES STRINGTODOUBLE
string rpad(string s,int n,char c)
{
   string nuevo;
   if(n!=length(s))
   {

      for(int i=0;s[i]!='\0';i++)
      {
         nuevo+=s[i];
      }

      for(int i=length(s);i<n;i++)
      {
         nuevo+=c;
      }


   }
   else
   {
      nuevo=s;
   }



   return nuevo;
}

string cpad(string s,int n,char c)
{
   string nuevo;
   string nuevo2;
   if(n!=length(s))
   {
      int valorNuevo=n-n/2.5;
      nuevo+=lpad(s,valorNuevo,c);

      nuevo2+=rpad(nuevo,n,c);





   }

   else
   {
      nuevo2=s;
   }


   return nuevo2;
}

bool isDigit(char c)
{
   bool pregunta=false;
   int nuevo=charToInt(c);


   if(nuevo>=0 && nuevo<=9)
   {
      pregunta=true;
   }


   return pregunta;
}

bool isLetter(char c)
{
    bool pregunta=false;
    if(c>='A' && c<='Z')
    {
       pregunta=true;

    }
    else if(c>='a' && c<='z')
    {
       pregunta=true;
    }


   return pregunta;
}

bool isUpperCase(char c)
{
   bool pregunta=false;
   if(c>='A' && c<='Z')
   {
         pregunta=true;

   }

   return pregunta;
}

bool isLowerCase(char c)
{
   bool pregunta=false;
   if(c>='a' && c<='z')
   {
      pregunta=true;
   }

return pregunta;
}

char toUpperCase(char c)
{

   if(c>='a' && c<='z')
   {
        int nuevo=charToInt(c);
        c=intToChar(nuevo);
   }



   return c;
}

char toLowerCase(char c)
{

   if(c>='A' && c<='Z')
   {
      c=32+c;
   }

   return c;
}

string toUpperCase(string s)
{
   string nuevo;
   for(int i=0;s[i]!='\0';i++)
   {
      if(s[i]>='a' && s[i]<='z')
      {
         char c=s[i];
         nuevo+=toUpperCase(c);
      }
      else
      {
         nuevo+=s[i];
      }
   }

   return nuevo;
}

string toLowerCase(string s)
{
   string nuevo;
   for(int i=0;s[i]!='\0';i++)
   {
       if(s[i]>='A' && s[i]<='Z')
       {
          char c=s[i];
          nuevo+=toLowerCase(c);
       }
       else
       {
            nuevo+=s[i];
       }
   }
   return nuevo;
}

int cmpString(string a,string b)
{

   return a<b?-1:a>b?1:0;
}

int cmpDouble(double a,double b)
{
   int valor;
   if(a<b)
   {
      valor=-1;
   }
   else if(a>b)
   {
      valor=1;
   }
   else
   {
      valor=0;
   }


   return valor;
}

#endif

