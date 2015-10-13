// TP_Grapho.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Graph.h"

using namespace std;


int main()
{
	Graph grafo(8);
	Edge edge0(0, 2, 1),edge1(0,3,1), edge2(1, 5, 1), edge3(2, 5, 1), edge4(3, 5, 1), edge5(3, 7, 1), edge6(4, 6, 1), edge7(4, 7, 1);
	vector<int> vetor;
	grafo.insert(edge0);
	grafo.insert(edge1);
	grafo.insert(edge2);
	grafo.insert(edge3);
	grafo.insert(edge4);
	/*grafo.insert(edge5);
	grafo.insert(edge6);
	grafo.insert(edge7);
	grafo.print_matrix();
	*/cout << "BFS:  " << endl;
	vetor = grafo.BFS(0);
	for (int i = 0; i < vetor.size(); i++)
	{
		cout << vetor[i] << " ";
	}
	cout << endl;
	system("pause");

	return 0;
}

