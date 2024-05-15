#ifndef _TARR_BITREADER_
#define _TARR_BITREADER_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../../funciones/strings.hpp"
#include "../../funciones/files.hpp"

using namespace std;

struct BitReader
{
   FILE* br;
   int contador;
   int nuevoC;
   char c;
};

BitReader bitReader(FILE* f)
{

   BitReader br;
   br.br=f;
   br.contador=0;
   br.nuevoC=0;
   br.c=' ';
   return {br};
}

string _binToString( char c)
{
    int nuevo=c;
    string impreso;
    int resultado;
    while(nuevo!=1)
    {

    resultado=nuevo%2;
    impreso+=intToChar(resultado);
    nuevo=nuevo/2;
    }
    impreso+='1';
    if(length(impreso)!=8)
    {
       impreso=rpad(impreso,8,'0');
    }
   return impreso;
}

int _bitTamanioLongitud(FILE* f)
{
   char s = read<char>(f);
   int longitud=0;
   while( !feof(f) )
   {

    longitud++;
    s = read<char>(f);
   }

   return longitud;
}

//va a leerlo desde atras hasta adelante xd
int bitReaderRead(BitReader& br)
{
   //vamos almacenando los bits usados para poder ver  si es igual a 8
   // si br.nuevo==8 entonces leemos un byte nuevo,ya que el byte anterior ya se leyo
   //pero como nos pide bit a bit ,tenemos que leer bit a bit ,no podemos pasar directa-
   //mente a leer el otro byte , por eso hay que poner una restriccion.
   //si se cumple entonces br.nuevoC=0 ya que reiniciamos la lectura para leer otro bit
  // pero hay que hacer esto hasta que no tenga registros
   int resultado=-1;

      if (br.nuevoC == 0) {
          br.c = read<char>(br.br);
          br.nuevoC = 8;
      }

      br.nuevoC--;
      resultado = (br.c >> br.nuevoC) & 1;


      //hay que hacer algo para que la maskara decifre los 1 y 0 que hay en el char
      // por ejemplo tengo el valor -> 01001000 quiero primero el primero cero seria algo
      //asi 00000001 ,despues 000000010


   return resultado;

}



#endif
