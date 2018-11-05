#include <queue>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <cassert>
#include <list>

using namespace std; 


class Grafo
{
	int V;
    list<int> *adj;


public:
	 Grafo(int V);
	 void adicionarAresta(int v1, int v2); 
     int obterGrauDeSaida(int v);
     void bfs(int v);

	
};

Grafo::Grafo(int V){
    this->V=V;
    adj= new list<int>[V+1];
   

}

void Grafo::adicionarAresta(int v1, int v2)
{
    adj[v1].push_back(v2);
}

int Grafo:: obterGrauDeSaida(int v){
    return adj[v].size();
}

void Grafo::bfs(int v){

    queue<int> fila;
    bool visitados[V];
    int distancia[V];
    for (int i = 0; i < V; ++i)
    {
        distancia[i]= -1;
        visitados[i]= false;
    }

    //distancia[v]=0;
    //cout<< v << " \n";
    visitados[v]=true;
    distancia[v]=0;

    while(true){

        list<int>::iterator it;
        for (it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if(!visitados[*it])
            {   

                //cout << *it << " \n"; 
                visitados[*it]=true;//marca como visitado
                fila.push(*it);//insere na fila
                distancia[*it]=distancia[v]+1;
            }
        }


		if (!fila.empty())//verifica se a fila não esta vazia
		{

		    v= fila.front();//obtem o primero da fila
		    fila.pop(); // remove da fila
		   
		}

		else
		    break;

    }
    
		for(int i=0;i<V;i++)
		{
			cout<<i<<" "<<distancia[i]<<endl;
		}
	
}


int main(int argc,  char const *argv[]) // grafo e vertice inicial
{   
	int n,m,v,w,inicio;
	cin>>n>>m;
	Grafo g(n);
	for(int i=0;i<m;i++)
	{
		cin>>v>>w;
		g.adicionarAresta(v,w);
	}
	cin>>inicio;
	g.bfs(inicio);
	return 0;
}  
