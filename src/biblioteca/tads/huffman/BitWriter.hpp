#ifndef _TARR_BITWRITER_
#define _TARR_BITWRITER_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../../funciones/strings.hpp"
#include "../../funciones/files.hpp"
#include <math.h>
using namespace std;

struct BitWriter
{
   FILE* c1;
   string s;
   string s2;

};

BitWriter bitWriter(FILE* f)
{
   BitWriter bw;
   bw.c1=f;
   bw.s="";
   bw.s2="";
   return {bw};
}

void bitWriterWrite(BitWriter& bw,int bit)
{
   char x=intToChar(bit);
   bw.s+=x;
   int numero=0;
   if(length(bw.s)==8)
   {

      for(int i=0;i<8;i++)
      {
         if(bw.s[i]=='1')
         {
            int valor=pow(2,7-i);
            numero=valor+numero;
         }
      }
      char nuevo=numero;
      write<char>(bw.c1,nuevo);

      bw.s="";
   }

}

void bitWriterWrite(BitWriter& bw,string sbit)
{
   bw.s2=sbit;
   int numero=0;
   if(length(bw.s2)==8)
   {

      for(int i=0;i<8;i++)
      {
         if(bw.s2[i]=='1')
         {
            int valor=pow(2,7-i);
            numero=valor+numero;
         }
      }
      char nuevo=numero;
      write<char>(bw.c1,nuevo);


      }

}


void bitWriterFlush(BitWriter& bw)
{

   if(length(bw.s)<8 && length(bw.s)!=0)
   {
    bw.s=rpad(bw.s,8,'0');
    bitWriterWrite(bw,bw.s);
   }


}

#endif
