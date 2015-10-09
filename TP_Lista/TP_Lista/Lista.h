#pragma once
#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>


class Lista
{
	
public:
	Lista();
	~Lista();

	bool inserir(int item);
	bool verifica(int item);
	bool retirar(int item);
	void grava(std::string arq);
	void grava();
	void recebe(std::string arq);
	void recebe();


};

