#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <limits.h>
#include <sys/time.h>
#include <cstdlib>
#include <ctime>

using namespace std;

void Merge(int v[], int aux[], int ini, int meio, int fim)
{
    int tam = (fim-ini)+1;
    //int *aux = new int[tam]; // vetor temporario onde os dados serão intercalados
    //int *aux =(int *) malloc(tam * sizeof (int));

    int cont=0, i=ini, j=meio+1;
    while(i<=meio && j<=fim)
    {
        if ( v[j] <= v[i] )
            aux[cont++] = v[j++];
        else
            aux[cont++] = v[i++];
    }
    // descarregar os elementos restantes!
    while( i<=meio )
        aux[cont++] = v[i++];
    while( j<=fim )
        aux[cont++] = v[j++];

    // copiar os valores do vetor aux para o vetor v...
    for(cont=0; cont<tam;cont++)
        v[ini+cont] = aux[cont];

    // apagar o vetor aux...
    //delete aux;
}


void MergeSort(int v[],int aux[], int ini, int fim)
{
    int meio = (ini+fim) / 2;

    if ( ini >= fim )    return; // condição de parada!!!

    MergeSort(v,aux,    ini, meio); // Ordenação da 1a Metade
    MergeSort(v,aux, meio+1,  fim); // Ordenação da 2a Metade

    // intercalação
    Merge(v,aux, ini, meio, fim);
}


void GeraVetor(int *v, int n)
{   
  for(int i=0;i<n;i++)
    v[i]=rand()%1000;


}


// Metodo que retorna o timestamp corrente em micro segundos (10e-6 s) 
long double getNow()
{
   struct timeval now;
   long double valor = 1000000;

   gettimeofday(&now,NULL);

   return ((long double)(now.tv_sec*valor)+(long double)(now.tv_usec));
}


int main(int argc, char const *argv[])
{  
    int n=100;    
    int *v=(int *) malloc(n * sizeof (int));
    int *aux =(int *) malloc(n * sizeof (int));
    GeraVetor(v,n);
    

    long double ti, tf;

    ti=getNow(); 
    MergeSort(v,aux,0,n);
    tf=getNow();
   


      //  for(int i=0;i<n;i++){
        //cout << v[i] << endl;
    //}

     //cout<<"Tempo: "<<(tf-ti)/1000000<<endl;
      printf("Tempo: %Lf\n",(tf-ti)/1000000);

    return 0;
}