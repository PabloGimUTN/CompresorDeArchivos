
#ifndef _MAIN
#define _MAIN

#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/lists.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/parte2/Array.hpp"
#include "biblioteca/tads/parte2/Map.hpp"
#include "biblioteca/tads/parte2/List.hpp"
#include "biblioteca/tads/parte2/Stack.hpp"
#include "biblioteca/tads/parte2/Queue.hpp"
#include "biblioteca/tads/parte1/Coll.hpp"
#include "biblioteca/tads/parte1/MultidimColl.hpp"
#include "biblioteca/tads/huffman/BitReader.hpp"
#include "biblioteca/tads/huffman/BitWriter.hpp"
#include "principal.hpp"
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include "biblioteca/tads/huffman/HuffmanSetup.hpp"

using namespace std;

void valoresPorDefecto(HuffmanTable tabla[256])
{
   for(int i = 0 ; i<256;i++)
   {
      tabla[i].n=0;
      tabla[i].cod="";
   }


}

void contarOcurrencias(string fName,HuffmanTable tabla[256])
{
   char nombreArchivo[100];
   strcpy(nombreArchivo,fName.c_str());

   //recorro las 256 posiciones y le asigno los valores por defecto
   //si no a futuro me va  a afectar en las demas funciones

   valoresPorDefecto(tabla);


   //recorro archivo
   FILE* f= fopen(nombreArchivo,"r+b");

   unsigned char valor=read<unsigned char>(f);

   while(!feof(f))
   {
      int i=valor;
      tabla[i].n++;
      valor=read<unsigned char>(f);

   }



   fclose(f);


}

int cmpHuff(HuffmanTable a, HuffmanTable b)
{
   //lo que hace es comparar la cantidad de veces que aparecio ese caracter con el otro
   //si el primero aparecio mas veces,entonces devuelve positivo,si no negativo
   return b.n - a.n;
}
int cmpHuffTree ( HuffmanTreeInfo a, HuffmanTreeInfo b)
{
   return a.n - b.n;
}



void crearLista(List<HuffmanTreeInfo>& lista,HuffmanTable tabla[256])
{


   for(int i=0;i<256;i++)
   {
      if(tabla[i].n >= 1)
      {
         HuffmanTreeInfo* ht=new HuffmanTreeInfo();
         ht->c = i;
         ht->n = tabla[i].n;

         listAddFirst<HuffmanTreeInfo>(lista,*ht);
      }
   }
   listSort<HuffmanTreeInfo>(lista,cmpHuffTree);

}

int cmpInt( int a, int b){

   if(a-b >= 0 ){
      return 1;
   }
   else{
      return -1;
   }
}



HuffmanTreeInfo* crearArbol(List<HuffmanTreeInfo>& lista)
{
   HuffmanTreeInfo* raiz=new HuffmanTreeInfo();


   while( !listIsEmpty<HuffmanTreeInfo>(lista))
   {
      //aca recorro mi lista ,entonces cada lit
      if(listSize<HuffmanTreeInfo>(lista)>=2)
      {
         HuffmanTreeInfo* primerRemovido=new HuffmanTreeInfo();
         HuffmanTreeInfo* segundoRemovido= new HuffmanTreeInfo();

         *primerRemovido = listRemoveFirst<HuffmanTreeInfo>(lista);
         *segundoRemovido = listRemoveFirst<HuffmanTreeInfo>(lista);


         HuffmanTreeInfo* nuevo = new HuffmanTreeInfo();


         int numero = cmpInt(primerRemovido->n,segundoRemovido->n);
         //1 si el primerRemovido es mayor que el segundo
         //-1 si el segundoRemovido es mayor que el primero
         if(numero==1){
            nuevo->left=primerRemovido;
            nuevo->right=segundoRemovido;
            nuevo->n=primerRemovido->n+segundoRemovido->n;//nuevo.n la lista tiene valores
            nuevo->c=42; //los items asterisco tienen valores
         }
         else
         {
            nuevo->left = segundoRemovido;
            nuevo->right = primerRemovido;
            nuevo->n=primerRemovido->n+segundoRemovido->n;
            nuevo->c=42;
         }


      listOrderedInsert<HuffmanTreeInfo>(lista,*nuevo,cmpHuffTree);

      delete nuevo;

      }
      else
      {
       //entonces como la lista solo posee uno ,ese va a ser la raiz
         HuffmanTreeInfo ultimoremovido = listRemoveFirst<HuffmanTreeInfo>(lista);
         *raiz = ultimoremovido;
         break;
      }
   }

   return raiz;
}

void cargarCodigosEnTabla(HuffmanTreeInfo* raiz,HuffmanTable tabla[256])
{

   HuffmanTree ht=huffmanTree(raiz);
   string cod;

   while(huffmanTreeHasNext(ht))
   {

      HuffmanTreeInfo* x= huffmanTreeNext(ht,cod);
      //por cada espacio decaracteres accedo a mi tabla
      //y el string cod le asigno el cod del tad
      tabla[x->c].cod=cod;
   }

}

