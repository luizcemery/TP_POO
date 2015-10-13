#pragma once
#include <vector>
#include <iostream>
#include <stdio.h>
#include <string>
#include "Dado.h"	
#include <fstream>


class Lista
{
	Dado *cabeca,*ultimo;

public:
	Lista();
	~Lista();

	bool inserir(int item);
	bool verifica(int item);
	bool retirar(int item);
	void grava(char *arq);
	void grava();
	void recebe(char *arq);
	void recebe();


};

