// TP_Grapho.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"

using namespace std;


int main()
{
	Graph grafo(8);
	Edge edge0(0, 1, 2),edge1(0,3,5), edge2(0, 4, 3), edge3(1, 2, 8), edge4(2, 4,6), edge5(2, 5, 6), edge6(2, 6, 2), edge7(5, 6, 5), edge8(5,7,3),edge9(6,7,5);
	vector<int> vetor;
	grafo.insert(edge0);
	grafo.insert(edge1);
	grafo.insert(edge2);
	grafo.insert(edge3);
	grafo.insert(edge4);
	grafo.insert(edge5);
	grafo.insert(edge6);
	grafo.insert(edge7);
	grafo.insert(edge8);
	grafo.insert(edge9);
	grafo.print_matrix();
	cout << "BFS:  " << endl;
	vetor = grafo.BFS(0);
	for (unsigned int i = 0; i < vetor.size(); i++)
	{
		cout << vetor[i] << " ";
	}
	cout << endl;
	cout << "DFS:   " << endl;
	vector<int> vetor3 = grafo.DFS(0);
	for (unsigned int i = 0; i < vetor3.size(); i++)
	{
		cout << vetor3[i] << " ";
	}
	cout << endl << "Numero de componentes:" << endl;
	cout << grafo.N_Component() << endl;
	cout << "Dijkstra:  " << endl;
	vector<int> vetor2 = grafo.Dijkstra(7,3);
	for (unsigned int i = 0; i < vetor2.size(); i++)
	{
		cout << vetor2[i] << " ";
	}
	cout << endl;
	system("pause");

	return 0;
}

