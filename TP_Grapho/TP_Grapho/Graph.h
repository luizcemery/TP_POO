#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include "Edge.h"

class Graph
{
	int vertices;
	int arestas;
	std::vector<std::vector<int> > matrix;

public:

	bool insert(Edge edge);
	bool remove(Edge edge);
	bool _edge(Edge edge);
	bool is_complete();
	bool complete();
	
	std::vector<int> BFS(int vertice);
	std::vector<int> DFS(int vertice);


	std::vector<int> Dijkstra(int begin, int end);


	int N_Component();
	int cont_edge();

	void print_matrix();
	
	Graph(int V);
	~Graph();
};