void escribirBit(BitWriter bw,string numeroABinario)
{
   for(int i=0;i<length(numeroABinario);i++)
   {
      char c=numeroABinario[i];
      bitWriterWrite(bw,charToInt(c));
   }
   bitWriterFlush(bw);


}

string intToBinario(int numeroDecimal)
{
   string binaryString="";

   for (int i = 7; i >= 0; --i)
   {
      // basicamente, esta operacion
      //construye una mascara con un 1 en la posicion que estamos verificando
      // y si coincide con el numero Decimal lo ponemos en nuestro numero binario
      if (numeroDecimal & (1 << i))
      binaryString += "1"; // Si esta activo, agregar '1' a la cadena
      else
      binaryString += "0"; // Si no esta activo, agregar '0' a la cadena
   }

   return binaryString;
}


void escribirHojas(BitWriter bw,HuffmanTable tabla[256])
{
   for(int i=0;i<256;i++)
   {
      if(tabla[i].n>=1)
      {
         //procedemos con agregar el caracter
         string binario=intToBinario(i); // caracter
         escribirBit(bw,binario);

         string binario2=intToBinario( length(tabla[i].cod) );//cantidad
         escribirBit(bw,binario2);

         //escribo los bits codificados
         string codificado = tabla[i].cod;//101 POR EJMEPLO
         for(int i=0;i<length(codificado);i++)
         {
            char c=codificado[i];
            int s=c;
            string binario = intToBinario(s);//paso por ejemplo el 49 a '110001'
            escribirBit(bw,binario);
         }

      }

   }



}

string cambiarNombreArchivo(string fName){
    fName=insertAt(fName,length(fName),'.');
    fName=insertAt(fName,length(fName),'h');
    fName=insertAt(fName,length(fName),'u');
    fName=insertAt(fName,length(fName),'f');
    fName=insertAt(fName,length(fName),'f');


   return fName;
}



void grabarArchivoComprimido(string fName,HuffmanTable tabla[256])
{
   string nuevoNombre=cambiarNombreArchivo(fName);
   char nuevoArchivo[100];
   strcpy(nuevoArchivo,nuevoNombre.c_str());

   //archivo que viene como paramtero
   char viejoArchivo[100];
   strcpy(viejoArchivo,fName.c_str());

   FILE* nuevo=fopen(nuevoArchivo,"w+b");
   FILE* f=fopen(viejoArchivo,"r+b");

   //1 ---1 byte indicando cuantas hojas conforman el arbol(t),
   int contador=-1;
   BitWriter bw = bitWriter(nuevo);
   for(int i=0;i<256;i++)
   {

      if(tabla[i].n>=1)
      {
         contador++;
      }

   }
   //validacion porque si es 256 no me lo escribe bien
   if(contador==-1)
   {
      contador++;
   }

   //hacer funcion que pase de int a binario string
   string binario=intToBinario(contador);
   escribirBit(bw,binario);

   //lo de arriba entonces ya lo escribi ,y ya pude meter los bits necesarios
   //para indicar el valor del ascci del numero de veces que hay variedad de letras

   //AHORA escribo las hojas y sus caracteristicas
   escribirHojas(bw,tabla);



   // 3 --4 bytes(un valor entero sin signo) indicando la longitud
   //del archivo original(en bytes);
   unsigned int longitudArchivo=sizeof(char)*fileSize<char>(f);

   write<unsigned int>(nuevo,longitudArchivo);



   // 4 grabo los archivos y bits codificados
   //aca no entra ,porque hay que reiniciar el campo contador
   //del archivo , despues tambien hay que verificar que es lo que se
   //escribe anteriormente,ya que la n no se si represente ocn exactitud los campos
   seek<char>(f,0);
   unsigned char c=read<unsigned char>(f);
   while(!feof(f))
   {
      int s=c;
      string codString = tabla[s].cod;

      for(int i=0;i<length(codString);i++)
      {
         char n = codString[i];
         int valorElemento=charToInt(n);
         bitWriterWrite(bw,valorElemento);
      }

      c=read<unsigned char>(f);
   }
   bitWriterFlush(bw);
   fclose(f);
   fclose(nuevo);

}

void comprimir(string fName)
{
   //paso 1
   HuffmanTable tabla[256];
   contarOcurrencias(fName,tabla);

   //paso 2
   List<HuffmanTreeInfo> lista = list<HuffmanTreeInfo>();
   crearLista(lista,tabla);


   //paso 3
   HuffmanTreeInfo* raiz = crearArbol(lista);

   //Recorro el arbol para obtener los codigos y los cargo
   // en el array de contadores, en el campo code
   cargarCodigosEnTabla(raiz,tabla);

   //Grabo el archivo comprimido
   grabarArchivoComprimido(fName,tabla);



}

