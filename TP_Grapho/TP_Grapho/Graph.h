#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include "Edge.h"


///<summary>
///Classe que armazena os m�todos e caracter�sticas dos grafos.
///</summary>
class Graph
{
	int vertices;
	int arestas;
	std::vector<std::vector<int> > matrix;

public:

	///<summary>
	///M�todo que insere uma aresta no grafo caso ela n�o exista.
	///Retorna true caso a aresta tenha sido inserida.
	///</summary>
	bool insert(Edge edge);

	///<summary>
	///M�todo que remove uma aresta do grafo caso ela exista.
	///Retorna true caso a aresta tenha sido removida.
	///</summary>
	bool remove(Edge edge);

	///<summary>
	///M�todo que verifica se uma aresta se encontra no grafo.
	///</summary>
	bool _edge(Edge edge);

	///<summary>
	///M�todo que verifica se o grafo � completo.
	///</summary>
	bool is_complete();

	///<summary>
	///M�todo que completa o grafo caso ele n�o seja completo.
	///</summary>
	bool complete();
	
	///<summary>
	///M�todo que faz a busca em largura.
	///Retorna o vetor com o caminho percorrido.
	///</summary>
	std::vector<int> BFS(int vertice);

	///<summary>
	///M�todo que faz a busca em profundidade.
	///Retornar o vetor com o caminho percorrido.
	///</summary>
	std::vector<int> DFS(int vertice);

	///<summary>
	///M�todo que busca o caminho m�nimo entre dois v�rtices.
	///Retorna o vetor com o caminho que deve ser percorrido.
	///</summary>
	std::vector<int> Dijkstra(int begin, int end);

	///<summary>
	///M�todo que retorna quantos componentes tem um grafo.
	///</summary>
	int N_Component();

	///<summary>
	///M�todo que retorna o n�mero de arestas presentes no grafo.
	///</summary>
	int cont_edge();

	///<summary>
	///M�todo que imprime a matriz correspondente ao grafo.
	///</summary>
	void print_matrix();
	
	Graph(int V);
	~Graph();
};

