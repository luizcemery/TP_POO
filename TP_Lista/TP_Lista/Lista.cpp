#include "stdafx.h"
#include "Lista.h"
using namespace std;

Lista::Lista()
{
	cabeca = new Dado();
	cabeca->item = NULL;
	ultimo = cabeca;
}

bool Lista::inserir(int item)
{
	Dado *aux = cabeca;
	Dado *novo = new Dado();
	 
	while (aux->prox != NULL) {
		if (item < aux->prox->item) {//Proximo na lista é maior que ele, insere no meio da lista.
			novo->item = item;
			novo->prox = aux->prox;
			aux->prox = novo;
			return true;
		}
		else if (item > aux->prox->item) {
			aux = aux->prox;
		}
		else { //Próximo na lista é igual, item já existe, não adiciona à lista.
			cout << "Numero ja se encontra na lista" << endl;
			return false;
		}
	}
	novo->item = item;
	novo->prox = NULL;
	aux->prox = novo;
	ultimo = novo;
	return true;
}

void Lista::grava()//Imprime na tela.
{
	Dado *aux = cabeca;
	if (aux->prox == NULL)
	{
		cout << "Lista Vazia." << endl;
	}
	else {
		while (aux->prox != NULL)
		{
			cout << aux->prox->item << " ";
			aux = aux->prox;
		}
		cout << endl << "FIM" << endl;
	}

}

void Lista::grava(char *arq)
{
	ofstream myfile;
	Dado *aux = cabeca;
	myfile.open(arq);
	while (aux->prox != NULL) {
		myfile << aux->prox->item << " ";
		aux = aux->prox;
	}
	myfile << "." << endl;

}

bool Lista::verifica(int item)
{
	Dado *aux = cabeca;
	while (aux->prox != NULL) {
		if (item < aux->prox->item) {
			cout << "Item nao esta na lista" << endl;
			return false;
		}
		else if (item > aux->prox->item){//Item não está na lista.
			aux = aux->prox;
		}
		else {
			cout << "Item esta na lista" << endl;
			return true;
		}
	}
}

bool Lista::retirar(int item)
{
	Dado *aux = cabeca,*aux2;
	while (aux->prox != NULL)
	{
		if (item < aux->prox->item) {
			cout << "Item nao esta na lista" << endl;
			return false;
		}
		else if (item > aux->prox->item) {
			aux = aux->prox;
		}
		else {
			aux2 = aux->prox;
			aux->prox = aux2->prox;
			free(aux2);
			cout << "Item removido com sucesso" << endl;
			return true;
		}
	}
}

void Lista::recebe()
{
	int item;
	cout << "Insira o numero que deseja adicionar a lista" << endl;
	cin >> item;
	if (inserir(item)) {
		cout << "Item inserido com sucesso" << endl;
	}
	else {
		cout << "Item ja existe na lista" << endl;
	}
}

void Lista::recebe(char *arq)
{
	ifstream myfile;
	int aux;
	myfile.open(arq);
	if (!myfile.is_open()) {
		cout << "Arquivo nao existe" << endl;
		return;
	}
	while (!myfile.eof()) {
		myfile >> aux;
		inserir(aux);
	}
}
Lista::~Lista()
{
	while (cabeca)
	{
		Dado *aux = cabeca;
		cabeca = cabeca->prox;
		free(aux);
	}
}
