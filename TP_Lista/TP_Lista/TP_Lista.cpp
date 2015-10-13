// TP_Lista.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include "Lista.h"
using namespace std;


int main()
{
	// Savio, dudu e negao
	Lista lista;
	lista.recebe("Teste.txt");
	lista.grava();
	lista.grava("Teste3.txt");
	lista.grava();
	system("pause");
    return 0;
}

