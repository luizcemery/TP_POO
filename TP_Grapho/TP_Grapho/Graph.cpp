#include "stdafx.h"
#include "Graph.h"
using namespace std;


Graph::Graph(int V)
{
	vertices = V;
	matrix.resize(V);
	arestas = 0;
	for (int i = 0; i < V; i++) {
		matrix[i].resize(V);
	}
}

/*Insere uma aresta caso ela ainda não esteja no grafo.*/
bool Graph::insert(Edge edge)
{
	if (matrix[edge.node1][edge.node2] == 0)//Edge is not in the matrix.
	{
		matrix[edge.node2][edge.node1] = edge.weight;
		matrix[edge.node1][edge.node2] = edge.weight;
		arestas++;
		return true;
	}
	else//Edge is in the matrix.
	{
		return false;
	}
}

/*Imprime matriz que representa o grafo.*/
void Graph::print_matrix()
{
	for (int i = 0; i < vertices; i++)
	{
		for (int j = 0; j < vertices; j++) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

/*Remove uma aresta do grafo caso ela esteja no grafo.*/
bool Graph::remove(Edge edge)
{
	if (matrix[edge.node1][edge.node2] == 0) //Edge is not in the matrix
	{
		cout << "NOT REMOVE" << endl;
		return false;
	}
	else
	{
		matrix[edge.node1][edge.node2] = 0;
		matrix[edge.node2][edge.node1] = 0;
		arestas--;
		cout << "REMOVE" << endl;
		return true;
	}
}

/*Checa se uma determinada aresta se encontra no grafo.*/
bool Graph::_edge(Edge edge)
{
	if (matrix[edge.node1][edge.node2] == edge.weight)//?????????
	{
		return true;
	}
	else return false;
}

/*Função booleana que retorna true se o grafo estiver completo.*/
bool Graph::is_complete()
{
	for (int i = 0; i < vertices; i++)
	{
		for (int j = i + 1; j < vertices; j++)
		{
			if (matrix[i][j] == 0) return false;
		}
	}
	return true;
}

/*Completa o grafo caso ele não esteja completo.*/
bool Graph::complete() // ????? Peso das novas arestas ??????
{
	for (int i = 0; i < vertices; i++)
	{
		for (int j = i + 1; j < vertices; j++)
		{
			if (matrix[i][j] == 0)
			{
				matrix[i][j] = 1;
				matrix[j][i] = 1;
				arestas++;
			}
		}
	}
	return true;
}

int Graph::cont_edge()
{
	return arestas;
}

int Graph::N_Component()
{
	
	list<int> nodes;
	int aux,cont = 0;
	for (int i = 0; i < vertices; i++)
	{
		nodes.push_back(i);
	}
	while (!nodes.empty())
	{
		vector<int> visitados;
		aux = nodes.front();
		nodes.pop_front();
		visitados = DFS(aux);
		for (unsigned int i = 0; i < visitados.size(); i++)
		{
			nodes.remove(visitados[i]);
		}
		cont++;
	}
	return cont;
}

vector<int> Graph::Dijkstra(int begin, int end)
{
	vector<int> cost, visitados, pai, path;
	queue<int> fila;
	int aux;
	if ((end >= vertices)||(end < 0))
	{
		cout << "Destino nao existe." << endl;
		path.push_back(-1);
		return path;
	}
	else if ((begin >= vertices) || (begin < 0))
	{
		cout << "Origem nao existe." << endl;
		path.push_back(-1);
		return path;
	}
	cost.resize(vertices);
	visitados.resize(vertices);
	pai.resize(vertices);

	for (int i = 0; i < vertices; i++)
	{
		cost[i] = 10000;
	}

	cost[begin] = 0;

	fila.push(begin);
	while (!fila.empty())
	{
		aux = fila.front();
		fila.pop();
		if (visitados[aux] == 0)
		{
			visitados[aux] = 1;
		}
		for (int i = 0; i < vertices; i++)
		{
			if (matrix[aux][i] != 0)
			{
				if ((matrix[aux][i] + cost[aux]) < cost[i])
				{
					cost[i] = matrix[aux][i] + cost[aux];
					pai[i] = aux;
				}
				if (visitados[i] == 0)
				{
					fila.push(i);
				}
			}
		}
	}
	aux = end;
	while (aux != begin)
	{
		path.insert(path.begin(), aux);
		aux = pai[aux];
	}
	path.insert(path.begin(), begin);
	return path;
}

/*Busca em largura no grafo.*/
vector<int> Graph::BFS(int vertice)
{
	queue<int> fila;
	vector<int> visitados,path;
	int aux;
	visitados.resize(vertices);
	fila.push(vertice);
	while (!fila.empty())
	{
		aux = fila.front();
		if (visitados[aux] == 0)
		{
			visitados[aux] = 1;
			path.push_back(aux);
		}
		fila.pop();
		for (int i = 0; i < vertices; i++)
		{
			if ((matrix[aux][i] != 0)&&(visitados[i] == 0))
			{
				fila.push(i);
			}
		}
	}
	return path;
}


/*Busca em profundidade do grafo.*/
vector<int> Graph::DFS(int vertice)
{
	stack<int> pilha;
	vector<int> visitados, path;
	int aux;
	visitados.resize(vertices);
	pilha.push(vertice);
	while (!pilha.empty())
	{
		aux = pilha.top();
		if (visitados[aux] == 0)
		{
			visitados[aux] = 1;
			path.push_back(aux);
		}
		pilha.pop();
		for (int i = vertices - 1; i >= 0; i--)
		{
			if ((matrix[aux][i] != 0) && (visitados[i] == 0))
			{
				pilha.push(i);
			}

		}
	}
	return path;
}

Graph::~Graph()
{
}
