#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

class Grafo
{
	int V;
	list<int> *adj;
	vector<int> comp;
	void preencher(int v, bool visitado[], stack<int> &Stack);
	void DFS(int v, bool visitado[]);

public:
	Grafo(int V);
	void adicionarAresta(int v, int w);
	void imprimirComponentes();
	Grafo transporGrafo();
	
};

Grafo::Grafo(int V)
{
	this->V=V;
	adj=new list<int>[V];
}

void Grafo::DFS(int v, bool visitado[])
{
	visitado[v]=true;

	//cout<< v << " ";
	comp.push_back(v);
	sort(comp.begin(),comp.end());

	list<int>::iterator i;
	for(i=adj[v].begin(); i!= adj[v].end(); ++i)
		if (!visitado[*i])
			DFS(*i, visitado);

	//sort(comp.begin(),comp.end());

	for (int i = 0; i < comp.size(); i++)
	{   
		int c = comp.front();
		cout<< c << " ";
		comp.erase(comp.begin());

	

}
}

Grafo Grafo::transporGrafo()
{
	Grafo g(V);
	for (int j=0;j<V; j++)
	{
		list<int>::iterator i;
		for (i = adj[j].begin(); i !=adj[j].end(); ++i)
		{
			g.adj[*i].push_back(j);
		}
	}

    return g;
}


void Grafo::adicionarAresta(int v, int w)
{
	adj[v].push_back(w);
}

void Grafo::preencher(int v, bool visitado[],stack<int> &Stack)
{
	visitado[v]= true;

	list<int>::iterator i;
	for (i = adj[v].begin(); i!=adj[v].end(); ++i)
		if(!visitado[*i])
			preencher(*i,visitado,Stack);
	

	Stack.push(v);
}

void Grafo::imprimirComponentes()
{
	stack<int> Stack;

	bool *visitado= new bool[V];
	for (int i = 0; i < V; i++)//marca todos os vertices como não visitados
		visitado[i]=false;


	for (int i = 0; i < V; i++)
		if (visitado[i]==false)
			preencher(i,visitado,Stack);
		

	Grafo gr = transporGrafo();


	for(int i=0; i <V; i++)
		visitado[i]=false;

	while(!Stack.empty())
	{
		int v = Stack.top();
		Stack.pop();

		if(visitado[v] == false)
		{
			gr.DFS(v,visitado);
			cout<< endl;
		}
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
	//cin>>inicio;
	g.imprimirComponentes();
	return 0;
}  
