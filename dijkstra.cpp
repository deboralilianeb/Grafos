#include <iostream>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo
{
private:
	int V; // número de vértices
	list<pair<int, int> > * adj;

public:

	Grafo(int V)
	{
		this->V = V; // atribui o número de vértices
		adj = new list<pair<int, int> >[V];
	}

	void adicionarAresta(int v1, int v2, int custo)
	{
		adj[v1].push_back(make_pair(v2, custo));
	}

	// algoritmo de Dijkstra
	int dijkstra(int orig, int dest)
	{
		// vetor de distâncias
		int dist[V];
		int visitados[V];

		// fila de prioridades de pair (distancia, vértice)
		priority_queue < pair<int, int>,
					   vector<pair<int, int> >, greater<pair<int, int> > > pq;

		for(int i = 0; i < V; i++)
		{
			dist[i] = INFINITO;
			visitados[i] = false;
		}

		dist[orig] = 0;

		pq.push(make_pair(dist[orig], orig));

		while(!pq.empty())
		{
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obtém o vértice do pair
			pq.pop(); // remove da fila

			if(visitados[u] == false)
			{
				visitados[u] = true;

				list<pair<int, int> >::iterator it;

				for(it = adj[u].begin(); it != adj[u].end(); it++)
				{
					int v = it->first;
					int custo_aresta = it->second;

					if(dist[v] > (dist[u] + custo_aresta))
					{
						dist[v] = dist[u] + custo_aresta;
						pq.push(make_pair(dist[v], v));
					}
				}
			}
		}

		return dist[dest];
	}
};

int main(int argc, char *argv[])
{   
	int n,m,v1,v2,custo,origem,destino;

	cin>>n>>m;
	Grafo g(n);

	for(int i=0;i<m;i++)
	{
		cin>>v1>>v2>>custo;
		g.adicionarAresta(v1,v2,custo);
	}

	cin>>origem>>destino;

	cout << g.dijkstra(origem, destino) << endl;

	return 0;
}