string fNameToOriginal(string fName)
{
   string retorno;
   //el fName viene con .huff

   for(int i=0;i<length(fName)-5;i++)
   {
      retorno+=fName[i];

   }

   return retorno;
}

void  creoArchivoOriginal(FILE* f,unsigned int cantidadBytesAO,string fNameVersion1,HuffmanTreeInfo* raiz)
{
   char archivoAnterior[100];
   strcpy(archivoAnterior,fNameVersion1.c_str());

   FILE* archivoOriginal= fopen(archivoAnterior,"w+b");

   unsigned int contadorSizeOf=0;

   BitReader br = bitReader(f);
   int bit = bitReaderRead(br);
   HuffmanTreeInfo* aux=raiz;

   //aca hago un while paseando por el arbol segun los bits que leo
   //mientras no encuentre a mi hoja , no paro de correr o es falso si
   // la cantidad de bytes de mi archivo original es = al contador que
   //suma los char que voy escribiendo

   while( !feof(f) && (contadorSizeOf != cantidadBytesAO) )
   {


      if(bit == 1)
      {
         aux=aux->right;
         //en mi funcion construir arbol , en cada hoja puse el caracter
         //y tambien un n=1 ,para utilizarlo justamente aca,como validacion
         if( aux->n==1)
         {
            //si llegamos a la hoja escribimso en el archivo original
            write<unsigned char>(archivoOriginal,aux->c);
            contadorSizeOf+=sizeof(unsigned char);//sumo la cantidad de bytes del char
            aux=raiz;
         }
      }
      else if(bit == 0)
      {
         aux=aux->left;
         if( aux->n==1)
         {
         //si llegamos a la hoja escribimos en el archivo original

         write<unsigned char>(archivoOriginal,aux->c);
         contadorSizeOf+=sizeof(unsigned char);//sumo la cantidad de bytes del char
         aux=raiz;
         }
      }


      bit = bitReaderRead(br);


   }


   fclose(archivoOriginal);
}


HuffmanTreeInfo* construirArbol(FILE* f)
{
   HuffmanTreeInfo* raiz = new HuffmanTreeInfo();
   //leo el primer numero que me indica cuantos registro tiene el arbol
    unsigned char c=read<unsigned char>(f);
    unsigned char n;
    unsigned char cod;
    int hojasEnElArbol=c;
    int s=0;
    int m=0;



    hojasEnElArbol++;


   for(int i=0;i<hojasEnElArbol;i++)
      {
      s++;
         c=read<unsigned char>(f);//caracter 8 bits
         n=read<unsigned char>(f);//cantidad n de string codificado
         HuffmanTreeInfo* aux = raiz;

         //recorro la cantidad de veces que sea n
         for(int i=1;i<=n;i++)
         {
            m++;
            unsigned char valorM=read<unsigned char>(f);
            if(valorM == '1')
            {
               //si no existe tal nodo,lo creamos
              if(aux->right == nullptr)
              {

                  HuffmanTreeInfo* elementoNuevo=new HuffmanTreeInfo();
                  elementoNuevo->c=0;
                  elementoNuevo->n=0;
                  elementoNuevo->left=nullptr;
                  elementoNuevo->right=nullptr;
                 aux->right =elementoNuevo;
              }

              //ponemnos a aux como igual a su derecha
              aux=aux->right;


            }
            else
            {
               if(aux->left == nullptr)
               {

                  HuffmanTreeInfo* elementoNuevo=new HuffmanTreeInfo();
                  elementoNuevo->c=0;
                  elementoNuevo->n=0;
                  elementoNuevo->left=nullptr;
                  elementoNuevo->right=nullptr;
                  aux->left = elementoNuevo;

               }
               aux=aux->left;
            }

         }
         //le asigno a aux el valor del caracter
         aux->c=c;
         aux->n=1;//este solo lo pongo para una validacion mas tarde.
      }


   return raiz;
}


void descomprimir(string fName)
{
   char viejoArchivo[100];
   strcpy(viejoArchivo,fName.c_str());

   FILE* f=fopen(viejoArchivo,"r+b");

   //construimos arbol

   HuffmanTreeInfo* raiz = construirArbol(f);




   //leemos la cantidad de byte sque habia en el archivo original ||
   unsigned int cantidadBytesAO=read<unsigned int>(f);

   //ahora leemos la informacion comprimida para restaurar el archivo
   string fNameVersion1=fNameToOriginal(fName);//aca consigo mi nombre de archivo normal

   creoArchivoOriginal(f,cantidadBytesAO,fNameVersion1,raiz);






   fclose(f);




}




int main(int argc, char** argv)
{
    //recibo el nombre de archivo
   string fName = argv[1];

   // si no termina con ".huf" comprimo
   if( !endsWith(fName,".huff"))
   {
      comprimir(fName);
   }
   else // descomprimo
   {
      descomprimir(fName);
   }

   return 0;
}

#endif
