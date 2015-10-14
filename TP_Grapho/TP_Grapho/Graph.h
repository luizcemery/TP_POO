#pragma once
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include "Edge.h"


///<summary>
///Classe que armazena os métodos e características dos grafos.
///</summary>
class Graph
{
	int vertices;
	int arestas;
	std::vector<std::vector<int> > matrix;

public:

	///<summary>
	///Método que insere uma aresta no grafo caso ela não exista.
	///Retorna true caso a aresta tenha sido inserida.
	///</summary>
	bool insert(Edge edge);

	///<summary>
	///Método que remove uma aresta do grafo caso ela exista.
	///Retorna true caso a aresta tenha sido removida.
	///</summary>
	bool remove(Edge edge);

	///<summary>
	///Método que verifica se uma aresta se encontra no grafo.
	///</summary>
	bool _edge(Edge edge);

	///<summary>
	///Método que verifica se o grafo é completo.
	///</summary>
	bool is_complete();

	///<summary>
	///Método que completa o grafo caso ele não seja completo.
	///</summary>
	bool complete();
	
	///<summary>
	///Método que faz a busca em largura.
	///Retorna o vetor com o caminho percorrido.
	///</summary>
	std::vector<int> BFS(int vertice);

	///<summary>
	///Método que faz a busca em profundidade.
	///Retornar o vetor com o caminho percorrido.
	///</summary>
	std::vector<int> DFS(int vertice);

	///<summary>
	///Método que busca o caminho mínimo entre dois vértices.
	///Retorna o vetor com o caminho que deve ser percorrido.
	///</summary>
	std::vector<int> Dijkstra(int begin, int end);

	///<summary>
	///Método que retorna quantos componentes tem um grafo.
	///</summary>
	int N_Component();

	///<summary>
	///Método que retorna o número de arestas presentes no grafo.
	///</summary>
	int cont_edge();

	///<summary>
	///Método que imprime a matriz correspondente ao grafo.
	///</summary>
	void print_matrix();
	
	Graph(int V);
	~Graph();
};

