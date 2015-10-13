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

bool Graph::_edge(Edge edge)
{
	if (matrix[edge.node1][edge.node2] == edge.weight)//?????????
	{
		return true;
	}
	else return false;
}

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
