#pragma once
#include <iostream>
#include <vector>
#include "Edge.h"

class Graph
{
	int vertices;
	int arestas;
	std::vector<std::vector<int> > matrix;

public:

	bool insert(Edge aresta);
	bool remove(Edge aresta);
	bool edge(Edge aresta);
	bool is_complete();
	bool complete();
	
	void BFS(int vertice);
	void DFS(int vertice);


	std::vector<int> Dijkstra(int begin, int end);


	int N_Component();
	int cont_edge();

	
	
	Graph(int V);
	~Graph();
};

