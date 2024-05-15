#ifndef _TFILES_T_
#define _TFILES_T_

#include <iostream>
#include <stdio.h>

template<typename T> void write(FILE* f, T t)
{
   fseek(f,0,SEEK_CUR);

   fwrite(&t,sizeof(t),1,f);
   // Se debe anteponer esta linea al inicio de la funcion.
   // De otro modo, apareceran errores al momento de actualizar
   // archivos. Esto se debe a un error en la implementacion de Windows.
   //

}

template<typename T> T read(FILE* f)
{
   fseek(f,0,SEEK_CUR);

   T t;
   fread(&t,sizeof(t),1,f);


   return t;
}

template<typename T> void seek(FILE* f, int n)
{
   fseek(f,n,SEEK_SET);


}

template<typename T> int fileSize(FILE* f)
{
   int i=0;
   T t;
   fread(&t,sizeof(t),1,f);
   while(!feof(f))
   {
      i++;
      fread(&t,sizeof(t),1,f);

   }




   return i;
}

template<typename T> int filePos(FILE* f)
{

   int n=ftell(f);


   return  n;
}

#endif

