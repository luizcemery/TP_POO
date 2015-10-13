#include "stdafx.h"
#include "Graph.h"
using namespace std;


Graph::Graph(int V)
{
	vertices = V;
	matrix.resize(V);
	for (int i = 0; i < V; i++) {
		matrix[i].resize(V);
	}
}


Graph::~Graph()
{
}
